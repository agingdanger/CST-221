#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


pthread_mutex_t mute = PTHREAD_MUTEX_INITIALIZER;
void *process();
int buff = 0;

main()
{
	int tr1, tr2;
	pthread_t thread1, thread2;
	if((tr1=pthread_create( &thread1, NULL, &process, NULL)))
	{
		printf("fail on: %d\n", tr1);
	}
	
	if((tr2=pthread_create( &thread2, NULL, &process, NULL)))
	{
		printf("fail on: %d\n", tr2);
	}
	


	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL);
	pthread_join( thread1, NULL);


	pthread_join( thread2, NULL);
	exit(0);

	
}

void *process()
{
	pthread_mutex_lock( &mute);
	buff++;
	printf("Val: %d\n", buff);
	//pthread_mutex_unlock( &mute);
}
