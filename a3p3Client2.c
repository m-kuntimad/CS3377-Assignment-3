#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <time.h>

#define MAXLINE 4096

int main(int argc, char** argv)
{
    unsigned int SERV_PORT;
    int sockfd;
    struct sockaddr_in servaddr;
    char recvline[MAXLINE];
    char sqlCommand[] = "Hello from the Client!";
    
    // the process will end in 150s
    alarm(120);                                                               
    //Check for correct number of arguments

    if(argc != 3)
    {
        perror("Unable to track <ServerIP> or <Server Port>");
        exit(1);
    }

    SERV_PORT = atoi(argv[2]);
  
    //Create a socket for the client
    //if the socket fd < 0 than an error occured while creating the socket
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR: Failed to create socket");
        exit(2);
    }

    //Creation of the socket

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(SERV_PORT); //converts to big-endian order
    //Connection of the client to the socket

    if(connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr))<0)
    {
        perror("Cant conect to the server");
        exit(3);
    }

    perror("Pre-Start 1");
    int x = 0;
     while(send(sockfd,sqlCommand,strlen(sqlCommand), 0)&&x<10)
    {


      
         perror("Pre-Start 2.1");
         
        if(recv(sockfd,recvline,MAXLINE,0) == 0 )
        {
            perror("The server Has Ended");

            exit(4);
        }
        
        printf("\n%s\n", "time C2: ");
        
        printf("Timestamp: %d\n", (int)time(NULL));
        
        
        fputs(recvline,stdout);
        
        sleep(3);
        x++;
    }
    perror("over");
    exit(0);    
    
} 
 
