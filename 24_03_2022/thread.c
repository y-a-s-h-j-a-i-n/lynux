#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

pthread_t tid;
pthread_t tid2;

int a=0;
void* thread1(void *arg){
    char *s=(char *)arg;
    printf("\n%s\n",s);
    printf("newly created thread 1 is executing \n");
    a++;
    printf("%d\n",a);
    return NULL;
}
void* thread2(){
    printf("newly created thread 2 is executing \n");
    a++;
    printf("%d\n",a);
    return NULL;
}
int main(void){
    int ret = pthread_create(&tid, NULL, thread1, "hello world");
    int ret2 = pthread_create(&tid2, NULL, thread2, NULL);
    printf("%d\n",a);
    if(ret)
        printf("Thread1 is not created\n");
    else    
        printf("Thread1 is created\n");

    if(ret2)
        printf("Thread2 is not created\n");
    else    
        printf("Thread2 is created\n");

    printf("%d in main\n",a);
    //sleep(2);
    pthread_join(tid, NULL);
    pthread_join(tid2, NULL); 
    return 0;
}