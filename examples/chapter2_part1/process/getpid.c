#include <stdio.h>	// required by printf()
#include <unistd.h>	// required by getpid()

int main(void) {
	printf("My PID is %d\n", getpid());
	return 0;
}
