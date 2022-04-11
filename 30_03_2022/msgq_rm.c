#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define KEY 8979

int main(){
    int qid;
    struct msqid_ds buf;
    qid=msgget(49,IPC_CREAT|0644);
    printf("qid=%d\n",qid);
    msgctl(qid,IPC_RMID,NULL);
}