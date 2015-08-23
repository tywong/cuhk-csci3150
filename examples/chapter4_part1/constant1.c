#include <stdio.h>	// required by printf()

int main(void)
{
	char *string = "hello";
	printf("Ptr to \"hello\" = %p\n", "hello");
	printf("Ptr to \"hello\" = %p\n", string);
	string[4] = '\0';
	printf("Go to %s\n", string);
	return 0;
}
