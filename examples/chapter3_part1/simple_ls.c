#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>	// opendir(), readdir(), closedir()

int main(int argc, char **argv)
{
	DIR *dir;
	char *input = ".";
	struct dirent *entry;

	if(argc > 1)
		input = argv[1];

	if( (dir = opendir(input)) == NULL )
	{
		perror("opendir()");
		exit(1);
	}

	while( (entry = readdir(dir)) != NULL )
		printf("%ld\t\t%s\n",
			(long) entry->d_ino,
			entry->d_name);

	closedir(dir);

	return 0;
}
