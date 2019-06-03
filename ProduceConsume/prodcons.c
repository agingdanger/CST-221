# include <stdio.h>
# include <pthread.h>

int theproduct = 1;



int produce()
{
	return theproduct++;
}

void consume(int i)
{
	if(i = 0)
	{
	printf("can't do that right now\n");
		return;
	}
	printf("%i", i);
	printf("\n");
	i = 0;
}
/*grabs a number and places it on the thread if available*/
void* producer()
{
	int i;
	while(1)
	{
		i = produce();
		put(i);
		return;
	}
}
/*calls the consume function which prints the number to the console*/
void* consumer()
{
	int i;
	while(1)
	{
		i = get();
		consume(i);
		return;
	}
}
/* Gets the current product and will sleep if state isn't correct  */
int get()
{
	
	if(theproduct = 0)
	{
		sleep(10);
		return;
	}
	return theproduct;
}
/* makes variable i the current product to be printed/consumed*/
void put(int i)
{
	theproduct = i;
}

int main()
{
	pthread_t t1,t2;
	
	pthread_create(&t1,NULL,producer, &theproduct);
	pthread_create(&t2,NULL,consumer, &theproduct);
	pthread_join(t1,NULL);

}
