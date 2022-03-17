#include<stdio.h>
#include<string.h>
#include<unistd.h>
void my_man_copy(char *buf1,char *buf2,int size){
    for(int i=0;i<size;i++){
        *buf2=*buf1;
        buf2++;
        buf1++;
        
    }
}
int main(){
    char buf1[]="yashjain";
    char buf2[]="";
    my_man_copy(buf1,buf2,10);
    printf("string 2 is %s",buf2);
}
