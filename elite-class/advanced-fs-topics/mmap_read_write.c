#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAP_LENGTH 11
#define FILENAME "a.txt"

int main(){
    int fd, i, j;
    int file_offset = 0;
    char *array ;

    fd = open( FILENAME, O_RDWR, 0600 );
    array = (char *) mmap( NULL, MAP_LENGTH,
            PROT_WRITE | PROT_READ, // read-write mode
            MAP_SHARED,             // to reflect changes
            fd, file_offset );

    if(array == MAP_FAILED) {
  		perror("mmap");
  		exit(1);
  	}

    // Do you know what the following loop is doing?
    for ( i = 0, j = MAP_LENGTH-1; i < j; i++, j-- ) {
      array[i] = array[i] ^ array[j];
      array[j] = array[i] ^ array[j];
      array[i] = array[i] ^ array[j];
    }

    munmap( array, MAP_LENGTH );
    close(fd);
	return 0;
}
