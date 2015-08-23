#include <stdio.h>	// "NULL"
#include <stdlib.h>	// srand(), rand()
#include <time.h>	// time()
#include <sys/types.h>	// kill(), getpid()
#include <unistd.h>	// getpid()
#include <signal.h>	// kill()

int main(void)
{
	int i, sum, count = 0;;
	srand(time(NULL));
	while(1)
	{
		sum = 0;
		for(i = 0; i < 3; i++)
			sum += (rand() % 6) + 1;
		if(sum == 18)
		{
			printf("count = %d\n", count);
			kill(getpid(), SIGTERM);
		}
		else
			count++;
	}
	return 0;
}
