#include "int_header.h"

int multi_int(int a, int b)
{
	if(b == 0)
		return 0;
	else if(b == 1)
		return a;
	else
		return add_int(a, multi_int(a, b-1));
}
