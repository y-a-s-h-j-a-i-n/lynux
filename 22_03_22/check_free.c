#include<stdio.h>
#include<stdlib.h>
void buggy(){
    int *intptr;
    int i;
    intptr=(int *)malloc(sizeof(int));
    // free(intptr);//segmentation fault
    *intptr=100;
    free(intptr);
    printf("%d",*intptr);
}
int main()
{
    buggy();
}