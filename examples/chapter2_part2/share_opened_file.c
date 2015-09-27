#include <stdio.h>  // fopen(), fprintf()
#include <stdlib.h> // rand()
#include <unistd.h> // fork(), sleep(), getpid()

int main(void) {
  int pid;
  int i;
  FILE *fp = fopen("data.txt", "w");

  pid = fork();
  for(i = 0; i < 10; i++) {
    fprintf(fp, "%d %d\n", getpid(), i);
    fflush(fp);
    sleep(rand() % 2);
  }
  fclose(fp);

  if(pid)
    wait(NULL);

  return 0;
}
