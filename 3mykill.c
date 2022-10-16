#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
int main(int argc, char *argv[])
{
	int ret1,ret2,ret;
	if(argc!=3)
	{
		printf("Cant kill\n");
		return -1;
	}
	ret1=atoi(argv[1]);
	ret2=atoi(argv[2]);
	ret=kill(ret2,ret1);
	if(ret<0)
	{
		printf("Failed to kill\n");
		return -1;
	}
	printf("Killed successfully\n");

}

