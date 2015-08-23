#include <stdio.h>

int main(void)
{
	char c;
	unsigned long long count = 0;
	while(1)
	{
		c = getchar();
		if(c == EOF)
			break;
		else
			count++;
	}
	printf("EOF is reached. Read %lld bytes.\n", count);
	return 0;
}
