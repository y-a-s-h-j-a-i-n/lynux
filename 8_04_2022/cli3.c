#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>

main(){
    char buf[200];
    char *serv_ip="127.0.0.1";
    int sockfd,ret_val,n;
    struct sockaddr_in servaddr;
    sockfd=socket(AF_INET,SOCK_STREAM,0);

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(8000);//TCP port----HTTP
    inet_pton(AF_INET,serv_ip,&servaddr.sin_addr);

    ret_val=connect(sockfd,(struct sockaddr *) &servaddr,sizeof(servaddr));
    //printf("clinent esatabliesednd connection with servaer \n");

    if(ret_val<0){
        perror("connect:");
        exit(1);
    }
    printf("Enter the data that you want to send to the server\n");
    gets(buf);
    write(sockfd,buf,strlen(buf));
    n=read(sockfd,buf,200);
    buf[n]='\0';
    printf("rec'd %s from server \n",buf);
    close(sockfd);
}
