#include <stdio.h>

int main(void) 	{
	unsigned long temp = 0x89ABCDEF;
	int i;
	unsigned char *ptr = (unsigned char *) &temp;

	if(ptr[0] == 0xef) {
		printf("This CPU is little endian, i.e., ending value in small (little) address\n");
	}
	else {
		printf("This CPU is big endian, i.e., ending value in big address\n");
	}

	printf("Byte-by-byte printing:\t");
	for(i = 0; i < sizeof(unsigned long); i++)
		printf("%x", ptr[i]);
	printf("\n");

	printf("Printing by value:\t");
	printf("%lx\n", temp);

	return 0;
}
