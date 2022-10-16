#include<stdio.h>
int main()
{
	int ret;
	int opt;
	char str[50];
	while(1)
	{
		printf("=========================\n");
		printf("0.Exit\n1.Make a directory\n2.Remove a directory\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:
				exit(0);
			case 1:
				printf("Enter a name to your directory\n");
				scanf("%s",str);
				ret=mkdir(str);
			        if(ret<0)
           				   printf("Failed to create a directory\n");
				else
     					   printf("Drirectory create Succerssfully\n");
				break;
			case 2:
				printf("Enter the directory you want to remove\n");
				scanf("%s",str);
				ret=rmdir(str);
				if(ret<0)
					printf("Failed to remove, Please re-enter\n");
				else
			       		printf("Removed the directory successfully\n");
				break;
			default:
				printf("Enter a valid input\n");
		}
	}




	
/*	ret=mkdir("Mydir");
	if(ret<0)
	{
		printf("Failed to create a directory\n");
		return -1;
	}
	printf("Drirectory create Succerssfully\n");
	sleep(8);
	ret=rmdir("Mydir");
	printf("Removed the directory successfully\n");*/
}
