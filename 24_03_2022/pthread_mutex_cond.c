#include<stdio.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_cond_t cond1=PTHREAD_COND_INITIALIZER; //pthread_condition_broadcast to release all thread.
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
int done=1;
void* foo(void *arg){
    char *str=(char*)arg;
    printf("thread task called by =%s\n",str);
    pthread_mutex_lock(&lock);
    if(done==1){
        printf("Waiting on condition variable cond1\n");
        pthread_cond_wait(&cond1,&lock);
    }
    else{
        //lets signal condition variable cond1
        printf("Singnaling condition variable cond1\n");
        pthread_cond_signal(&cond1);
    }
    //release lock
    pthread_mutex_unlock(&lock);
    printf("returing thread\n");
    return NULL;
}
//driver code
int main(){
    pthread_t tid1,tid2;
    //create thread1
    pthread_create(&tid1,NULL,foo,"THDone");

    //sleep for 1 sec so that thread1
    //would get a chancxe to run first
    sleep(1);
    //lets wait     on condition variable cond1
    done=2;
    pthread_create(&tid2,NULL,foo,"THDtwo");
    pthread_join(tid2,NULL);
}
