#include <stdio.h>

#ifndef offsetof
	#define offsetof(TYPE, MEMBER) ( (size_t) &((TYPE *) 0)->MEMBER )
#endif

#define container_of(ptr, type, member) ({ \
const typeof( ((type *)0)->member ) *__mptr = (ptr); \
(type *)( (char *)__mptr - offsetof(type,member) );})

struct list_head {
	struct list_head *prev, *next;
};


struct data_type {
	int data;
	struct list_head list;
};

int main(void) {
	struct data_type object;
	struct data_type *object_ptr;
	struct list_head *list_ptr;

	list_ptr = &(object.list);
	object_ptr = container_of(list_ptr, struct data_type, list);

	printf("%d\n", (object_ptr == &object));
	return 0;
}
