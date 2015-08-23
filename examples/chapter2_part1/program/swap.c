#include <stdio.h>
#define SWAP(a,b)  { int c; c = a; a = b; b = c; }

int main(void)
{
	int i = 10, j = 20;
	printf("before swap: i = %d, j = %d\n", i, j);
	SWAP(i, j);
	printf("after swap: i = %d, j = %d\n", i, j);
	return 0;
}
