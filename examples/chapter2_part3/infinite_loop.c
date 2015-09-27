#include <stdio.h>	// printf()
#include <unistd.h>	// sleep()
#include <signal.h>	// "SIGINT", signal()

int stop = 0;

void sig_handler(int sig) {
	stop = 1;
}

int main(void) {
	unsigned int i = 0;

	signal(SIGINT, sig_handler);
	printf("PID %d\n", getpid());

	while(!stop) {
		sleep(1);
		printf("%d sec\n", ++i);
		fflush(stdout);
	}

	printf("Exit peacefully\n");
	return 0;
}
