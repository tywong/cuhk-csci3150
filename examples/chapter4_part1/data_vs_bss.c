#include <stdio.h>

int global_data = 10;
int global_bss;

int main(void) {
	static int static_data = 10;
	static int static_bss;

	printf("global  bss = %p\n", &global_bss);
	printf("static  bss = %p\n", &static_bss);
	printf("global data = %p\n", &global_data);
	printf("static data = %p\n", &static_data);

	return 0;
}
