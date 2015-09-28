#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX	100

void * do_your_job(void *input) {
	printf("child thread:\tinitial input\t= %d\n", *((int *) input));
	*((int *) input) = rand() % MAX;
	printf("child thread:\tfinal input\t= %d\n", *((int *) input));
	pthread_exit(NULL);
}

int main(void) {
	int input;
	pthread_t tid;

	input = 10;

	printf("main thread:\tinitial input\t= %d\n", input);
	pthread_create(&tid, NULL, do_your_job, &input);
	pthread_join(tid, NULL);
	printf("main thread:\tfinal input\t= %d\n", input);
	return 0;
}
