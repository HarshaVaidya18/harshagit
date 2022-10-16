#include<stdio.h>
void main()
{
	FILE *fd;
	char name[25];
	printf("enter the file name\n");
	scanf("%s",name);
	fd=fopen(name,"w");
}
