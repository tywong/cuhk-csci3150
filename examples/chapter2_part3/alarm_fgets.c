#include <stdio.h>	// printf(), fgets()
#include <stdlib.h>	// exit()
#include <unistd.h>	// alarm()
#include <signal.h>	// "SIGALRM", signal()

#define TIMEOUT	2

void sig_handler(int sig)
{
	printf("\nTimeout! Go on!\n");
	alarm(TIMEOUT);
}

int main(void)
{
	char buf[1024];
	signal(SIGALRM, sig_handler);
	alarm(TIMEOUT);
	if(fgets(buf, 1024, stdin) == NULL)
	{
		printf("No input. Goodbye!\n");
		exit(0);
	}
	alarm(0);
	printf("Your input: %s", buf);
	return 0;
}
