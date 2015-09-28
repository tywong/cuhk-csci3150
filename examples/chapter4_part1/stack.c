#include <stdio.h>

#define PRINT_INT(X, FUN) printf("In %s, " #X " = %p\n", (FUN), &(X))

int fun2(int x, int y) {
	int c = 10;
	PRINT_INT(x, __FUNCTION__);
	PRINT_INT(y, __FUNCTION__);
	PRINT_INT(c, __FUNCTION__);
	return (x + y + c);
}

int fun1(int u, int v) {
	PRINT_INT(u, __FUNCTION__);
	PRINT_INT(v, __FUNCTION__);
	return fun2(v, u);
}

int main(void) {
	int a = 1, b = 2;
	PRINT_INT(a, __FUNCTION__);
	PRINT_INT(b, __FUNCTION__);
	b = fun1(a, b);
	return -1;
}
