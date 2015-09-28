#define _LARGEFILE_SOURCE
#define _FILE_OFFSET_BITS 64

#include <stdio.h>
#include <stdlib.h>

#define PTABLE_START	446	// length of the boot code.

struct ptable {
	unsigned char	flag;
	unsigned char	chs_start_addr[3];
	unsigned char	type;
	unsigned char	chs_end_addr[3];
	unsigned int	lba_start_addr;
	unsigned int	size_in_sector;
} __attribute__ ((packed));

int main(int argc, char **argv) {
	FILE *fp;
	unsigned char buf[1000];
	struct ptable *ptr;
	int i;

	if(argc != 2) {
		fprintf(stderr, "Usage: %s [disk image]\n", argv[0]);
		exit(1);
	}

	if( (fp = fopen(argv[1], "r")) == NULL ) {
		perror(argv[1]);
		exit(1);
	}

	fseek(fp, PTABLE_START, SEEK_SET);	// skip boot code
	fread(buf, sizeof(struct ptable), 4, fp);

	ptr = (struct ptable *) buf;

	for(i = 0; i < 4; i++) {
		printf("Partition table #%d\n", i + 1);
		printf("------------------\n");

		printf("Bootable\t");
		if(ptr[i].flag == 0x80)
			printf("Yes\n");
		else
			printf("No\n");

		printf("LBA start addr\t%u\n", ptr[i].lba_start_addr);
		printf("type\t\t0x%02x\n", ptr[i].type);
		printf("size\t\t%u\n", ptr[i].size_in_sector);
		printf("\n");
	}
	return 0;
}
