#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
    int p[2];
    pipe(p);
    printf("read end of pipe=%d \t write end of pipe =%d\n",p[0],p[1]);
    if(fork())
    {
        char s[20];
        printf("in parent enter data...\n");
        scanf("%s",s);
        write(p[1],s,strlen(s)+1);
    }
    else{
        char buf[20];
        printf("int childe ... \n");
        read(p[0],buf,sizeof(buf));
        printf("child pro printing .. data of the parent process .. %s\n",buf);
    }
    return 0;
}