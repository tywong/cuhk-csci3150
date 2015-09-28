#include <stdio.h>
#include <stdlib.h>

int global_int;

int main(void) {
	int *malloc_ptr = malloc(4);
	char *constant_ptr = "hello";

	printf("Local variable  = %15p\n", &malloc_ptr);
	printf("malloc() space  = %15p\n", malloc_ptr);
	printf("Global variable = %15p\n", &global_int);
	printf("Code & constant = %15p\n", constant_ptr);
	printf("Code & constant = %15p\n", main);
	return 0;
}
