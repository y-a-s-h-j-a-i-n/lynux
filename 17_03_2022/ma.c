#include<stdio.h>
#include "cm.h"
int main(int argc,char *argv[])
{
double v1,v2,m1,m2;
v1=5.2;
v2=7.9;
m1=mul(v1,v2);
m2=div(v1,v2);
printf("the mean of %3.3f and %3.2f is %3.2f\n",v1,v2,m1);
printf("The substration of %3.3f and %3.2f is %3.2f\n",v1,v2,m2);
}
