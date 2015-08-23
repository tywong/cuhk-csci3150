#include <stdio.h>
#include <unistd.h>	// fork(), getpid()
#include <sys/wait.h>	// wait()

int main(void)
{
	int pid;
	if( (pid = fork()) )
	{
		printf("Look at the status of the process %d\n", pid);
		while( getchar() != '\n' );
		wait(NULL);
		printf("Look again!\n");
		while( getchar() != '\n' );
	}
	return 0;
}
