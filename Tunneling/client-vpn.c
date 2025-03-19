#include <stdlib.h>
#include <fcntl.h>                
#include <linux/if.h>              
#include <linux/if_tun.h>          
#include <sys/ioctl.h>            
#include <arpa/inet.h>             
#include <openssl/ssl.h> 
#include <unistd.h>                
#include <sys/select.h>		 
#include <string.h>		   
#include <strings.h>
#include <signal.h>


#define PORT 8002
#define MTU 1400
#define BIND_HOST "0.0.0.0"
#define SERVER_HOST "192.168.7.12"
#define BUFFER_SIZE 1024
static int Max(int a, int b)
{
    return a > b ? a : b;
}
int TunAlloc()
{
    struct ifreq ifr;
    int fd = 0;
    int e = 0;

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
        perror("ioctl[TUNSETIFF]");
        close(fd);
        return e;
    }
    printf("tun allocated \n");
    return fd;
}
int TcpTLS(SSL_CTX **ctx, SSL **ssl)
{
    int socketfd = 0;
    struct sockaddr_in addr;

    *ctx = SSL_CTX_new(TLS_client_method());
    SSL_CTX_use_certificate_file(*ctx, "/home/ubuntu/C/client.crt",SSL_FILETYPE_PEM);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(SERVER_HOST);
    addr.sin_port = htons(PORT);

    if((socketfd = socket(AF_INET,SOCK_STREAM, 0 )) < 0)
    {
        return -1;
    }

    *ssl = SSL_new(*ctx);
    SSL_set_fd(*ssl, socketfd);
    if(-1 == connect(socketfd,(struct sockaddr *)&addr,sizeof(addr)))
    {
        printf("connection failed \n");
        return -1;
    }
    if(0 > SSL_connect(*ssl))
    {
        printf("SSL connection failed \n");
        return -1;
    }
    printf("connection success \n");
    return socketfd;
}

void IfConfig()
{
    char cmd[1024];
    sprintf(cmd, "ifconfig tun0 10.8.0.2/16 mtu %d up", MTU);
    system(cmd);
    printf("setup ip 10.8.0.2 to tun0 \n");
}
void SetupRouteTable()
{
    char cmd[1024];
    system("sysctl -w net.ipv4.ip_forward=1");
    system("iptables -I FORWARD 1 -i tun0 -m state --state RELATED,ESTABLISHED -j ACCEPT");
    system("iptables -I FORWARD 1 -o tun0 -j ACCEPT");
    sprintf(cmd,"iptables -I FORWARD 1 ! -d %s -o tun0 -j ACCEPT", SERVER_HOST);
    system(cmd);
    system("ip route add 0/1 dev tun0");
    system("ip route add 128/1 dev tun0");
    
    printf("route table setup \n");
}
int ExitFunc()
{
    char buffer[20];
    fgets(buffer,20,stdin);
    return strcmp(buffer,"exit");
}
void CleanupRouteTable()
{
    char cmd[1024];

    system("iptables -D FORWARD -i tun0 -m state --state RELATED,ESTABLISHED -j ACCEPT");
    sprintf(cmd,"iptables -D FORWARD ! -d %s -o tun0 -j ACCEPT", SERVER_HOST);
    system(cmd);
    system("ip route del 0/1");
    system("ip route del 128/1");
    
    printf("route table cleaned \n");
}
void EndConnect(int nic_fd,int soc_fd,SSL_CTX *ctx, SSL *ssl)
{
    close(nic_fd);
    close(soc_fd);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    system("sudo ip link delete tun0");
}
void Cleanup(int signo,int nic_fd,int soc_fd,SSL_CTX *ctx, SSL *ssl)
{
    if (signo == SIGHUP || signo == SIGINT || signo == SIGTERM)
    {
        CleanupRouteTable();
        EndConnect(nic_fd,soc_fd,ctx, ssl);
        exit(0);
    }
}
int main()
{
    int tun_fd = 0;
    int tcp_fd = 0;
    int max_fd = 0;
    int r = 0;
    char buffer[BUFFER_SIZE];
    fd_set readset;
    SSL_CTX *ct;
    SSL *ssl;

    tun_fd = TunAlloc();

    if (-1 == tun_fd)
    {
        return -1;
    }
    IfConfig();
    SetupRouteTable();
    
    tcp_fd = TcpTLS(&ct,&ssl);
    if (-1 == tcp_fd)
    {
        CleanupRouteTable();
        close(tun_fd);
        system("sudo ip link delete tun0");
    }

    while (1)
    {
        FD_ZERO(&readset);
        FD_SET(tun_fd, &readset);
        FD_SET(tcp_fd, &readset);

        max_fd = Max(tun_fd, tcp_fd) + 1;

        if (-1 == select(max_fd, &readset, NULL, NULL, NULL))
        {
            printf("error in select");
            break;
        }

        if (FD_ISSET(tun_fd, &readset))
        {
            r = read(tun_fd, buffer, sizeof(buffer));
            if (r < 0)
            {
                printf("read from tun_Fd failed");
                break;
            }
            r = SSL_write(ssl,buffer,r);
            if (r < 0)
            {
                printf("unable to write");
                break;
            }
            bzero(buffer,sizeof(buffer));
        }
        if (FD_ISSET(tcp_fd, &readset))
        {
            r = SSL_read(ssl,buffer,sizeof(buffer));
            if (r < 0)
            {
                printf("recv from tcp_fd error \n");
                break;
            }
            r = write(tun_fd,buffer, r);
            if (r < 0)
            {
                printf("write tun_fd error \n");
                break;
            }
            bzero(buffer,sizeof(buffer));
        }
    }

    CleanupRouteTable();
    EndConnect(tun_fd,tcp_fd,ct,ssl);

    return 0;
}
