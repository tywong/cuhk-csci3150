#include <stdio.h>
#include <stdlib.h>
#include <sched.h>  // sched_setscheduler(), sched_getparam()

int main(int argc, char **argv) {
	int pid;
	char *tmp;
	struct sched_param sp;

	if(argc != 2) {
		fprintf(stderr, "Usage: %s [PID]\n", argv[0]);
		exit(1);
	}

	pid = strtol(argv[1], &tmp, 10);
	if(*tmp != '\0') {
		fprintf(stderr, "Usage: %s [PID]\n", argv[0]);
		exit(1);
	}

	if(sched_getparam(pid, &sp) == -1) {
		perror("Error: sched_getparam()");
		exit(1);
	}

	sp.sched_priority = 99;
	if(sched_setscheduler(pid, SCHED_FIFO, &sp) == -1) {
		perror("Error: sched_setscheduler()");
		exit(1);
	}

	printf("From now on, PID %d will seized the CPU!\n", pid);

	return 0;
}
