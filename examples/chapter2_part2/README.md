# Summary



- `time_example.c` illustrates how the `printf()`` calls consume extra user and system time although the number of iterations is the same.

 Running the example without `printf()` calls:
 ```
 time ./time_example 0

 real  0m0.006s
 user  0m0.004s
 sys   0m0.001s
 ```

 Running the example with `printf()` calls:
 ```
 time ./time_example 1

 real  0m3.479s
 user  0m0.651s
 sys   0m0.728s
  ```

- `printf_example_fast.c` & `printf_example_slow.c`

  The two programs together demonstrate the fact that the number of `printf()` calls changes the running time.

  The following is an example that shows the differences in the running time of difference executions of the two programs:

  ```
  time ./print_example_slow

  real  0m0.166s
  user  0m0.017s
  sys   0m0.068s
  ```

  ```
  time ./printf_example_fast

  real  0m0.102s
  user  0m0.003s
  sys   0m0.048s
  ```

- `zombie.c` produces zombie process on purpose:

  1. Open two terminals on the same machine.

  2. **Terminal 1**: Run `zombie`. Note that `1234` is an example PID.

    ```
    $ ./zombie
    Look at the status of the process 1234
    ```

  3. **Termainl 2**: Inspect the status of the process 1234. The state of the process is `Z` (or `Z+`), meaning that it is a zombie process.

    **Explanation**. The parent process is blocked and did not run the `wait` system call. Therefore, when the child process is terminated, it is in a zombie state.

    ```
    $ ps -l -p 1234
    ...... Z .....
    ```

  4. **Termainal 1**: Press `Enter` and the parent process will invoke the system call `wait`.

  5. **Terminal 2**: Run `ps` again and you would no longer find the zombie process. This is the result of the `wait` system call reaping the zombie.

  6. **Terminal 1**: Press `Enter` and the parent process terminates.

---
By the way, the `ps` command may return the following set of states:

| State | Description |
|:----- | ----------- |
| `R`   | Running     |
| `S`   | Sleeping or waiting for CPU |
| `T`   | Stopped or suspended |
| `Z`   | Zombie |
