#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAP_LENGTH  50

int main(void) {
  int i;
	unsigned long long *array;

  array = mmap (NULL,    // NULL means not mapping any files.
      MAP_LENGTH,
			PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANONYMOUS,   // both flags are essential.
			-1, 0);

	if(array == MAP_FAILED) {
		perror("mmap()");
		exit(1);
	}

  /* Guess: what the following codes are doing? */

	array[0] = 1;
	array[1] = 1;
	for(i = 2; i < MAP_LENGTH; i++) {
		array[i] = array[i-1] + array[i-2];
    printf("%d\t%llu\n", i, array[i]);
  }

	return 0;
}
