#include<stdio.h>
#include<sys/shm.h>
#include<string.h>
#define KEY 0x19980
int main()
{
	char *ptr;
	int shmid=shmget(KEY,100,0);
	ptr=shmat(shmid,NULL,0);
	strcpy(ptr,"Hi");
	shmdt(ptr);
}
