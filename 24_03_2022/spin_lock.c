//#define_XOPEN_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<pthread.h>
#include<sys/types.h>
#include<bits/types.h>

static pthread_spinlock_t spinlock;
volatile int slock;


void *spinlockThread(void *i)
{
    int rc;
    int count=0;

    printf("\nEnterd thread %d, getting Spin lock\n",(int*)i);

    rc= pthread_spin_lock(&slock);

    printf("%d thread compelete\n",(int*)i);
return NULL;
}

int main()
{
     int rc=0;
     pthread_t thread,thread1;

     if(pthread_spin_init(&slock,PTHREAD_PROCESS_PRIVATE)!=0)
     perror("init");
     printf("Main,get spin lock");
     rc=pthread_spin_lock(&slock);

     printf("\nMain, create the spin lock thread");
     rc = pthread_create(&thread,NULL,spinlockThread,(int*)1);

     printf("\nMain,wait a bit holding the spin lock");
     sleep(5);

     printf("\nMain, Now unlock the spin lock");
     rc = pthread_spin_unlock(&slock);

     if(rc==0)
        printf("\nmain thread succesfully unlocked\n");
     else
        printf("\n Main Thread unsuccessfully unlocked\n");

printf("Main, wait for the thread to end\n");
rc= pthread_join(thread,NULL);

printf("Main Compelete\n");
return 0;
}