#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * do_your_job(void *input) {
	int id = *((int *) input);
	printf("My ID number = %d\n", id);
	pthread_exit(NULL);
}

int main(void)
{
	int i;
	pthread_t tid[5];

	for(i = 0; i < 5; i++)
		pthread_create(&tid[i], NULL, do_your_job, &i);

	for( ; i < 10; i++)
		pthread_join(tid[i-5], NULL);
	return 0;
}
