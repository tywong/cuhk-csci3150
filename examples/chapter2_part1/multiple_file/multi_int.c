#include "int_header.h"

int multi_int(int a, int b) {
	int sign = (b < 0) ? -1 : 1;
	int c = (b < 0) ? -b : b;
	int ans = 0;

	if(b == 0)
		return 0;

	while(c-- > 0) {
		ans = add_int(a, ans);
	}

	return (ans * sign);
}
