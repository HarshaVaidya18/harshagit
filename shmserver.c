#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
#define KEY 0x19980
int main()
{
	char *ptr;
	int shmid=shmget(KEY,100,IPC_CREAT|0660);
	ptr=shmat(shmid,NULL,0);
	while(ptr[0]!='H');
	printf("client %s\n",ptr);
	shmdt(ptr);
}

