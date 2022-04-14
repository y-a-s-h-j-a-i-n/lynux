#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
main(){
    int listfd,connfd,retval;
    socklen_t clilen;
    struct sockaddr_in cliaddr,servaddr;
    int opt=1;

    listfd=socket(AF_INET,SOCK_STREAM,0);//tcp .... connection...../FIFO
    if(listfd<0){
        perror("socket:");
        exit(1);
    }
    //forcefully attaching socket to the port 8080
    // if(setsockopt(listfd,SOL_SOCKET,SO_REUSEADDR|SO_REUSEPORT,&opt,sizeof(opt)))
    // {
    //     perror("setsockopt");
    //     exit(EXIT_FAILURE);
    // }
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(8000);//TCP protocol HTTP----port
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");//htonl(INADDR_ANY)   (inet_addr() convert char -> to long)

    retval=bind(listfd,(struct sockaddr *) &servaddr,sizeof(servaddr));
    if(retval<0){
        perror("bind:");
        exit(2);
    }
    listen(listfd,5);  ///for 100 client fork is used.
    while(1){
        clilen=sizeof(cliaddr);
        connfd=accept(listfd,(struct sockaddr *) &cliaddr,&clilen);
        printf(" client connected \n");
    }
}