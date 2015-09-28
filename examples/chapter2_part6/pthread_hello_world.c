#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void * hello(void *input)
{
	int i;

	for(i = 0; i < 100000000; i++)
	{
		if(i == 10000000)
			printf("T:DAM!\n");
		if(i == 50000000)
			printf("T:BAM!\n");
		if(i == 100000000-1)
			printf("T:GAM!\n");
	}

	printf("%s\n", (char *) input);
	pthread_exit(NULL);
}

int main(void)
{
	int i;
	pthread_t tid;
	pthread_create(&tid, NULL, hello, "hello world");

	for(i = 0; i < 100000000; i++)
	{
		if(i == 10000000)
			printf("JAM\n");
		if(i == 50000000) 
			printf("EAM\n");
		if(i == 100000000-1)
			printf("ZAM\n");
	}

	pthread_join(tid, NULL);
	printf("main thread terminated\n");
	return 0;
}
