#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(void) {
	pid_t pid;
	pid = syscall(SYS_gettid);
	syscall(SYS_exit, 0);
	printf("%d\n", pid);
	return 0;
}
