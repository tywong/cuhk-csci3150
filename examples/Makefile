SUBDIRS = chapter2_part1 \
	chapter2_part2 \
	chapter2_part3 \
	chapter2_part4 \
	chapter2_part6 \
	chapter3_part1 \
	chapter3_part2 \
	chapter4_part1 \
	chapter4_part2 \


all:
	for dir in $(SUBDIRS) ; \
	do \
		make -C $$dir; \
	done

chapter3_part2:
	make -k -C chapter3_part2

clean:
	for dir in $(SUBDIRS) ; \
	do \
		make -C $$dir clean; \
	done
