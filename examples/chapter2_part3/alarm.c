#include <stdio.h>
#include <unistd.h>	// alarm()

int main(int argc, char **argv)
{
	alarm(3);
	while(1) puts("hey");
	return 0;
}
