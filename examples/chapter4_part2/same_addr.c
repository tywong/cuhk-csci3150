#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	int pid;
	pid = fork();
	printf("PID %d: %p.\n", getpid(), &pid);
	if(pid)
		wait(NULL);
	return 0;
}
