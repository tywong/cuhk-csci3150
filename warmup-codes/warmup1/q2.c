/*
	Notes:
	 - problem occurs in 32-bit Ubuntu 14.04
	 - no problem occurred in 64-bit Ubuntu 14.04
*/

#include <stdio.h>
#include <stdlib.h>

int count = 0;

int * new_array() {
	int i, *array = (int *) malloc(sizeof(int) * 9);

	for(i = 0; i <= 9; i++)
		array[i] = count++;

	for(i = 0; i <= 9; i++)
		printf("%d ", array[i]);
	printf("\n");

	return array;
}

int main(void) {
	int i;
	int *a;
	for(i = 0; i < 10; i++) {
		a = new_array();
	}
	return 0;
}
