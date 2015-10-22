#include <stdio.h>
#include <sched.h>

int main(void) {
	int min, max;

	min = sched_get_priority_min(SCHED_OTHER);
	max = sched_get_priority_max(SCHED_OTHER);
	printf("SCHED_OTHER (%d): [%d, %2d]\n", SCHED_OTHER, min, max);

	min = sched_get_priority_min(SCHED_RR);
	max = sched_get_priority_max(SCHED_RR);
	printf("SCHED_RR    (%d): [%d, %2d]\n", SCHED_RR, min, max);

	min = sched_get_priority_min(SCHED_FIFO);
	max = sched_get_priority_max(SCHED_FIFO);
	printf("SCHED_FIFO  (%d): [%d, %2d]\n", SCHED_FIFO, min, max);

	return 0;
}
