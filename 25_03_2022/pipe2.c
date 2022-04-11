#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

     int fds[2];
     int res,i;

void parent_code(){
     char *buf1="aaaaaaaaaaaaaaaaaaaaaa";
     char *buf="bbbbbbbbbbbbbbbbbbbbbb";
     char buf2[40];

     res = pipe(fds);

     if(res ==-1)
    {
          perror("pipe");
          exit(1);
      }

    write(fds[1],buf1,20);
    write(fds[1],buf,20);
    read(fds[0],buf2,40);
    printf("end of parent\n");
}
void child_code(){
    char buf[100];
     int n,i;
     close(fds[1]);
     n = read(fds[0],buf,100);
     printf("\nno of chars read = %d\n",n);

    for(i=0; i<n;i++)
       printf("%c",buf[i]);
     printf("end of child\n");
}

int main()
{
    pid_t p;
    res = pipe(fds);

   if(res ==-1){
     perror("pipe");
          exit(1);
      }
    p = fork();
    if(p==0){
        child_code();
    }
    else{
          parent_code();
     }
return 0;
}
