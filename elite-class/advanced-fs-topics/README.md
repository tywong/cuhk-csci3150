# Summary

- `flock.c`: this program lock a file with either a **shared lock** (aka the read lock) or an **exclusive lock** (aka, the write lock).

  Consider the following demonstration:

  - Terminal 1:
    
     ```
    $ ./flock flock.c 1               # locking with shared lock
    waiting for the lock...           # acquiring the lock
    I'm inside the protected region   # lock acquired
    _
    ```

  - Terminal 2:
    
    ```
    $ ./flock flock.c 2               # locking with exclusive lock
    waiting for the lock...           # acquiring the lock
    ```

  - Terminal 3:
    
    ```
    $ ./flock flock.c 1               # locking with shared lock
    waiting for the lock...           # acquiring the lock
    I'm inside the protected region   # lock acquired
    _
    ```

  - Type `Ctrl+C` in both Terminals 1 and 3 release the shared locks from both processes.
  - Last, Terminal 3 will show that the exclusive lock is acquired.
  - Note importantly that the lock is applied over the opened file. Therefore, you can acquire the exclusive locks over two different files.

- `mmap_read_write.c`: this program demonstrates the use of the `mmap()` system call. A process can read and write over the mapped file.

  **Pop Quiz**. By reading Lines 29-33 without executing the program, do you know how the program will update the mapped file?

- `mmap_write_to_file.c` & `mmap_read_from_file.c`: this pair of program work as follows.

  1. Run `mmap_write_to_file.c` first. It will write data to the file.
  2. Then, run `mmap_read_from_file.c`. It will read the data written by `mmap_write_to_file.c`.

  What is the use of this pair of program?  You can create a system of software that can apply `mmap()` in order to backup data (e.g., array) to a file. Then, use `mmap()` to restore the system from the backup data.

- `mmap_memory.c`: this program demonstrates how `mmap()` can produce a memory page for the process, instead of mapping to a file. As a matter of fact, `malloc()` calls `mmap()` when the allocation size is bigger than 128KB ([reference](http://man7.org/linux/man-pages/man3/malloc.3.html#NOTES)).
