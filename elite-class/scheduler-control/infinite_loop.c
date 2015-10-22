#include <stdio.h>
#include <stdlib.h>

#define MAX	10000000LL

void print_usage(char *p_name) {
	fprintf(stderr, "Usage: %s [1 | 2 | 3]\n", p_name);
	fprintf(stderr, "\t1: fast; 2: slow; 3: very slow [default is 1].\n");
}

/*
 *  My choice:
 *    I prefer strtol() over atoi().
 */
int check_input(char *in, int *i) {
	char *temp;

	*i = strtol(in, &temp, 10);
	if(*temp != '\0')
		return -1;

	if(*i > 3 || *i < 1)
		return -1;

	return 0;
}

int main(int argc, char **argv) {
	unsigned long long i, limit;
	int result;

	if( argc == 1 )
		result = 0;
	else if( check_input(argv[1], &result) == -1 ) {
		print_usage(argv[0]);
		exit(1);
	}

	limit = MAX;
	for(i = 0; i < result; i++)
		limit *= 10;

	printf("PID = %d\n", getpid());
	for(i = 0; i < limit; i++) {
		if(i % (limit / 10) == 0) {
			printf(".");
			fflush(stdout);
		}
	}
	printf("done\n");

	return 0;
}
