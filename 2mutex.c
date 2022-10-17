#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *fun1(void *);
void *fun2(void *);
int global=0;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
void main()
{
        int num=50;
        void *ptr;
        pthread_t ti1,ti2;
        pthread_create(&ti1,NULL,fun1,&num);
        pthread_create(&ti2,NULL,fun2,&num);
	 pthread_mutex_lock(&mutex);
	pthread_join(ti1,&ptr);
        pthread_join(ti2,&ptr);
}
void *fun1(void * ptr)
{
	int num=*(int *)ptr;
	for(int i=0;i<num;i++)
	{
		pthread_mutex_lock(&mutex1);
		printf("thread 1 value : %d\n",global);
		global++;
		pthread_mutex_unlock(&mutex);
	}

}
void *fun2(void *ptr)
{
	int num=*(int *)ptr;
	for(int i=0;i<num;i++)
	{
		pthread_mutex_lock(&mutex);
                printf("thread 2 value : %d\n",global);
                global++;
        pthread_mutex_unlock(&mutex1);
        }
}


