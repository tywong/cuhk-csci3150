#include <stdio.h>
#include <stdlib.h>
#include <sched.h>      // sched_get_priority_max(), sched_get_priority_min,
                        // sched_setscheduler(), sched_param()
#include <string.h>
#include <unistd.h>		  // sysconf()
#include <sys/times.h>  // times(), setpriority()
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/resource.h>	// setpriority()

#define POLICY_NUM	3

/********

  int check_policy()
  ==================

  This function checks whether the input policy is a valid one or not.
  If not, an error message is shown. Then, the program is terminated.
  Else, the numeric representation of the policy is returned.

********/
int check_policy(const char *p, char *policy_array[]) {
	int i;
	for(i = 0; i < POLICY_NUM; i++)
		if(strcmp(p, policy_array[i]) == 0)
			break;

	if(i == POLICY_NUM) {
		fprintf(stderr, "Error: [sched policy] should be either:");
		for(i = 0; i < POLICY_NUM; i++) {
			fprintf(stderr, " %s", policy_array[i]);
			if(i+1 < POLICY_NUM)
				fprintf(stderr, ",");
			else
				fprintf(stderr, ".\n");
		}
		exit(1);
	}

	return i;
}

/********

  int check_static_prio()
  =======================

  This function checks whether the input priority is a valid one or not.
  There is such a need because under different scheduling policy, the
  min and max static priorities are different.

  If not valid, an error message is shown. Then, the program is terminated.
  Else, the priority is returned.

********/
int check_static_prio(const char *p, int policy, const char *policy_str) {
	int ret, min, max;
	char *temp;

  /****
	We don't use atoi() because there is no way for us to check
	whether the input is a number or not.

	See the manpage of strtol()
   ****/
	ret = strtol(p, &temp, 10);
	if(*temp != '\0') {
		fprintf(stderr, "Error: [sched priority] for %s should be in the range [%d, %d]\n",
			policy_str, min, max);
		exit(1);
	}

  /****
	Query the min and the max static priorities for the given policy.
   ****/
	max = sched_get_priority_max(policy);
	min = sched_get_priority_min(policy);

	if(ret < min || ret > max) {
		fprintf(stderr, "Error: [sched priority] for %s should be in the range [%d, %d]\n",
			policy_str, min, max);
		exit(1);
	}

	return ret;
}

/********

  int check_dynamic_prio()
  ========================

  This function checks whether the input dynamic priority is a valid one or not.

  If not valid, an error message is shown. Then, the program is terminated.
  Else, the priority is returned.

********/
int check_dynamic_prio(const char *p) {
	int ret;
	char *temp;

  /****
	We don't use atoi() because there is no way for us to check
	whether the input is a number or not.

	See the manpage of strtol()
   ****/
	ret = strtol(p, &temp, 10);
	if(*temp != '\0') {
		fprintf(stderr, "Error: dynamic priority should be in the range [-20, 19]\n");
		exit(1);
	}

	if(ret < -20 || ret > 19) {
		fprintf(stderr, "Error: dynamic priority should be in the range [-20, 19]\n");
		exit(1);
	}

	return ret;
}

/********

  int set_sched()
  ===============

  This function sets the scheduling policy and the static priority of the process.
  Note important that this function should only be invoked by the child process.

********/
void set_sched(int policy, int s_prio, int d_prio) {
	struct sched_param sp;

	if(setpriority(PRIO_PROCESS, 0, d_prio) == -1) {
		perror("Error: setpriority()");
		exit(1);
	}

	if(sched_getparam(0, &sp) == -1) {
		perror("Error: sched_getparam()");
		exit(1);
	}

	sp.sched_priority = s_prio;

	if(sched_setscheduler(0, policy, &sp) == -1) {
		perror("Error: sched_setscheduler()");
		exit(1);
	}
}

/********

  void run_job()
  ==============

  This function invokes the command using the new target scheduling policy and static priority.

  This function does the following things:
    - using fork()-and-exec*() to run the command.
    - before calling exec*(), the child process changes its scheduling policy and static priority.
    - the parent program will calculate the running time of child process using the system call times().

********/
void run_job(int policy, char *policy_name, int s_prio, int d_prio, char **cmd) {
	struct tms start_tms, end_tms;
	clock_t start, end;
	long ticks;
	int status, i;

/****
	The times() syscall presents the running time in terms of clock ticks.
	So, we need to know how many ticks in one second.
	To retrieve this data, we use the sysconf() syscall.

	See the manpage of sysconf() [man sysconf] and times() [man 2 times].
****/
	if( (ticks = sysconf(_SC_CLK_TCK)) == -1) {
		perror("Error: sysconf()");
		exit(1);
	}

	start = times(&start_tms);	//// Record the starting time ////

	if(fork() == 0)		//// fork() now ////
	{
	//// Child part ////

		printf("\nScheduling policy: [%s, %d, %d] ... ", policy_name, s_prio, d_prio);
		fflush(stdout);

		set_sched(policy, s_prio, d_prio);	//// Set the scheduling policy and static priority ////
		printf("set\n");

		printf("Running Command: ");
		for(i = 0; cmd[i] != NULL; i++)
			printf("%s ", cmd[i]);
		printf("\n");

		printf("--------------------------------------------------- child begins--\n\n");

		if(execvp(cmd[0], cmd) == -1) {
			perror("Error: execvp()");
			exit(1);
		}
	}
	else {
	//// Parent part ////

		signal(SIGINT, SIG_IGN);
		signal(SIGTERM, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGTSTP, SIG_IGN);

		wait(&status);

		signal(SIGINT, SIG_DFL);
		signal(SIGTERM, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		signal(SIGTSTP, SIG_DFL);

		printf("\n----------------------------------------------------- child ends--\n");
		printf("Return value: %d\n\n", status);

	//// Record the ending time and print the timing results. ////

		end = times(&end_tms);
		printf("Parent Real:\t%f\n", (end-start)/(double) ticks);
		printf("Parent User:\t%f\n", (end_tms.tms_utime-start_tms.tms_utime)/(double) ticks);
		printf("Parent Sys:\t%f\n", (end_tms.tms_stime-start_tms.tms_stime)/(double) ticks);
		printf("Child User:\t%f\n", (end_tms.tms_cutime-start_tms.tms_cutime)/(double) ticks);
		printf("Child Sys:\t%f\n", (end_tms.tms_cstime-start_tms.tms_cstime)/(double) ticks);
	}
}

/********

  The main function
  =================

  This function doesn't worth having any explanations.

 ********/

int main(int argc, char **argv) {
	int policy, s_prio, d_prio;
	char *policy_array[POLICY_NUM];

    //// It is so happened that SCHED_OTHER is 0, SCHED_FIFO is 1, and SCHED_RR is 2! ////

	policy_array[SCHED_OTHER] = "SCHED_OTHER";
	policy_array[SCHED_FIFO] = "SCHED_FIFO";
	policy_array[SCHED_RR] = "SCHED_RR";

	if(argc < 5) {
		fprintf(stderr, "Usage: %s [sched policy] [static priority] [command and arguments]\n", argv[0]);
		exit(1);
	}

	policy = check_policy(argv[1], policy_array);
	s_prio = check_static_prio(argv[2], policy, policy_array[policy]);
	d_prio = check_dynamic_prio(argv[3]);

    //// Invoke the command ////

	run_job(policy, policy_array[policy], s_prio, d_prio, argv + 4);

	return 0;
}
