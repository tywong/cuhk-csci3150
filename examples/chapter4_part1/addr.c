#include <stdio.h>
#include <stdlib.h>

int global_int;

int main(void)
{
	int *malloc_ptr = malloc(4);
	char *constant_ptr = "hello";

	printf("Local variable  = %10p\n", &malloc_ptr);
	printf("malloc() space  = %10p\n", malloc_ptr);
	printf("Global variable = %10p\n", &global_int);
	printf("Code & constant = %10p\n", constant_ptr);
	printf("Code & constant = %10p\n", main);
	return 0;
}
