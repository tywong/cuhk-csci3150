# Summary

- `suicide.c`

  This is a simple program that demonstrates the use of the `kill()` system call.

  The process which runs this program will terminate itself after a random period of time. In addition, the program can use the call `raise()` instead of `kill()` when the process sends any signals to herself.

- `handle_int.c`

  This program demonstrates the use of the `signal()` in order to handle the signal `SIGINT`.

- `break_sleep.c`

  This program demonstrates that `sleep()` is not a re-entrant call. The `sleep()` call will be interrupted.

- `many_signal.c`

  This program demonstrates the fact that non-realtime signals, such as `SIGQUIT` and `SIGINT`, is not countable.

  In this example, the program fires 10 `SIGQUIT` in a row. However, the corresponding signal handler will only be triggered once.

- `segv.c`

  This program is an example in handling the segmentation fault signal `SIGSEGV`.

- `pause.c`

  This program demonstrates that the `pause()` call is interrupted when any signal is handled by a user-defined handler.

- `infinite_loop.c`

  This program is an infinite loop. Nevertheless, we set up a control variable that can be updated within the signal handler. Eventually, the program can terminate gracefully using `SIGINT`.

- `alarm.c` and `alarm_fgets.c`

  This first program is a simple demonstration of the use of `alarm()`. The second program demonstrates the use of `alarm(0)` in order to cancel the previous `alarm()` call.
