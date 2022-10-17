#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *fun1(void *);
void *fun2(void *);
void main()
{
        int num=10;
        void *ptr;
        pthread_t ti1,ti2;
        pthread_create(&ti1,NULL,fun1,&num);
        pthread_create(&ti2,NULL,fun2,&num);
        pthread_join(ti1,&ptr);
        pthread_join(ti2,&ptr);
}
void *fun1(void *num)
{
        int numm=*(int *)num;
        for(int i=0;i<numm;i++)
        {
		if(i%2==0)
		{
                	printf("%d is even num\n",i);
		}
                sleep(1);
        }

}
void *fun2(void *num)
{
        int numm=*(int *)num;
	for(int i=0;i<numm;i++)
        {
                if(i%2!=0)
                {
                        printf("%d is odd num\n",i);
                }
               sleep(1);
        }

}


