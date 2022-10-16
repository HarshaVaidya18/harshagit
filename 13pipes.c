#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int fd[2];
	int ret;
	char buf[100],str[100];
	ret=pipe(fd);
	if(ret<0)
	{
		printf("Failed to create a pipe\n");
		return -1;
	}
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		close(fd[0]);
		while(1)
		{
			printf("Send a message to child : ");
			scanf("%s",str);
			ret=write(fd[1],str,strlen(str));
		}
	}
	else if(pid==0)
	{
		close(fd[1]);
		while(1){
			ret=read(fd[0],buf,10);
			buf[ret]='\0';
			printf("Message from parent : %s\n",buf);}
	}
}

