#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int pid,fd;
    char rbuf[1];
    fd=open("file3.txt", O_CREAT | O_RDWR, 0777);
    
    read(fd,rbuf,1);
    printf("read data is:%s\n",rbuf);
}