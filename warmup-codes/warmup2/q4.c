#include <stdio.h>
#include <unistd.h>

int main(void) {
	pid_t pid;
	if( pid = fork() == 0 ) {
		printf("child started\n");
	}

	if(pid == 0) {
		// child process
		int i;
		for(i = 0; i < 10; i++) {
			printf("working %d\n", i);
			sleep(1);
		}
		printf("done\n");
		return 0;
	}
	else {
		// parent process
		return 0;
	}
}
