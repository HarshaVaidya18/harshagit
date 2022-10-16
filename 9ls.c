#include<stdio.h>
#include<dirent.h>
void main()
{
	DIR *dir;
	struct dirent *list;
	dir=opendir(".");
	while((list=readdir(dir))!=NULL)
		printf("%s\n",list->d_name);
	closedir(dir);
}
