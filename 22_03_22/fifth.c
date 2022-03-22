#include<stdio.h>
#include<string.h>
struct A
{
    int roll;
    char gender,name[40] __attribute__((aligned(2)));//aligned is structure attribute t
    float height;
}__attribute__((packed));
int main(){
    struct A first;
    printf("\n size of struct A %3d\n",sizeof(first));
}