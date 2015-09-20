#include <stdio.h>
#include <stdlib.h>	// atoi()

void print_usage(char *name) {
	fprintf(stderr,
		"Usage: %s [0|1]\n\twhere 0 - don't call printf(); 1 - call printf()\n",
		name);
}

int main(int argc, char **argv) {
	int i, is_printf;
	double x = 0;

	if(argc != 2) {
		print_usage(argv[0]);
		exit(1);
	}

	is_printf = atoi(argv[1]);
	if(is_printf != 0 && is_printf != 1) {
		print_usage(argv[0]);
		exit(1);
	}

	for(i = 1; i <= 1000000; i++) {
		x += i;
		if(is_printf == 1)
			printf("x = %.0f\n", x);
	}

	return 0;
}
