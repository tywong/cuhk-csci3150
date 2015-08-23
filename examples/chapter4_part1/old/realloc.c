#include <stdio.h>	// required by printf()
#include <stdlib.h>	// required by malloc()

int main(void)
{
	void *p1, *p2, *p3, *p4;
	p1 = malloc(16);
	p2 = malloc(16);
	p3 = realloc(p1, 32);
	p4 = malloc(16);

	printf("%d\n", (int) (p3-p1));
	printf("%d\n", (int) (p4-p1));

	return 0;
}
