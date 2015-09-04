/*
	Notes:
	 - problem occurs in 32-bit Ubuntu 14.04
	 - problem occurs in 64-bit Ubuntu 14.04
*/

#include <stdio.h>
#include <stdlib.h>

#define ROWS	10
#define COLS	8

void process_array(int array[ROWS][COLS]) {
	int i, j, count = 0;
	for(i = 0; i < ROWS; i++)
		for(j = 0; j < COLS; j++)
			array[i][j] = count++;
}

int main(void) {
	int **array = malloc(sizeof(int) * ROWS * COLS);
	process_array(array);
/****
	int i, j;
	for(i = 0; i < ROWS; i++) {
		for(j = 0; j < COLS; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
****/
	return 0;
}
