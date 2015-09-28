# Summary

- `pthread_game`. It is a simple game implemented with Pthread.

- `pthread_hello_world`. It is a basic example that launches a thread to print `hello world`.

- `pthread_evil_1`. This program illustrates how a value is passed into a thread function. The value-passing mechanism is done through pointer.

  Since threads of the same process shared all memory (yes, the stack for each pthread is not private), a thread function can change the variable in the main thread.

- `pthread_evil_2`. This program illustrates the inconsistency between **the time the thread is created** and **the time the thread is running**. That is:
  ```c
  /** In main thread **/
  for(i = 0; i < 5; i++)
    pthread_create(&tid[i], NULL, do_your_job, &i);

  /** In thread function **/
  int id = *((int *) input);
  ```
  The time that the main pthread executes the `pthread_create` function **is not the same as** the time that the thread copies the value of `i` to the id` variable.

  Hence, one of the possible outcomes form this program is as follows.
  ```
  My ID number = 2
  My ID number = 3
  My ID number = 4
  My ID number = 4
  My ID number = 5
  ```  
  The above output implies two threads copy the same value of `i`.

- `pthread_evil_2sol.c`. This program is one of the possible solutions to the problematic code `pthread_evil_2.c`. The code is self-explanatory.

- `pthread_exit.c`. The `pthread_exit()` function call should be executed by the thread function. After such a call has finished executing:
  1. The calling thread should terminate.
  2. The calling thread should pass a result back to the main thread through a pointer, and `NULL` pointer means nothing would be pass back to main.
  3. The main thread can collect the result through the `pthread_join()` call.

- `pthread_mutex` demonstrates the use of `pthread_mutex` data type, as well as the `pthread_mutex_lock` and `pthread_mutex_unlock` calls.

- `pthread_producer_consumer`. This is a polished program that demonstrates the use of the following `pthread` related stuffs:
  - `pthread_cond_t` data type,
  - `pthread_cond_signal()` call,
  - `pthread_cond_wait()` call.

- `normal_strtok.c`, `pthread_strtok.c` `pthread_strtok_r.c`. The function `strtok()` is not thread-safe. By the extending the non-threaded example code `normal_strtok()`, the program `pthread_strtok()` use `strtok()` and has the thread safety problem manifested.

  Then, we have the program `pthread_strtok_r.c`, using the thread-safe function `strtok_r()`.
