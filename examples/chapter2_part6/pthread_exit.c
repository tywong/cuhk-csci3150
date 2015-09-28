#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void * do_your_job(void *input) {
	int *output = (int *) malloc(sizeof(int));
	srand(time(NULL));
	*output = ((rand() % 10) + 1) * (*((int *) input));
	pthread_exit(output);
}

int main(void) {
	pthread_t tid;
	int input = 10, *output;
	pthread_create(&tid, NULL, do_your_job, &input);
	pthread_join(tid, (void **) &output);
	printf("output = %d\n", *output);
	return 0;
}
