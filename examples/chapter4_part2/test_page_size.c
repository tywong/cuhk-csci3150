#include <stdio.h>	// required by printf()
#include <stdlib.h>	// required by exit()
#include <unistd.h>	// required by sbrk()
#include <signal.h>	// required by signal()

char *prev_ptr = NULL;
char *ptr = NULL;

void handler(int sig)
{
	printf("Page size = %d bytes\n", (int) (ptr - prev_ptr));
	exit(0);
}

int main(int argc, char **argv)
{
	char c;

	signal(SIGSEGV, handler);
	prev_ptr = ptr = sbrk(0);	// mark the start of the heap.
	sbrk(5000);			// force 1-page allocation.
	while(1)
		c = *(++ptr);
	return 0;
}
