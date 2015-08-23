#include <stdio.h>	// required by printf()

int main(void)
{
	unsigned long temp = 0x89ABCDEF;
	int i;
	unsigned char *ptr = (unsigned char *) &temp;

	printf("Byte-by-byte printing:\t");
	for(i = 0; i < sizeof(unsigned long); i++)
		printf("%x", ptr[i]);
	printf("\n");

	printf("Printing by value:\t");
	printf("%lx\n", temp);

	return 0;
}
