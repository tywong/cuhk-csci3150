#include <stdio.h>

#define FACTORIAL(in) \
		({ \
			int p = 1, i; \
			for(i = 1; i <= (in); i++) \
				p = p * i; \
			p; \
		})

int main(void) {
	int ans = FACTORIAL(6);
	printf("%d\n", ans);
	return 0;
}
