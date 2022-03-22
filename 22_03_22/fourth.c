#include<stdio.h>
#include<string.h>
struct A
{
    int roll;
    char gender,name[40]; //memory padding first time char required 4 byte enter unmenaing full value. same applied to structure called structure padding.
    float height;// structure padding :- add 1 or more empty byte between memory address to align data in memory.
}f;
int main(){
    struct A first;
    printf("\n size of struct A %3d\n",sizeof(first));
}