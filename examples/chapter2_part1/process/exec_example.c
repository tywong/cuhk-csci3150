#include <stdio.h>	// required by printf()
#include <unistd.h>	// required by execl()

int main(void) {
	printf("before execl...\n");

	execl("/bin/ls", "/bin/ls", "-l", "-a", NULL);

	printf("after execl...\n");

	return 0;
}
