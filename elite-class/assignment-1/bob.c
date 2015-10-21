#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv)
{
	clock_t begin, current, end;
	int interval;

	if(argc != 2) {
		fprintf(stderr, "Usage: %s [output frequency (HZ)]\n", argv[0]);
		exit(1);
	}
	interval = CLOCKS_PER_SEC / atoi(argv[1]);

	begin = end = clock();
	while(1)
	{
		current = clock();
		if((current - end) >= interval) {
			printf("%c[1;32mBob %5d: %.2fs%c[m\n", 27, getpid(), ((double) (current - begin)) / CLOCKS_PER_SEC, 27);
			end += interval;
		}
	}
	return 0;
}
