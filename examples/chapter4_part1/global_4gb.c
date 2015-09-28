#include <stdio.h>	// required by printf()
#include <string.h>	// required by memset()

#define ONE_MEG	(1024 * 1024)

char a[1024 * ONE_MEG];
char b[1024 * ONE_MEG];
char c[1024 * ONE_MEG];
char d[1024 * ONE_MEG];

int main(void) {
	printf("start\n");
	memset(a, 0, sizeof(a));
	printf("1GB OK\n");
	memset(b, 0, sizeof(b));
	printf("2GB OK\n");
	memset(c, 0, sizeof(c));
	printf("3GB OK\n");
	memset(d, 0, sizeof(d));
	printf("4GB OK\n");
	return 0;
}
