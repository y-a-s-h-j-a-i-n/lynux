#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char buff_comm[5];
    strcpy(buff_comm,"ls -l");

    printf("system() library function uses fork() to create a child process\n");
    printf("child process executes excel() which loads and run new program provided by system() argument\n");
    printf("%d",system(buff_comm));
}