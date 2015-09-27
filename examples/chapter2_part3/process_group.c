#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
	printf("%d\n", getpid());
}

int main(void ) {
	signal(SIGINT, handler);
	fork();
	pause();
	return 0;
}
