obj-m = proc_mole.o buffer_test.o
KVERSION = $(shell uname -r)

all: $(EXE)

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
