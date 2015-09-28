# Summary

- `same_addr.c` demonstrates that two processes are using the same variable name, reporting the same address. However, the two processes report different values. This is because the address is actually a *virtual address*.

- `test_page_size.c` measures the side of a basic allocation unit.

  1. The program does not have any prior `malloc()`, `sbrk()`, or `brk()` call.
  2. Then, the program grows the heap by 1 byte with `sbrk(1)`.
  3. Last, we can detect that the usable space allocated is actually 4096 bytes.

- `grow_stack.c` demonstrates the growth of the stack space using a recursive function call.

  1. First, you need two terminals.
  2. On **Terminal 1**, launch `grow_stack`.
    ```
    ## Terminal 1 ##

    $ ./grow_stack
    PID = 2358
    Real allocation...
    ```
  3. On **Terminal 2**, use the command `top` to monitor the process running `grow_stack`.
    ```
    ## Terminal 2 ##

    $ top -p 2358  ## PID of ./grow_stack
    ```
  4. On **Terminal 1**, press `Enter`.
  5. Then, `top` in **Terminal 2** will report the increase in the memory consumption on the `RES` column, i.e., the *memory resident on physical RAM*.
  6. On **Terminal 1**, press `Enter`.
  7. Then, `top` in **Terminal 2** will report the increase in the memory consumption on the `VIRT` column, i.e., the *virtual memory consumption*.

- ``grow_heap.c`` demonstrates the growth on the heap allocation.

  1. You need two terminals.
  2. On **Terminal 1**, launch `grow_heap`. As a matter of fact, the process has allocated 1GB of space in the virtual memory.

    ```
    ## Terminal 1 ##

    $ ./grow_heap
    PID = 2358
    ```
  3. On **Terminal 2**, launch `top` and you will find that the process has 1GB of space in the `VIRT` column.
  4. Press `Enter` on **Terminal 1**. Then, the process writes to 1MB of space.
  5. On **Terminal 1**, `top` reports a growth of 1MB in the `RES` column.
