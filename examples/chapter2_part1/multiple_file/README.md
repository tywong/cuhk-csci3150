# Explanation

This example demonstrates how to compile a program with multiple source files.

- `add_int.c` implements a function `add_int()` which adds two numbers.

- `multi_int.c` implements a function `multi_int()` which multiply functions. To make this example to a funny one, I implement **multiplication using addition**. Then, `multi_int()` has to include the implementation of `add_int()`.

- `int_header.h` includes the declarations of both `add_int()` and `multi_int()`.

- `main.c` includes the main function that uses both `add_int()` and `multi_int()`.

- Last but not least, the `Makefile` is most interesting file in this directory. It demonstrates how defines dependencies. E.g.,

  ```
  OBJ=add_int.o multi_int.o main.o
  main: ${OBJ}
  ```
  - The second line defines the files that the compilation of the file `main` depend on.
  - That is `main` depends on the three listed `.o` files.
  - Note that `make` defines an implicit rule to compile `.o` files, which is:
    ```
    $(CC) $(CFLAGS) -c file.c -o file.o
    ```
