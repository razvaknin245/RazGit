#include <stdlib.h>
#include <fcntl.h>                 /* O_RDWR */
#include <linux/if.h>              /* ifr */
#include <linux/if_tun.h>          /* IFF_TUN */
#include <sys/ioctl.h>             /* ioctl(), TUNSETIFF */
#include <arpa/inet.h>             /* inet_addr */
#include <openssl/ssl.h> /* ssl */ /* sudo apt install openssl libssl-dev */
#include <unistd.h>                /* close, read */
#include <sys/select.h>		   /* select */
#include <string.h>		   /* strstr */
#include <strings.h>		   /* bzero */
#include <signal.h>		   /* SIGINT */

#define PORT 8002
#define MTU 1400

static int max(int a, int b)
{
    return a > b ? a : b;
}
int TunAlloc()
{
    
    struct ifreq ifr;
    int fd = 0;
    int e = 0;
    system("ip tuntap add mode tun tun0");

    if ((fd = open("/dev/net/tun", O_RDWR)) < 0)
    {
        perror("Cannot open /dev/net/tun");
        return fd;
    }
    
    memset(&ifr, 0, sizeof(ifr));

    ifr.ifr_flags = IFF_TUN | IFF_NO_PI;
    strncpy(ifr.ifr_name, "tun0", IFNAMSIZ);

    if ((e = ioctl(fd, TUNSETIFF, (void *)&ifr)) < 0)
    {
        printf("ioctl[TUNSETIFF]");
        close(fd);
        return e;
    }
    system("ip link set dev tun0 up");
    printf("alloc of tun worked \n");
    return fd;
}
void IfConfig()
{
    char cmd[1024];
    sprintf(cmd, "ifconfig tun0 10.8.0.1/16 mtu %d up", MTU);
    system(cmd);
    printf("bind ip success\n");
}
void SetupRouteTable()
{
    system("sysctl -w net.ipv4.ip_forward=1");
    system("iptables -t nat -A POSTROUTING -o ens160 -j MASQUERADE");
    printf("setup route table success\n");
}
void CleanupRouteTable()
{
    system("iptables -t nat -D POSTROUTING -s 10.8.0.0/16 ! -d 10.8.0.0/16 -m comment --comment 'vpndemo' -j MASQUERADE");
    system("iptables -D FORWARD -s 10.8.0.0/16 -m state --state RELATED,ESTABLISHED -j ACCEPT");
    system("iptables -D FORWARD -d 10.8.0.0/16 -j ACCEPT");
    system("iptables -t nat -D POSTROUTING -o ens160 -j MASQUERADE");
    printf("cleanup route table success\n");
}
void CloseConnect(int nic_fd, int sock_fd, int sock, SSL_CTX *ctx, SSL *ssl)
{
    close(nic_fd);
    close(sock_fd);
    close(sock);
    SSL_free(ssl);
    SSL_CTX_free(ctx); 
}

void CleanUp(int signo,int nic_fd, int sock_fd, int sock, SSL_CTX *ctx, SSL *ssl)
{

    if (signo == SIGHUP || signo == SIGINT || signo == SIGTERM)
    {
        CleanupRouteTable();
        CloseConnect(nic_fd, sock_fd, sock, ctx,ssl);
        exit(0);
    }
}

int TcpOpenSocTLS(SSL_CTX **ct, SSL **ssl)
{
    int sock = 0;
    int host_len = 0;
    struct sockaddr_in addr;
    *ct = SSL_CTX_new(TLS_server_method());
    SSL_CTX_use_certificate_file(*ct,"/home/ubuntu2/c/server.crt",SSL_FILETYPE_PEM);
    SSL_CTX_use_PrivateKey_file(*ct,"/home/ubuntu2/c/server.key",SSL_FILETYPE_PEM);
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sock)
    {
        return -1;
    
    }
    printf("sock created : %d \n",sock);
    
    host_len = sizeof(addr);
    
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(PORT);
    
    if (bind(sock, (struct sockaddr *)&addr, host_len) < 0)
    {
        return -1;
    }
    if (0 > listen(sock,1))
    {
        return -1;
    }
    printf("bind success\n");
    return sock;
}
int TcpTLSConnection(int tcpfd,SSL_CTX **ctx, SSL **ssl)
{

    int newsockfd = 0;
    socklen_t length;
    struct sockaddr_in addr;

    length = sizeof(addr);
    newsockfd = accept(tcpfd, (struct sockaddr *)&addr, (socklen_t *)&length);
    if (-1 == newsockfd)
    {
        return -1;
    }
    *ssl = SSL_new(*ctx);
    SSL_set_fd(*ssl, newsockfd);
    if(SSL_accept(*ssl) != 1 )
    {
        printf("SSL failed\n");
        return -1;
    }
    printf("connection sucessed");
    return newsockfd;
}

int main()
{
    int tun_fd = -1;
    int tcp_fd = -1;
    int max_fd = 0;
    int newsocfd = -1;
    int r = 0;
    char buf[MTU];
    fd_set readset;
    SSL_CTX *ct;
    SSL *ssl;
    if ((tun_fd = TunAlloc()) < 0)
    {
        return 1;
    }
    CleanupRouteTable();
    IfConfig();
    SetupRouteTable();
    tcp_fd = TcpOpenSocTLS(&ct,&ssl);
    if (tcp_fd < 0)
    {
        CleanupRouteTable();
        close(tun_fd);
        printf("Failed to create TCP server\n");
        return tcp_fd;
    }
    newsocfd = TcpTLSConnection(tcp_fd,&ct,&ssl);
    if (-1 == newsocfd)
    {
        CleanupRouteTable();
        close(tcp_fd);
        close(tun_fd);
        return -1;
    }
    
    while (1)
    {
        FD_ZERO(&readset);
        FD_SET(tun_fd, &readset);
        FD_SET(tcp_fd, &readset);
	
        max_fd = max(tun_fd, tcp_fd) + 1;
        if (-1 == select(max_fd + 1, &readset, NULL, NULL, NULL))
        {
            printf("error in select");
            break;
        }

        if (FD_ISSET(tun_fd, &readset))
        {
            r = read(tun_fd, buf, MTU);
            if (r < 0)
            {
                printf("recvfrom udp_fd error");
                break;
            }
            r = SSL_write(ssl,buf,r);
            if (r < 0)
            {
                printf("write tun_fd error");
                break;
            }
            bzero(buf,MTU);
        }
        if (FD_ISSET(newsocfd, &readset))
        {
            r = SSL_read(ssl, buf, MTU);
            if (r < 0)
            {
                printf("read from tun_Fd failed");
                break;
            }
            r = write(tun_fd, buf, r);
            if (r < 0)
            {
                printf("send to tcp_fd error");
                break;
            }
            bzero(buf,MTU);
        }
    }

    CleanupRouteTable();
    CloseConnect(tun_fd,tcp_fd,newsocfd,ct,ssl);
    return 0;
}
