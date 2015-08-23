#include <stdio.h>		// required by fprintf()
#include <stdlib.h>		// required by exit()
#include <unistd.h>		// required by read(), write()
#include <sys/types.h>		// required by open()
#include <sys/stat.h>		// required by open()
#include <fcntl.h>		// required by open()

#define SRC	"/dev/zero"	// the white hole...
#define BUF	1048576		// 1 MB
#define CNT	4096		// going to write 4096 MB

int main(int argc, char **argv)
{
	int fd[2], rtn, i;
	char buf[BUF];

	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
		exit(1);
	}

	if( (fd[0] = open(SRC, O_RDONLY)) == -1 )
	{
		perror("open() the source");
		exit(1);
	}

	if( (fd[1] = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0600)) == -1 )
	{
		perror("open() the destination");
		exit(1);
	}

	fprintf(stderr, "Start writing a file of size %d MB ", CNT);
	fflush(stderr);

	for(i = 0; i < CNT; i++)
	{
		if( (rtn = read(fd[0], buf, BUF)) <= 0 )
		{
			perror("read()");
			exit(1);
		}

		if( write(fd[1], buf, rtn) <= 0 )
		{
			perror("write()");
			exit(1);
		}

		if((i % (CNT / 10)) == 0)
		{
			fprintf(stderr, ".");
			fflush(stderr);
		}
	}
	fprintf(stderr, "done\n");

	return 0;
}
