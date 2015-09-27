#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig) {
	printf("Press any key to continue...");
	getchar();
	exit(0);
}

int main(void) {
	int *ptr = NULL;
	signal(SIGSEGV, handler);
	printf("%d\n", *ptr);
	return 0;
}
