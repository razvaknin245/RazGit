#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8000
#define BUFFER 1024

int main()
{
    int server_fd = 0;
    int nsocket = 0;
    int filesize = 0;
    struct sockaddr_in addr;
    int addrlen = sizeof(addr);
    char buffer[BUFFER] = {0};
    char *hw = "Hello World!";
    char *file_contents;
    FILE *f;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(0 == server_fd)
    {
        perror("socket failed");
        exit(-1);
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;
    if(bind(server_fd, (struct sockaddr *)&addr, addrlen) < 0)
    {
        perror("bind failed");
        exit(-1);
    }
    if(listen(server_fd, 3) < 0)
    {
        perror("listen failed");
        exit(-1);
    }
    printf("server listen on port %d \n",PORT);
    while(1)
    {
        nsocket = accept(server_fd,(struct sockaddr *)&addr,(socklen_t *)&addrlen);
        if(nsocket < 0)
        {
            perror("accept failed");
            exit(-1);
        }

        printf("new client connected \n");

        read (nsocket, buffer , 1024);

        if(strstr(buffer,"GET / HTTP") != NULL)
        {
            send(nsocket,hw,strlen(hw),0);
        }
        else if(strstr(buffer,"GET /index.html HTTP") != NULL)
        {
            f = fopen("index.html" , "r");
            if(NULL == f)
            {
                send(nsocket, "HTTP/1.1 404 Not Found\r\n\r\n", 26, 0);
            }
            else
            {
                fseek(f , 0, SEEK_END);
                filesize = ftell(f);
                rewind(f);
                file_contents = malloc(filesize + 1);
                fread(file_contents, filesize, 1, f);
                fclose(f);
                file_contents[filesize] = '\0';
                send(nsocket, file_contents, filesize ,0 );
                free(file_contents);
            }
        }
        else
        {
            send(nsocket, "HTTP/1.1 404 Not Found\r\n\r\n", 26, 0);
        }
        close(nsocket);
        printf("disconnected \n");
    }
    return 0;
}

