#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
	char a[8192 * 1024];
	memset(a, 0, sizeof(a));
	printf("OK!\n");
	return 0;
}
