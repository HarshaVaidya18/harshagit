#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/msg.h>
#include<stdlib.h>
#define MSG_TYPE 2
#define KEY 0x00012345
struct msg
{
        long int msg_type;
        long int pid;
        char buf[20];
};
void main()
{       
        struct msg c;
	int ret;
	char rbuf[50];
	int msqid=msgget(KEY,IPC_CREAT|0660);
	while(1)
	{
		ret=msgrcv(msqid,&c,100,MSG_TYPE,0);
		printf("PROCESS ID OF CLIENT %ld\n",c.pid);
		printf("client :%s\n",c.buf);
		 if(strcmp(c.buf,"bye")==0)
                        exit(0);
		printf("send a msg to client\t");
                scanf("%s",rbuf);
                strcpy(c.buf,rbuf);
                msgsnd(msqid,&c,sizeof(c),0);
		 if(strcmp(rbuf,"bye")==0)
                        exit(0);

	//	exit(0);
	}

}

