#include <stdio.h>

int main(void) {
	char *string  = "hello";
	printf("\"hello\"      = %p\n", "hello");
	printf("String pointer = %p\n", string);
	string[4] = '\0';
	printf("Go to %s\n", string);
	return 0;
}
