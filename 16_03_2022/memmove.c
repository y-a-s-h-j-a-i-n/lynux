#include<stdio.h>
#include<string.h>
int main(){
char buf1[10]="oldstring";
char buf2[10]="newstring";
printf("before dest=%s and soc =%s",buf1,buf2);
memmove(buf1,buf2,2);//gaurentry result(overlaping) , slow, relible;
printf("\nafter dest=%s and soc =%s\n",buf1,buf2);
}
