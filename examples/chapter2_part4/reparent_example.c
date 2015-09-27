#include <stdio.h>	// printf()
#include <unistd.h>	// getpid(), getppid(), sleep(), fork()
#include <sys/types.h>	// getppid()

int main(void) {
	if(fork() == 0) {
		int i;
		for(i = 0; i < 5; i++) {
			printf("(%d) parent's PID = %d\n",
				getpid(),	// My PID
				getppid()	// My Parent's PID
			);
			sleep(1);
		}
	}
	else
		sleep(1);	// Parent or Child?

	printf("(%d) bye.\n", getpid());
	return 0;
}
