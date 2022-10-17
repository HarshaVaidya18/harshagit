#include<stdio.h>
#include<pthread.h>
void *small_thread(char *);
void *large_thread(char *);
void main()
{
	int *ptr;
	pthread_t t1,t2;
	int x;
	char str[25];
	printf("enter the string\n");
	scanf("%s",str);
	pthread_create(&t1,NULL,small_thread,&str);
	pthread_create(&t2,NULL,large_thread,str);
	pthread_join(t1,&ptr);
	pthread_join(t2,NULL);
}
void *small_thread(char *ptr)
{
	int i;
	for(i=0;ptr[i]!='\0';i++)
	{
		if(ptr[i]>=97 && ptr[i]<=122)	
			printf("Small letters : %c\n",ptr[i]);
		
	}
}
void *large_thread(char *ptr)
{
        int i;
        for(i=0;ptr[i]!='\0';i++)
        {
                if(ptr[i]>=65 && ptr[i]<=90)
                        printf("Capital letters : %c\n",ptr[i]);

        }
}
