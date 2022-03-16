#include<stdio.h>
#include<string.h>
int main(){
const char str[]="linux.com";
const char ch='.';
char *ret;
printf("string brfore %s\n",str);
memrcr(str,ch,strlen(str));
printf("string after %s\n",str);
//printf("addresss = %s",ret+1);
}
