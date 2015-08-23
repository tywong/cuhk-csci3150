#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/times.h>

int main(int argc, char **argv)
{
	char c;
	struct tms start, end;
	clock_t start_clock, end_clock;
	unsigned long ticks = sysconf(_SC_CLK_TCK);

	start_clock = times(&start);
	while(read(fileno(stdin), &c, 1) > 0);
	end_clock = times(&end);

	printf("%.4f\t%.4f\t%.4f\n",
		(end_clock - start_clock) / (double) ticks,
		(end.tms_utime - start.tms_utime) / (double) ticks,
		(end.tms_stime - start.tms_stime) / (double) ticks);

	return 0;
}
