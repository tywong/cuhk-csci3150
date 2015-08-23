#include <stdio.h>
#include <string.h>	// memset();
#include <unistd.h>	// getpid();

#define BUF_SIZE	512 * 1024

void re()
{
	char buf[BUF_SIZE];

	printf("Real allocation...");
	fflush(stdout);
	while( getchar() != '\n' );

	memset(buf, 0, sizeof(buf));

	printf("Virtual allocation...");
	fflush(stdout);
	while( getchar() != '\n' );
	re();
}

int main(void)
{
	printf("PID = %d\n", getpid());
	re();
	return 0;
}
