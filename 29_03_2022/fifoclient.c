#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main(){
    printf("Client process writing\n");
    char clientmsg[]="Linux system kernel programming";
    int fd=open("cli_ser_fifo",O_WRONLY);
    if(fd==-1){
        perror("cannot open fifo");
        return EXIT_FAILURE;
    }
    write(fd,clientmsg,strlen(clientmsg));
    close(fd);
    return 0;
}