#include <stdio.h>
#include <stdlib.h>
#include "list.h"


////////////////////////////////////

struct head_type {
	int count;
	struct list_head list;
};

////////////////////////////////////

struct data_type {
	int data;
	struct list_head list;
};

////////////////////////////////////

void add_element(struct head_type *h, int data)
{
	/*
		1. Use malloc() to create an object of struct data_type;
		2. Initialize the "list_head" in the new object.
		3. Using "list_add" defined in list.h to add to the list.
		(Using "list_add" / "list_add_tail" is up to you)
	*/
}

////////////////////////////////////

void print_list(struct head_type *h)
{
	struct data_type *p;
	printf("List length = %d\n", h->count);
	list_for_each_entry(p, &(h->list), list) {
		/* print the content of list here */
	}
}

////////////////////////////////////

void remove_element(struct head_type *h, int data)
{
	struct data_type *p, *safe_ptr;
	list_for_each_entry_safe(p, safe_ptr, &(h->list), list)	{
		/*
			1. Locate any one of the nodes containing "data".
			2. Use list_del() to remove the node.
			3. break;
		*/
	}
}

////////////////////////////////////

int main(void)
{
	struct head_type h;
	INIT_LIST_HEAD(&h.list);	// list_head initialization.
	h.count = 0;

	add_element(&h,1);
	add_element(&h,3);
	add_element(&h,5);
	add_element(&h,7);
	add_element(&h,9);

	print_list(&h);

	remove_element(&h, 3);
	remove_element(&h, 5);
	remove_element(&h, 7);

	print_list(&h);

	return 0;
}
