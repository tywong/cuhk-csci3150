# Compilation

The program `global_2gb.c` should yield compilation errors. Therefore, please compile this set of programs with the following command:

```
make -k
```

The switch `-k` means *"keep going"*.

# Summary

- `addr.c`.  This program shows the relative positions of codes, global variables, local variables, and dynamically allocated memory.

- `constant_ptr.c & access_code.c`. This pair of programs demonstrates that a constant pointed by a pointer as well as the code pointed by a function pointer is read-only.

- `constant_array.c`. This is a counterpart of the program `constant_ptr.c`. The main difference between the two programs is:

  ```c
  // constant_ptr.c
  char *string = "hello";

  // constant_array.c
  char string[] = "hello";
  ```

  In this program, one can observe that the the constant is copied to the array `string`. That's why it is writable.

- `global_vs_static.c`. This program shows that the static variables inside functions are actually global variables.

- `data_vs_bss.c`. This program shows that when a global is initialized or uninitialized, their memory locations are different.

- `bss_small.c` & `bss_large.c`. This pair of programs shows that for uninitialized global variables, the compiled programs should be of the same size.

  ```
  $ ls -l bss_small bss_large
  ... 4272 ... bss_large
  ... 4272 ... bss_small
  ```

- `data_small.c` & `data_large.c`. This pair of programs shows that for initialized global variables, the sizes of the compiled programs should vary.

  ```
  $ ls -l data_small data_large
  ... 1007792 ... data_large
  ...    8368 ... data_small
  ```

- `global_{1,2,3,4}gb.c`. This set of programs demonstrates whether you can allocate global variables of a total size of 1GB, 2GB, 3GB, and 4GB, respectively.

  1. First, you have to run on a machine with enough memory, i.e., the sum of physical RAM and swap space is greater than 4GB.
  2. On a 32-bit system, both `global_3gb.c` and `global_4gb.c` fail to run.
  3. On a 64-bit system, both `global_3gb.c` and `global_4gb.c` can run successfully.
  4. `global_2gb.c` cannot be compiled. Can you can the code so that it can allocate a continuous space of 2GB in the global variable zone?

- `stack.c` is a simple program illustrating how the stack space grows.

- `max_stack.c`. This program allocates a space of 8MB on the stack. It usually fails unless you use the command `ulimit` to change the stack size limit.

- `stack_overflow.c`. This program allocates stack space through recursion. The main function already allocates stack space of more than 8000KB. The recursive function ``recursion`` keeps allocating an extra 40KB of stack space through its local variables.

- `malloc_distance.c`. This program demonstrates the distance (in bytes) between two adjacent allocated memory blocks. The distance implies that the `malloc()` call reserves space for each `malloc()` call.

  Note importantly that this example only works how the amount of allocation is smaller than 128KB. Beyond 128KB, `malloc()` uses `mmap()` for memory allocation.

  1. On 32-bit systems, the distance should be 8 bytes.
  2. On 64-bit systems, the distance should be 16 bytes.

- `oom_v1.c` & `oom_v2.c`. This pair of codes tries to use up all the memory in the system by running an infinite loop. They both failed because the memory allocated is not really allocated (because of demand paging). Note that in order to observe meaningful results, please run the programs on 32-bit systems.

  The difference between the two programs:
  1. `oom_v2.c` allocates a significant amount of space (approx. 8MB) in the stack while `oom_v1` does not.
  2. `oom_v1.c` should report a bigger allocation from the heap than those reported from `oom_v2.c`.

- `code_start.c`. The program uses the segmentation fault signal to look for the beginning address of the code segment. We can verify the answer using the command `pmap`.
