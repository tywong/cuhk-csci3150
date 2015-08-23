#include <unistd.h>

int main(void)
{
	while(fork())
		wait(NULL);
	return 0;
}
