#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char buf[1024];

int main(void)
{
	if(setvbuf(stdout, NULL, _IOFBF, 0) != 0)
	{
		perror("setvbuf");
		exit(1);
	}

	printf("H");	sleep(1);
	printf("E");	sleep(1);
	printf("L");	sleep(1);
	printf("L");	sleep(1);
	printf("O");	sleep(1);
	printf("\n");	sleep(1);

	return 0;
}
