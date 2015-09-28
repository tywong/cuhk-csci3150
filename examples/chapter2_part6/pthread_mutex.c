#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

int shared;		/* this data is shared by the thread(s) */
int max;		/* this data is shared by the thread(s) */

pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

/*
	The thread function
 */
void *do_your_job(void *input)
{
	int number = *((int *) input);
	int i = 0;

	printf("Thread %d: starts execution.\n", number);

	while(1)
	{
		pthread_mutex_lock(&mutex);	// locking

		if(shared < max)		// reading shared variables
		{
			shared++;		// writing shared variables
			i++;
			printf("Thread %d: shared = %d.\n", number, shared);
		}
		else
		{
			pthread_mutex_unlock(&mutex);	// unlocking before break.
			break;
		}

		pthread_mutex_unlock(&mutex);	// unlocking
		sleep(rand() % 2);	// forced context switching
	}

	printf("Thread %d: termination: I'm responsible for %d updates.\n", number, i);

	pthread_exit(0);

	return NULL;
}

/*
	Main function
 */
int main(int argc, char *argv[])
{
	pthread_t *tid;		/* the thread identifiers */
	int thread_num;		/* the total number of threads created */
	int *id, i;

	if(argc != 3)
	{
		fprintf(stderr, "usage: %s [max value] [num of threads]\n", argv[0]);
		exit(1);
	}

	if(atoi(argv[1]) < 0)
	{
		fprintf(stderr, "1st argument must be non-negative\n");
		exit(1);
	}

	if(atoi(argv[2]) < 0)
	{
		fprintf(stderr, "Second argument must be > 0\n");
		exit(1);
	}

/* variable initialization */

	srand(time(NULL));
	max = atoi(argv[1]);
	thread_num = atoi(argv[2]);

	printf("Number of threads created = %d\n", thread_num);
	if( (tid = (pthread_t *) malloc(sizeof(pthread_t) * thread_num)) == NULL)
	{
		perror("malloc()");
		exit(1);
	}

	if( (id = (int *) malloc(sizeof(int) * thread_num)) == NULL)
	{
		perror("malloc()");
		exit(1);
	}

/* create the threads */

	for(i = 0; i < thread_num; i++)
	{
		id[i] = i;
		if(pthread_create(&tid[i], NULL, do_your_job, &id[i]) != 0)
		{
			perror("pthread_create");
			exit(0);
		}
	}

/* now wait for the thread to exit */

	for(i = 0; i < thread_num; i++)
		pthread_join(tid[i], NULL);

/* free the memory */

//	free(tid);
//	free(id);

	return 0;
}

