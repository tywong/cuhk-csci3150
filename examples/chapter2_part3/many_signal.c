#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void handler(int sig) {
	static int count = 0;
	int i;
	printf("count = %d\n", ++count);
	usleep(100000);
}

int main(void) {
	int i;
	if(fork() == 0) {
		printf("Press Enter...\n");
		getchar();
		for(i = 0; i < 100000; i++)
			kill(getppid(), SIGQUIT);
	}
	else {
		signal(SIGQUIT, handler);
		sleep(1000);
		wait(NULL);
	}
	return 0;
}
