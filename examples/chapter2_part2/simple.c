#include <stdio.h>

int main(void) {
	int i, x;
	x = 0;
	for(i = 1; i <= 100000; i++) {
		x = i + x;
		printf("x = %d\n", x);
	}
	return 0;
}
