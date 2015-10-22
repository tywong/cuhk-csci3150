# Scheduler Control

This set of codes are for demonstrating how one can control the scheduler by using the `sched_setscheduler()` system call. 

- `sys_sched_info.c`. This program dumps the information of three different scheduler classes:
  - `SCHED_FIFO`: Real-time, FIFO scheduler class;
  - `SCHED_RR`: Real-time, round robin scheduler class;
  - `SCHED_OTHER`: ordinary scheduler class.
  
- `simple_set_sched.c`. This program changes an ordinary process to a `SCHED_FIFO` process of the static proiority level 99. The command:
  ```
  sudo ./simple_set_sched 1234
  ```
  will change the process of PID 1234 to a `SCHED_FIFO` process of 99 priority.
  
  You should expect that the entire system will be frozen because the CPU will give it full attention toward the process 1234.
  
  Note that only **root** can change a process from an ordinary process to a real-time process.
  
- `infinite_loop.c`. Actually, it is a **finite loop** :)

  It has three different levels of CPU comsumption:
  ```
  $ Usage: ./infinite_loop [1 | 2 | 3]
           1: fast; 2: slow; 3: very slow [default is 1].
  ```
