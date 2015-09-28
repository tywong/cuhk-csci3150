#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define STR_MAX	1024
#define THREAD	2

void *thread_func(void *input)
{
	char *token;
	int i = 0, thread_num;

	thread_num = ((char *) input)[strlen(input) - 1] - '0';		
	printf("Thread %d: I start with the input %s\n", thread_num, (char *) input);

	token = strtok((char *) input, " ");		// 1st step for strtok()
	do
	{
		printf("Thread %d: Token %d = %s\n", thread_num, i++, token);
		sleep(1);
	}
	while((token = strtok(NULL, " ")) != NULL);	// later steps for strtok()

	printf("Thread %d: terminated.\n", thread_num);

	pthread_exit(0);
}

int main(void)
{
	pthread_t tid[THREAD];
	char buf[THREAD][STR_MAX];
	int i;

	for(i = 0; i < THREAD; i++)
	{
		sprintf(buf[i], "Thread %d says: Linux is a cool operating system %d", i, i);
		pthread_create(&tid[i], NULL, thread_func, buf[i]);
	}

	for(i = 0; i < THREAD; i++)
		pthread_join(tid[i], NULL);

	return 0;
}
