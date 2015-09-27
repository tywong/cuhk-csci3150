#include <stdio.h>	// printf(), getchar()
#include <signal.h>	// signal(), "SIGINT"

void sig_handler(int sig)
{
	if(sig == SIGINT)
		printf("I've received Ctrl + C\n");
	else if(sig == SIGQUIT)
		printf("I've received Ctrl + \\\n");
}

int main(void)
{
	int c;
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	printf("Press enter\n");
	c = getchar();
	printf("End of program (%c) \n", c);
	return 0;
}
