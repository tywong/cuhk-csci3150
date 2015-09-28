#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

char *ptr = NULL;
char *main_ptr = NULL;

void handler(int sig) {
	printf("           Code starts at %p\n", ptr + 1);
	printf("Reference: main starts at %p\n", main_ptr);
	printf("Please run \"pmap %d\"\n", getpid());
	pause();
}

int main(int argc, char **argv) {
	char c;
	main_ptr = (char *) main;
	signal(SIGSEGV, handler);
	ptr = (char *) main;
	while(1) {
		ptr--;
		c = *ptr;
	}
	return 0;
}
