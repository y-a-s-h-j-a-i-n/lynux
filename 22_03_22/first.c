#include<stdio.h>
#include<string.h>
struct student
{
    int roll;
    char name[40],gender;
    float height;
}first;
int main(){
    struct student second;
    struct student third={103,"Hari Prasad. D",'M',5.11};
    printf("\n Roll\t Name \t\t\t\t\t\t Gender\t Height\n");
    first.roll=101;
    strcpy(first.name,"Yash Jain");
    first.gender='M';
    first.height=5.6;
    printf("\n %3d\t%-40s\t%c\t%1.2f",first.roll,first.name,first.gender,first.height);
    printf("\n %3d\t%-40s\t%c\t%1.2f\n",third.roll,third.name,third.gender,third.height);
}