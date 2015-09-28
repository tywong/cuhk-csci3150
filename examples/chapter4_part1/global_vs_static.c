#include <stdio.h>

int global_int = 0;

int main(void) {
	int local_int = 0;
	static int static_int = 0;

	printf("local_int  addr = %p\n", &local_int);
	printf("static_int addr = %p\n", &static_int);
	printf("global_int addr = %p\n", &global_int);
	printf("addr difference = %d\n",
		(char *) &static_int - (char *) &global_int
	);
	return 0;
}
