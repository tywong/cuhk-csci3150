#include <stdio.h>

#ifndef offsetof

#define offsetof(TYPE, MEMBER) ( (size_t) &((TYPE *) 0)->MEMBER )

#endif

struct foobar {
	char a;
	short b;
	int c;
	long d;
	float e;
	double f;
};


[0...32]

int main(void) {
	printf("offset of a = %u\n", offsetof(struct foobar, a));
	printf("offset of b = %u\n", offsetof(struct foobar, b));
	printf("offset of c = %u\n", offsetof(struct foobar, c));
	printf("offset of d = %u\n", offsetof(struct foobar, d));
	printf("offset of e = %u\n", offsetof(struct foobar, e));
	printf("offset of f = %u\n", offsetof(struct foobar, f));
	return 0;
}
