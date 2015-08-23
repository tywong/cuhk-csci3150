#include <stdio.h>	// required by printf()
#include <string.h>	// required by memset()

#define ONE_MEG	(1024 * 1024)

char a[1024 * ONE_MEG];

int main(void) {
	memset(a, 0, sizeof(a));
	printf("1GB OK\n");
	return 0;
}
