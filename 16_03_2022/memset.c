#include<stdio.h>
#include<string.h>
int main(){
const char str[]="linux.com";
const char ch='#';
printf("string brfore %s\n",str);
memset(str,ch,strlen(str));
printf("string after %s\n",str);
}
