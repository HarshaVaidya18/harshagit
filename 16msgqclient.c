#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/msg.h>
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
	c.msg_type=MSG_TYPE;
	int msqid=msgget(KEY,0);
	c.pid=getpid();
	char rbuf[20];
	while(1)
	{
		printf("send a msg to server\t");
		scanf("%s",rbuf);
		strcpy(c.buf,rbuf);
		msgsnd(msqid,&c,sizeof(c),0);
		if(strcmp(rbuf,"bye")==0)
			exit(0);
		ret=msgrcv(msqid,&c,100,MSG_TYPE,0);
                printf("client :%s\n",c.buf);
		if(strcmp(c.buf,"bye")==0)
			exit(0);
	}
}

