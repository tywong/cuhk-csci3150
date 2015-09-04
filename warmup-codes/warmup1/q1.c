/*
	Can you interchange the execution order of the printf() statements?!

	Notes:
	 - problem occurs in 32-bit Ubuntu 14.04
	 - problem occurs in 64-bit Ubuntu 14.04
*/

#include <stdio.h>

int * addition(int a, int b) {
	int c = a + b;
	int *d = &c;
	return d;
}

int main(void) {
	int result = *(addition(1, 2));
	int *result_ptr = addition(1, 2);
	printf("result = %d\n", *result_ptr);
	printf("result = %d\n", result);
	return 0;
}
