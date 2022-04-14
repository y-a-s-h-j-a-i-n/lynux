#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>


#include <netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
/* following function will be handling the client in child process */
void handleClient(int connfd) {
int n;
char buf[200];
n = read(connfd,buf,200);
buf[n]='\0';
printf("data rec'd from client = %s\n", buf);
printf("requested handled by server %d\n",getpid());
write(connfd,"Good Bye",8);
exit(0); // terminate child.
}
main() {
int sockfd,retval,n;
char buf[10000];
socklen_t clilen;
struct sockaddr_in cliaddr, servaddr;
sockfd = socket(AF_INET, SOCK_DGRAM, 0);
if (sockfd <0) {
perror("sock:");
exit(1);}
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(8000);//tcp protocol http---port
retval=bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)); //it would bind the serveraddr to the listfd
if(retval <0){
perror("bind:");
exit(2);
}


printf("Socket bound to port 8000\n");
clilen=sizeof(struct sockaddr_in);
while(1){
printf("before recv from\n");
n=recvfrom(sockfd,buf,10000,0,(struct sockaddr *)&cliaddr,&clilen);
printf("recieved %d bytes\n",n);
buf[n]='\0';
printf("msg from client=%s\n",buf);


}
}