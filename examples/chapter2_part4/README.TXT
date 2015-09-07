How to run signal_wait.c
------------------------

- Open 2 terminals;
- On the 1st terminal, type:
    watch --interval=1 "ps -f -C signal_wait"
- On the 2nd terminal, type:
    ./signal_wait

You can try to comment the "wait()" statement to see what'll happen.
