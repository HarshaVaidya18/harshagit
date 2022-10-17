#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
	int fd1,fd2,ret;
	char buf1[1024],buf2[1024],buf3[1024],buf4[1024];
	fd1=open(argv[1],O_RDWR);
	if(fd1<0)
	{
		printf("Failed to open first file\n");
		return -1;
	}
	fd2=open(argv[2],O_RDWR);
	if(fd2<0)
	{
		printf("Failed to open Second file\n");
		return -1;
	}
	ret=read(fd1,buf1,1024);
	buf1[ret]='\0';
	printf("Content of First file : %s\n",buf1);
	ret=read(fd2,buf2,1024);
	buf2[ret]='\0';
	printf("Content of Second file : %s\n",buf2);
	truncate(argv[1],0);
	truncate(argv[2],0);
	ret=write(fd1,buf2,strlen(buf2));
	ret=write(fd2,buf1,strlen(buf1));
	printf("AFTER SWAPPING\n");


	ret=read(fd1,buf3,1024);
        buf3[ret]='\0';
        printf("Content of First file : %s\n",buf3);
        ret=read(fd2,buf4,1024);
        buf4[ret]='\0';
        printf("Content of Second file : %s\n",buf4);
        close(fd1);
        close(fd2);
}



