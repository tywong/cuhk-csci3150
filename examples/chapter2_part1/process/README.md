# Summary

- `args.c`: this demonstrates how one can iterates through all input arguments.

  Command:
  ```
  ./args hello there
  ```
  Output:
  ```
  argv 0: ./args
  argv 1: hello
  argv 2: there
  ```

- `envp.c`: this shows the set of environment variables inherited from the shell.

  Command:
  ```
  ./envp
  ```
  Output:
  ```
  LOGNAME=tywong
  HOME=/home/tywong
  ```
  etc.

- `getpid.c`: this prints the process ID of the running process. Please try executing it multiple times to see the printed PIDs are changing.

- `fork_example_1.c`: this is the basic example of using `fork()`;

  Command:
  ```
  ./fork_example_1
  ```

  Output:
  ```
  Ready (PID = 1234)    # the original process
  My PID is 1234        # original process -> parent process
  My PID is 1235        # child process
  ```

- `fork_example_2.c`: this is another basic example of using `fork()`. The key message of this example is the **return value of `fork()`**:

  > Process Process: `fork()` returns Child's PID;
  Child Process: `fork()` returns 0;

- `exec_example.c`: this example executes the command line: `/bin/ls -l`. Please try modify the code with non-existing filenames, e.g.,

  ```
  execl("/bin/wuar", "/bin/wuar", NULL);
  ```

  Please observe what would happen.

- `system_example.c`: in case you did not use `system()` library call before, you can run and observe that what would happen.

- `system_implement_1.c`: this example demonstrates that, without the use of the `wait()` system call, one cannot control the execution order of the parent and the child processes.

- `system_implement_2.c`: this example has added the use of the `wait()` system call.
