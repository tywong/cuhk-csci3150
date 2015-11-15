#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAP_LENGTH  10
#define FILENAME "array.dat"

int main(){
  int fd, i;
  int file_offset = 0;
  int *array;

  fd = open( FILENAME, O_RDWR, 0600 );
  array = (int *) mmap( NULL, MAP_LENGTH,
          PROT_WRITE, // write only
          MAP_SHARED, // to reflect changes
          fd, file_offset );

  if(array == MAP_FAILED) {
		perror("mmap");
		exit(1);
	}

  for ( i = 0; i < MAP_LENGTH; i++ ) {
    array[i] = rand() % 10;
  }

  munmap( array, MAP_LENGTH );
  close(fd);
	return 0;
}
