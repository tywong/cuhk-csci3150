#include <stdio.h>	// required by printf()
#include <stdlib.h>	// required by malloc()
#include <string.h>	// required by malloc()
#include <math.h>

#define ONE_MEG  1024 * 1024
char global[1024 * ONE_MEG];

int main(void) {
	void *ptr;
	unsigned long long counter = 0;
	char local [8000 * 1024];

	while(1) {
		ptr = malloc(ONE_MEG);
		if(!ptr) {
			perror("malloc()");
			break;
		}
		counter++;
		printf("Allocated %lld MB\n", counter);
	}

	return 0;
}
