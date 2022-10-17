#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/sem.h>
#include<sys/shm.h>
#define KEY 0x19920
int main()
{
	struct sembuf sop;
	char *addr;
	int shmid=shmget(KEY,1000,IPC_CREAT|0660);
	addr=shmat(shmid,NULL,0);
	int semid=semget(KEY,2,IPC_CREAT|0660);
	while(1)
	{
		semctl(semid,0,SETVAL,0);
		semctl(semid,1,SETVAL,0);
		sop.sem_num=0;
		sop.sem_op=-1;
		sop.sem_flg=0;
		semop(semid,&sop,1);
		printf("client :%s\n",addr);
		 if(strcmp(addr,"bye")==0)
       		         exit(0);
		sop.sem_num=1;
		sop.sem_op=1;
		sop.sem_flg=0;
		printf("send a message \t");
		scanf("%s",&addr[500]);
		semop(semid,&sop,1);
	}
}
