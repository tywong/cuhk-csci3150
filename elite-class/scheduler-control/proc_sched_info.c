#include <stdio.h>
#include <stdlib.h>
#include <sched.h>         // sched_getscheduler(), sched_setscheduler()
#include <sys/time.h>      // getpriority()
#include <sys/resource.h>  // getpriority()
#include <unistd.h>
#include <sys/types.h>

void do_job(int pid) {
	int ret;
	struct sched_param sp;

  //// Read and report the scheduling policy ////

	if((ret = sched_getscheduler(pid)) == -1) {
		perror("sched_getscheuler()");
		exit(1);
	}

	switch(ret) {
	  case SCHED_OTHER:
		printf("Scheduling policy\t\t= SCHED_OTHER (%d)\n", SCHED_OTHER);
		break;
	  case SCHED_RR:
		printf("Scheduling policy\t\t= SCHED_RR (%d)\n", SCHED_RR);
		break;
	  case SCHED_FIFO:
		printf("Scheduling policy\t\t= SCHED_FIFO (%d)\n", SCHED_FIFO);
		break;
	  default:
		printf("Unknown policy\n");
		break;
	}

  //// Read and report the static priority ////

	if(sched_getparam(pid, &sp) == -1) {
		perror("sched_getschedparam()");
		exit(1);
	}
	printf("Static priority\t\t\t= %d\n", sp.sched_priority);

  //// Read and report the dynamic priority (or the nice value) ////

	if((ret = getpriority(PRIO_PROCESS, pid)) == -1)
		perror("getpriority() on PRIO_PROC");
	else
		printf("Priority of process\t\t= %d\n", ret);

	if((ret = getpriority(PRIO_PGRP, pid)) == -1)
		perror("getpriority() on PRIO_PGRP");
	else
		printf("Priority of process group\t= %d\n", ret);

	if((ret = getpriority(PRIO_USER, pid)) == -1)
		perror("getpriority() on PRIO_USER");
	else
		printf("Priority of user\t\t= %d\n", ret);
}

int main(int argc, char **argv) {
	char *temp;
	int pid;
	if(argc > 1) {
	//// I prefer strtol() over atoi() ////
		pid = strtol(argv[1], &temp, 10);
		if(*temp != '\0') {
			fprintf(stderr, "Usage: %s [PID]\n", argv[0]);
			exit(1);
		}

		printf("Process ID\t\t\t= %d\n", pid);
	}
	else {
		printf("Process ID\t\t\t= %d\n", getpid());
		pid = 0;
	}

	do_job(pid);
	return 0;
}
