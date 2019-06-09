#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

//initializing functions
void 
myfunc1 (void *ptr);

void
myfunc2 (void *ptr);

//character buffer
char buf[24];

//semaphore decl
sem_t rSem, wSem;

int main (int c, char *v[])
{
	//initialize threads
	pthread_t t1, t2;
	
	//message for each thread
	char *msg1 = "Thread 1";
	char *msg2 = "Thread 2";
	//initialize sems
	sem_init(&rSem, 0, 1);
	sem_init(&wSem, 0, 1);
	//thread create
	pthread_create(&t1, NULL, (void *)&myfunc1, (void *)msg1);
	pthread_create(&t2, NULL, (void *)&myfunc2, (void *)msg2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	sem_destroy(&rSem);

	return 0;
}

//first function with pointer param
void myfunc1(void *ptr)
{
	char *msg = (char *)ptr;
	printf("%s\n", msg);
	//wait call for reader sem
	sem_wait(&rSem);
	printf("writing..\n");
	sprintf(buf, "%s", "Hello");
	sem_post(&wSem);
	sem_post(&rSem);
	pthread_exit(0);
}

//second function with pointer param
void myfunc2(void *ptr)
{
	char *msg = (char *)ptr;
	printf("%s\n", msg);
	//wait for both reader and writer
	sem_wait(&wSem);
	sem_wait(&rSem);
	printf("%s\n", buf);
	sem_post(&rSem);
	pthread_exit(0);
}
