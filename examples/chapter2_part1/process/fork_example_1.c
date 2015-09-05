#include <stdio.h>	// required by printf()
#include <sys/types.h>	// required by getpid()
#include <unistd.h>	// required by getpid(), fork()

int main(void) {
	printf("Ready (PID = %d)\n", getpid());
	fork();
	printf("My PID is %d\n", getpid());
	return 0;
}
