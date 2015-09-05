# Summary

- `hello.c` produces `hello.out`. This demonstrates the replacement of pre-defined constants.

- `header.h` & `include.c` produce `include.out`. This demonstrates the substitution effect of the `#include` directive.

- `swap.c` produces `swap.out`. This demonstrations how a macro is expanded.

- `stupid_add` produces
  - `stupid_add_O0.s`: this assembly output demonstrates the case when optimization is turned off.
  - `stupid_add_O1.s`: this assembly output demonstrations obviously stupid codes would be optimized by the GCC compiler.
