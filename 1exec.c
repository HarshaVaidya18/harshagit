#include<stdio.h>
#include<unistd.h>
void main(int argc,const char *argv[])
{
	int ret;
	ret=execvp("objdump",argv);
	if(ret<0)
		printf("Failed to change the process image\n");
}
