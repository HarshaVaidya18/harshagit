#include<stdio.h>
#include<sys/shm.h>
#include<string.h>
#define KEY 0x19980
int main()
{
	char *ptr;
	char buf[1024];
	int shmid=shmget(KEY,100,0);
	ptr=shmat(shmid,NULL,0);
	printf("Enter a message : %s",buf);
	strcpy(ptr,buf);
	shmdt(ptr);
}
