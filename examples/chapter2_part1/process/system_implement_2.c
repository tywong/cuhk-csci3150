#include <stdio.h>	// required by printf()
#include <stdlib.h>	// required by exit()
#include <unistd.h>	// required by fork(), exec family
#include <sys/wait.h>	// required by wait()

int system_ver_3150(const char *cmd_str) {
	if(cmd_str == NULL)
		return -1;

	if(fork() == 0) {
		execl(cmd_str, cmd_str, NULL);
		fprintf(stderr, "%s: command not found\n", cmd_str);
		exit(-1);
	}

	wait(NULL);
	return 0;
}

int main(void) {
	printf("\033[1;30m\033[1;42mbefore..\n\033[0m\n");
	printf("\033[1;37m\033[1;41m");
	fflush(stdout);
	system_ver_3150("/bin/ls");
	printf("\033[1;30m\033[1;42m\nafter..\n\033[0m");
	return 0;
}
