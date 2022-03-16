#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
char *str1="linux";
char *str2="kernel";
char *name=(char *) alloca (strlen(str1)+strlen(str2));
//stpcpy(stpcpy(name,str1),str2);
strcpy(name,str1);
strcat(name,str2);
printf("the copied string data is %s\n",name);
}
