#include<stdio.h>
#include<stdlib.h>
void buggy(int *p)
{
    p[0]=10;
    free(p);
}
int main(){
    int *ptr;
    ptr=(int *)malloc(sizeof(int));
    buggy(ptr);
    free(ptr);
}