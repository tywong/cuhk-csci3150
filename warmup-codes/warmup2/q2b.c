#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE	8

// Version 2 structure!
struct T {
	int flag;
	char ch;
};

int main(void) {
	struct T *array = malloc(sizeof(struct T) * SIZE);
	memset(array, -1, 5 * SIZE);

	int i;
	for(i = 0; i < SIZE; i++) {
		printf("array[%d]\t", i);
		printf("flag=%d\t", array[i].flag);
		printf("ch=%d\n", array[i].ch);
	}

	free(array);
	return 0;
}
