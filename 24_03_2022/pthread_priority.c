#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
void *my(void *i)
{
printf("\ni am in thread %d \n",(int *) i);
}
main()
{
pthread_t tid;
struct sched_param param;
int priority,policy,ret;
ret = pthread_getschedparam (pthread_self(), &policy, &param);
if(ret != 0)
perror("getschedparam");
printf("\n-----------------main thread---------\n policy %d \t priority %d\n",policy,param.sched_priority);
policy = SCHED_FIFO;
param.sched_priority =3;
ret = pthread_setschedparam (pthread_self(),policy,&param);
if(ret != 0)
perror("getschedparam");
ret = pthread_getschedparam (pthread_self(), &policy, &param);
if(ret != 0)
perror("getschedparam");
printf("\n-----------------main thread---------\n policy %d \t priority %d\n",policy,param.sched_priority);
}