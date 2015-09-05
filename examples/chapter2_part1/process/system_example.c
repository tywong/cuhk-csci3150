#include <stdio.h>	// required by printf()
#include <stdlib.h>	// required by system()

int main(void)
{
	printf("before system ...\n");
	system("ls -l");
	printf("after system ...\n");
	return 0;
}
