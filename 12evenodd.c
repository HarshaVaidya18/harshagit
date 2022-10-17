#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *thread1(void *);
void *thread2(void *);
void main()
{
        int num=10;
        void *ptr;
        pthread_t ti1,ti2;
        pthread_create(&ti1,NULL,thread1,&num);
        pthread_create(&ti2,NULL,thread2,&num);
        pthread_join(ti1,&ptr);
        pthread_join(ti2,&ptr);
}
void *thread1(void *ptr)
{
        int num=*(int *)ptr;
        for(int i=0;i<num;i++)
        {
		if(i%2==0)
		{
                	printf("Even : %d\n",i);
		}
                sleep(1);
        }

}
void *thread2(void *ptr)
{
        int num=*(int *)ptr;
	for(int i=0;i<num;i++)
        {
                if(i%2!=0)
                {
                        printf("Odd : \n",i);
                }
               sleep(1);
        }

}


