#include <stdio.h>	// printf()
#include <unistd.h>	// sleep()
#include <signal.h>	// signal()

void signal_handler(int sig)
{
	printf("\nsignal received\n");
}

int main(void)
{
	signal(SIGINT, signal_handler);
	printf("I'm sleeping for 24 hours...\n");
	sleep(60 * 60 * 24);
	printf("Wake up and die\n");
	return 0;
}
