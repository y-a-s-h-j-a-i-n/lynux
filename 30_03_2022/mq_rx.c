#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msgbuf{
    long mtype;
    char data[512];
};

int main(int argc, char **argv){
    int id;
    struct msgbuf v;
    struct msqid_ds buf;
    if(argc!=2){
        printf("usage:./mq_rx type \n");
        printf("Example: mq_rx 5\n");
        return 0;
    }
    id=msgget(49,IPC_CREAT|0644);
    if(id<0){
        perror("msgget");
        return 0;
    }
    msgrcv(id,&v,sizeof(v),atoi(argv[1]),0);
    printf("data %s\n",v.data);
    // msgctl(id,IPC_RMID,&buf);
    printf("Here are the details of the queue\n");
    printf("no of msg\s in q %hi\n",buf.msg_qnum);
    printf("max no of bytes in %hi\n",buf.msg_qbytes);
    return 0;
}