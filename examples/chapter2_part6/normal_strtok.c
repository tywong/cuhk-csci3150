#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX	1024
#define THREAD	2

int main(void)
{
	char buf[STR_MAX];
	char *token;
	int i = 0;

	sprintf(buf, "Linux is a cool operating system");

	token = strtok((char *) buf, " ");		// 1st step for strtok()
	do
	{
		printf("Token %d = %s\n", i++, token);
	}
	while((token = strtok(NULL, " ")) != NULL);	// later steps for strtok()

	return 0;
}
