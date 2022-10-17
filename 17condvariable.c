#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
void *even_thread(void *ptr);
void *odd_thread(void *ptr);
int i=1;
int main()
{
	int num=40;
	int *ptr;
	pthread_t ti1,ti2;
	pthread_create(&ti1,NULL,even_thread,&num);
	pthread_create(&ti2,NULL,odd_thread,&num);
	pthread_join(ti1,&ptr);
	pthread_join(ti2,&ptr);
	printf("FINAL i VALUE : %d\n",i);
}
void *even_thread(void *ptr)
{
        int num,k=0;
        num=*(int *)ptr;
        while(i<num)
        {
                pthread_mutex_lock(&mutex);
                if(i%2!=0)
                {
                        pthread_cond_wait(&cond,&mutex);
                }
                printf("even :%d\n",i);
                i++;
                pthread_cond_signal(&cond);
                pthread_mutex_unlock(&mutex);
        }
}
void *odd_thread(void *ptr)

{
        int num;
        num=*(int *)ptr;
        while(i<num)
        {
                pthread_mutex_lock(&mutex);
                if(i%2==0)
                {
                        pthread_cond_wait(&cond,&mutex);
                }
                printf("odd  :%d\n",i);
                i++;
                pthread_cond_signal(&cond);
                pthread_mutex_unlock(&mutex);
        }
}

