#include<stdio.h>
#include<string.h>
int main(){
char buf1[10];
char buf2[10];
int ret;
memcpy(buf1,"mad",5);
memcpy(buf2,"madam12345",5);
ret=memcmp(buf1,buf2,5);
if(ret>0)
printf("buf1 is greater");
else if(ret<0)
printf("buf1 is lesser");
else
printf("buf1 is equal");
printf("\n%d\n",strlen(buf2));
printf("\n%s\n",buf2);
printf("%d\n",ret);
}
