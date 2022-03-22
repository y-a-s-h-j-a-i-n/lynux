#include<stdio.h>
#include<stdlib.h>
// extern int EF_PROTECT_BELOW;
void buggy(){
    int *intptr;
    int i;
    intptr=(int *)malloc(sizeof(int)*5);
    // free(intptr);//segmentation fault
    for(i=0;i<13;i++)  //segmentaation fault
    {
        *intptr=100;
        printf("value at ptr intptr =%d\n",(*intptr));
        intptr++;
    }
}
int main()
{
    buggy();
}