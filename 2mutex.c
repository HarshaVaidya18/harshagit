#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
void *thread_even(void *);
void *thread_odd(void *);
int i=1;
void main()
{
	int ret,num=100;
	pthread_t ti1,ti2;
	int *ptr;
	pthread_create(&ti1,NULL,thread_even,&num);
	pthread_create(&ti1,NULL,thread_odd,&num);
	pthread_join(ti1,&ptr);
	pthread_join(ti2,&ptr);
	printf("Done\n");
}
void *thread_even(void *ptr)
{
	int num= *(int *)ptr;
	for(i;i<=num;i++)
	{
			pthread_mutex_lock(&mutex);
		if(i%2==0)
		{
			printf("Even : %d\n",i);
			i++;
		}
		else
		{
			pthread_mutex_unlock(&mutex);
		}
	}
}
void *thread_odd(void *ptr)
{
        int num= *(int *)ptr;
        for(i;i<=num;i++)
        {
			pthread_mutex_lock(&mutex);
                if(i%2!=0)
                {
                        printf("Odd : %d\n",i);
                        i++;
                }
                else
                {
                      pthread_mutex_unlock(&mutex);
                }
        }
}

			
