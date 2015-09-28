#include <stdio.h>	// required by printf()
#include <stdlib.h>	// required by malloc()
#include <string.h>	// required by malloc()
#include <unistd.h>

#define ONE_MEG  1024 * 1024

int main(void) {
	void *ptr;
	unsigned long long counter = 0;

	while(1) {
		ptr = malloc(ONE_MEG);
		if(!ptr) {
			perror("malloc()");
			break;
		}
		counter++;
		printf("Allocated %lld MB (%10p)\n",
			counter, ptr - 8);
	}

	printf("Take a look on me. I'm %d\n", getpid());
	printf("Ctrl+C to break...");
	fflush(stdout);
	pause();

	return 0;
}
