#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
void myhandler(int);
int main()
{
	int i=0,x,ret;
	printf("PID :%d\n",getpid());
	signal(2,myhandler);
	while(i<50)
	{
		printf("1\n");
		i++;
		sleep(1);
	}
}
void myhandler(int signal_no)
{
	printf("RECEIVED SIGNAL %d\n",signal_no); //USER DEFINED
//	exit(0); // DEFAULT BEHAVIOUR SIG_DFL
//	return ; //IGNORE SIGNAL SIG_IGN

}
