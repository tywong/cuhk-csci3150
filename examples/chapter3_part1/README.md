# Summary

- `fileno.c` shows the relationship between the `FILE` structure  and the file descriptor.

- `full_buf.c`, `line_buf.c`, and `no_buf.c`. This set of programs changes the buffering mode of the standard output stream to **full buffer mode**, **line buffer mode**, and **no buffer mode**, respectively.

- `fork.c` is a mind-blown demonstration.

  ```c
  printf("Hello");
  fork();
  printf("\n");
  ```
  gives the following output:
  ```
  Hello
  Hello
  ```
  The explanation is kept as a challenge to the readers.

- `read_eof.c` & `getchar_eof.c`. This pair of programs is to emphasize that `EOF` is only a pre-defined constant!

  You cannot find any `EOF` characters using the `read()` system call, and is illustrated by the program `read_eof.c`.

  Hence, the return value `EOF` from `getchar()`, shown in `getchar_eof.c`, is only an **indicator** of the end of the standard input stream.

- `simple_ls.c` uses `opendir()` and `readdir()` library calls to open and to read the current directory, respectively.
