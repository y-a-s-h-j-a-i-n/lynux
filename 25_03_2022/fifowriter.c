#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
    char s[20];
    int fd;
    mkfifo("newfifo11",0644);
    perror("mkfifo");
    printf("before open()..\n");
    fd=open("newfifo11",O_WRONLY);
    printf("Enter data...\n");
    scanf("%s",s);
    write(fd,s,strlen(s)+1);
}