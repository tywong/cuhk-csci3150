#include <stdio.h>      // required by printf()
#include <sys/types.h>  // required by getpid()
#include <unistd.h>     // required by getpid(), fork()

int main(void) {
	int result;

	printf("before fork ...\n");
	result = fork();
	printf("result = %d\n", result);

	if(result == 0) {
		sleep(1);
		printf("I'm the child\n");
		printf("My PID is %d\n", getpid());
	}
	else {
		sleep(1);
		printf("I'm the parent\n");
		printf("My PID is %d\n", getpid());
	}

	printf("program terminated\n");

	return 0;
}
