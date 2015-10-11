#include <stdio.h>

#define SWAP(A,B) do { \
	typeof(A) _c_ = A; \
  A = B; B = _c_; \
} while(0)

int main(void) {
  int a = 1, b = 2;
  double c = 3, d = 4;
	if(1 == 1)
  	SWAP(a, b);
	else
	  SWAP(c, d);
  printf("a: %d, b: %d, c: %lf, d: %lf\n", a, b, c, d);

  return 0;
}
