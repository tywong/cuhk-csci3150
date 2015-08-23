#include <stdio.h>	// required by printf()
#include <string.h>	// required by memset()
#include <unistd.h>

int main(int argc, char **argv)
{
	char a[8000 * 1024];
	memset(a, 1, sizeof(a));
	printf("OK!\n");
	printf("PID = %d\n", getpid());
	printf("Ctrl+C to break...");
	fflush(stdout);
	pause();
	return 0;
}
