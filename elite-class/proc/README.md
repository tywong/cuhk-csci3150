# Implementing Linux Kernel Modules

Don't feel bad. It is normal to start implementing LKMs from boilerplate codes. We have two things to finish in this workshop.

## Task 1: /proc/mole

This file is copied from `[kernel source]/fs/proc/version.c`. The kernel module creates a new "*file*" under the `/proc` pseudo filesystem, and the path of the new entry is `/proc/mole`.

This LKM is to print data out only. You have two sub-tasks:

  - **Sub-Task A**.  Output a hard-coded message when the user reads from `/proc/mole`
    ```
    $ cat /proc/mole
    hello world
    $
    ```

  - **Sub-Task B**. Update your code from Task A and output the current `jiffies` value when the user reads from `/proc/mole`.
    ```
    $ cat /proc/mole
    1234567890   # older jiffies value
    $ cat /proc/mole
    1234568709   # more recent jiffies value
    $
    ```

## Task 2: /proc/buffer_test

This buffer test code is copied from "*The Linux Documentation Project*" (tldp). The original code allows you to do the following:
```
$ echo "hello mole" > /proc/buffer_test
$ cat /proc/buffer_test
hello mole
$
```

Now, you can going to add the **mutual exclusion** access control to `/proc/buffer_test`. That means:
  - In Terminal 1, the process `cat` has opened the file `/proc/buffer_test`.
  ```
  ## Terminal 1 ##
  $ cat > /proc/buffer_test
  _        <-- running waiting for data from STDIN
  ```
  - In Terminal 2, another process `cat` will be blocked when reading / writing to the buffer:
  ```
  ## Terminal 2 ##
  $ cat /proc/buffer_test
  _        <-- Blocked!  Will release when Terminal 1 releases the lock.
  ```
  
  ```
  ## Terminal 3 ##
  $ echo "a quick brown fox jumps over a lazy dog" > /proc/buffer_test
  _        <-- Blocked!  Will release when Terminal 1 releases the lock.
  ```

You have two sub-tasks:

  - **Sub-Task A**.  Using the `spinlock` API inside the kernel to fulfill this task. Remember, you need to enable **two CPUs in your VM**. **Try with one CPU at your own risk**.

  - **Sub-Task B**. Using the `semaphore` API inside the kernel to fulfill this task.

## Compilation and execution

In the provided `Makefile`, I have encoded the compilation targets. To compile:
```
# make
```

To install the kernel modules:
```
# insmod proc_mole.ko    <-- run as the remove_proc_entry
# insmod buffer_test.ko
# lsmod
Module                  Size  Used by
buffer_test             3798  0
proc_mole               1148  0
# _
```

Then, you can access the new entries in `/proc`:
```
# cat /proc/mole
......
# cat /proc/buffer_test
......
# _
```

To remove the kernel modules:
```
# rmmod proc_mole.ko
# rmmod buffer_test.ko
# lsmod
Module                  Size  Used by     <-- no modules in my Gentoo box
# _
```
