#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <signal.h>

void sig_handler(int sig) {
	fprintf(stderr, "\n");
}

void print_usage(char *cmd) {
	fprintf(stderr,
		"Usage: %s [filename] [mode]\n"
		"\tmode = 1: shared lock\n"
		"\tmode = 2: exclusive lock\n",
		cmd);
}

int main(int argc, char **argv) {
	int fd;
	int mode;

	if(argc != 3) {
		print_usage(argv[0]);
		exit(1);
	}

	if( (fd = open(argv[1], O_RDONLY)) == -1) {
		perror("open()");
		exit(1);
	}

	mode = atoi(argv[2]);
	if(mode != 1 && mode != 2) {
		print_usage(argv[0]);
		exit(1);
	}

	puts("waiting for the lock...");
	if(mode == 1)
		flock(fd, LOCK_SH);	/** Shared lock **/
	else
		flock(fd, LOCK_EX);	/** Exclusive lock **/

	signal(SIGINT, sig_handler);
	puts("I'm inside the protected region");

	pause();

	flock(fd, LOCK_UN);	/** Release lock **/
	puts("I'm outside the protected region");

	return 0;
}
