#include <stdio.h>
#include "list.h"

struct data {
    int data;
    struct list_head list;
};

int main(void) {
  struct data obj, *obj_ptr;
  struct list_head *list_ptr;

  list_ptr = &(obj.list);
  obj_ptr = container_of(
        list_ptr, struct data, list);
  printf("%d\n", (obj_ptr == &obj) );
}

