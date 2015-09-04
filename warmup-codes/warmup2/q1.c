/*
  Notes:
	  - Different architectures give different results.
*/

#include <stdio.h>

#define SIZE 4

void fill(int array[SIZE]) {
	int i;
	for(i = 0; i < sizeof(array); i++)
		array[i] = i;
}

int main(void) {
	int i;
	int array[SIZE];
	fill(array);

	printf("==== dump array ==== \n");
	for (i = 0; i < SIZE; i++)
		printf("%d ", array[i]);
	printf("\n==== end ====\n");
	return 0;
}
