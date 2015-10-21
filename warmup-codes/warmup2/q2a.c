#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE	8

// Version 1 structure!
struct T {
	char flag[4];
	char ch;
};

int main(void) {
	struct T *array = malloc(sizeof(struct T) * SIZE);
	memset(array, -1, 5 * SIZE);

	int i, j;
	for(i = 0; i < SIZE; i++) {
		printf("array[%d]\tflag=", i);
		for(j = 0; j < 4; j++)
			printf("%d ", array[i].flag[j]);
		printf("\tch=%d\n", array[i].ch);
	}

	free(array);
	return 0;
}
