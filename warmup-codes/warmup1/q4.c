/*
	Notes:
	 - problem occurs in 32-bit Ubuntu 14.04
	 - problem occurs in 64-bit Ubuntu 14.04
*/

#include <stdio.h>
#include <string.h>
#define SIZE 5

void print_array(int *array, char *name, int len) {
	int i;
	printf("%s = { ", name);
	for(i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("}\n");
}

int main(void) {
	char string1[SIZE] = { '1','2','3','4','\0' };
	char string2[SIZE], string3[SIZE];
	int array1[SIZE] = { 1, 2, 3, 4, 5 };
	int array2[SIZE], array3[SIZE];

	strncpy(string2, string1, sizeof(string1));
	memcpy (string3, string1, sizeof(string1));

	printf("string2 = %s\n", string2);
	printf("string3 = %s\n", string3);

	strncpy((char *) array2, (char *) array1, sizeof(array1));
	memcpy(array3, array1, sizeof(array1));

	print_array(array2, "array2", SIZE);
	print_array(array3, "array3", SIZE);

	return 0;
}
