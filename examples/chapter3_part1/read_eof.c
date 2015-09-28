#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>	// read()

int main(void)
{
	int ret;
	char c;
	unsigned long long count = 0;
	while(1)
	{
		ret = read(fileno(stdin), &c, 1);
		if(ret == 0)
			break;
		else
		{
			count += ret;
			if(c == EOF)
				printf("WoW!\n");
		}
	}
	printf("EOF is reached. Read %lld bytes.\n", count);
	return 0;
}
