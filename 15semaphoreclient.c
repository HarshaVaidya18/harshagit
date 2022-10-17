 #include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/sem.h>
#include<sys/shm.h>
#define KEY 0x19920
int main()
{
	struct sembuf sop;
	char *addr;
	int shmid=shmget(KEY,1000,0);
	addr=shmat(shmid,NULL,0);
	int semid=semget(KEY,2,0);
	while(1)
	{
		printf("send a message\t");
		scanf("%s",addr);
		sop.sem_num=0;
		sop.sem_op=1;
		sop.sem_flg=0;
		semop(semid,&sop,1);
		 if(strcmp(addr,"bye")==0)
       		         exit(0);
		sop.sem_num=1;
		sop.sem_op=-1;
		sop.sem_flg=0;
		semop(semid,&sop,1);
		printf("server :%s\n",&addr[500]);
	}
}
