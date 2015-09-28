#include <stdio.h>
#include <stdlib.h>		// rand(), srand(), exit()
#include <unistd.h>		// sleep()
#include <time.h>		// time()
#include <pthread.h>		// pthread_*()
#include <errno.h>		// "ETIMEDOUT"

#define LIFE_INIT	3
#define TIMEOUT_INIT	8
#define TIMEOUT_MIN	2
#define DICE_COUNT	3

#define IS_BIG(x)	( (x) >= 11 )
#define IS_SMALL(x)	( (x) <  11 )

int global_input = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t input_cond = PTHREAD_COND_INITIALIZER;

void * read_input(void *nothing)
{
	int c;

	while(1)
	{
		if( (c = getchar()) == 0 )
		{
			printf("End of input. Bye\n");
			exit(1);
		}

		pthread_mutex_lock(&mutex);
		if(c != '\n')
		{
			global_input = c;
			while( getchar() != '\n');
		}
		pthread_cond_signal(&input_cond);
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

int all_the_same(int dice[])
{
	int i;
	for(i = 0; i < DICE_COUNT-1; i++)
		if(dice[i] != dice[i+1])
			break;

	if(i != DICE_COUNT-1)	// dice are not the same.
		return 0;
	else
		return 1;
}

//// Helper function: display the game screen ////

void display(int dice[], int life, int point, int level)
{
	int i;
	system("clear");
	printf("+---+---+---+\n");
	for(i = 0; i < DICE_COUNT; i++)
		printf("| %d ", dice[i]);
	printf("|\n");
	printf("+---+---+---+\n");
	printf("[LIFE LEFT: %d]\t[POINTS: %2d]\t[LEVEL: %2d]\t[B/S/N]? ", life-1, point, level+1);
	fflush(stdout);
}

int wait_for_input(int level)
{
	int wait_ret, input, timeout;
	struct timespec t;

	timeout = TIMEOUT_INIT - level;
	if(timeout < TIMEOUT_MIN)
		timeout = TIMEOUT_MIN;

	t.tv_sec = time(NULL) + timeout;
	t.tv_nsec = 0;

	pthread_mutex_lock(&mutex);

		if(global_input == 0)
		{
			wait_ret = pthread_cond_timedwait(&input_cond, &mutex, &t);
			if(wait_ret == ETIMEDOUT)
			{
				input = 0;
				sleep(1);
			}
			else
			{
				input = global_input;
			}
		}
		else
			input = global_input;

		global_input = 0;

	pthread_mutex_unlock(&mutex);

	return input;
}

void *game_play(void *nothing)
{
	int i, input, sum, life = LIFE_INIT, point = 0, level = 0;
	int dice[DICE_COUNT];

	srand(time(NULL));
	while(1)
	{
		for(i = 0; i < DICE_COUNT; i++)
			dice[i] = rand() % 6 + 1;

		display(dice, life, point, level);
		input = wait_for_input(level);

		if(input == 0)	// 0 - means no input until timeout.
		{
			life--;
			printf("\nTIMEOUT\n");
		}
		else	// has an input.
		{
			if(input != 'B' && input != 'b' &&
			   input != 's' && input != 'S' &&
			   input != 'n' && input != 'N')
			{
				life--;
				printf("WRONG\n");
			}
			else
			{
				if(input == 'B')
					input = 'b';
				if(input == 'S')
					input = 's';
				if(input == 'N')
					input = 'n';

				for(i = 0, sum = 0; i < DICE_COUNT; i++)
					sum += dice[i];

				if((IS_BIG(sum) && input != 'b') ||
				   (IS_SMALL(sum) && input != 's') ||
				   (all_the_same(dice) && input != 'n') )
				{
					life--;
					printf("WRONG\n");
				}
				else
				{
					point++;
					printf("CORRECT\n");
				}
			}
		}

		if(life == 0)
		{
			printf("End of game. Bye\n");
			exit(0);
		}

		if(point > 0 && point % 10 == 0)
			level++;

		usleep(500000);
	}
}

void display_intro()
{
	system("clear");
	printf(
		"BIG or SMALL\n"
		"------------\n\n"
		"- Three dices are thrown;\n"
		"- If their sum is less than 11, then type 's' (for small);\n"
		"- If their sum is greater than or equal to 11, then type 'b' (for big);\n"
		"- However, if three of them are the same, then type 'n' (for none);\n\n"
		"- You only have a limited time to input your answer;\n"
		"- Higher the score is, the faster the timeout becomes;\n\n"
		"Press enter to start the game. "
	);
	fflush(stdout);
	while(getchar() != '\n');
}

int main(void)
{
	pthread_t tid1, tid2;
	display_intro();
	pthread_create(&tid1, NULL, read_input, NULL);
	pthread_create(&tid2, NULL, game_play, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	return 0;
}
