#include<stdio.h>
#include<string.h>
void myprint(char* msg)
{
if(msg!=NULL)
printf("msg: %s\n",msg);
}
int main()
{
char buff[]="linux";
myprint(NULL);
}
