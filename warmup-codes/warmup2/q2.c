#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE	8

struct T {
	char flag[4];
//	int flag;
	char ch;
};

int main(void)
{
	struct T *array = malloc(sizeof(struct T) * SIZE);
	memset(array, -1, 5 * SIZE);

	int i, j;
	for(i = 0; i < SIZE; i++)
	{
		printf("array[%d]\tflag=", i);
		printf("flag = %x", array[i].flag);
//		for(j = 0; j < 4; j++)
//			printf("%x", array[i].flag[j]);
		printf("\tch=%d\n", array[i].ch);
	}

	free(array);

	return 0;
}
