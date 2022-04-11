#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main(){
    printf("server listening");
    int code=mkfifo("cli_ser_fifo",0764);
    if(code==-1){
        perror("mkfifo returned an error -file may already exist");
    }
    int fd=open("cli_ser_fifo",O_RDONLY);
    if(fd==-1){
        perror("Cannot open FIFO for read");//return error message to standard array device.
        return 0;
    }
    printf("FIFO OPEN");
    char serverrcv[100];
    memset(serverrcv,0,100);
    int res;
    char Len;
    while(1){
        res=read(fd,&Len,1);
        if(res==0){
            break;
        }
        read(fd,serverrcv,Len);                                   //read string characters
        
        printf("Server received: %s\n",serverrcv);                       
    }
    printf("EOF Reached");

    close(fd);
    printf("FIFO Closed");
}