#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

char *ptr = NULL;
char *main_ptr = NULL;

void handler(int sig)
{
	printf("             Code ends at %p\n", ptr + 4);
	printf("Reference: main starts at %p\n", main_ptr);
	exit(0);
}

int main(int argc, char **argv)
{
	main_ptr = (char *) main;
	signal(SIGSEGV, handler);
	ptr = (char *) &main_ptr;
	printf("ptr starts at %p\n", ptr);
	while(1)
	{
		ptr -= 4;
		*ptr = 0;
	}
	return 0;
}
