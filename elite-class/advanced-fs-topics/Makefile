CC=gcc
CFLAGS=-Wall

EXE=\
	flock \
	mmap_read_write \
	mmap_memory \
	mmap_read_from_file \
	mmap_write_to_file \
	mmap_memory \


TESTFILE=a.txt
ARRAYFILE=array.dat

all: $(EXE) create_file

create_file: $(ARRAYFILE) $(TESTFILE)

$(ARRAYFILE):
	dd if=/dev/zero of=$(ARRAYFILE) bs=4 count=10

$(TESTFILE):
	echo "hello world" > $(TESTFILE)

clean:
	rm -f $(EXE) $(ARRAYFILE) $(TESTFILE)
