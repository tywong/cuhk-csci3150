#include <stdio.h>	// required by printf()
#include <stdlib.h>	// required by exit()
#include <unistd.h>	// required by fork(), sleep()
#include <signal.h>	// required by signal()
#include <sys/wait.h>	// required by wait()
#include <sys/types.h>	// required by wait()

#define PROC_NUM	10	// number of processes

void sig_handler(int sig) {
	static int count = 0;
	int pid = 0;

	printf("\nSIGCHLD received.\n");
	pid = wait(NULL);		// This is important.
	count++;

	printf("wait() done. Child %d is terminated.\n", pid);
	if(count == PROC_NUM)
	{
		printf("\nAll child processes are terminated. Exiting.\n");
		exit(0);		// Goodbye
	}
}

void create_process(void) {
	int i;
	for(i = 1; i <= PROC_NUM; i++) {
		if(fork() == 0) {
			sleep(i);
			exit(0);
		}
	}
}

int main(void) {
	signal(SIGCHLD, sig_handler);
	create_process();
	while(1) {
		sleep(1);
	}
}
