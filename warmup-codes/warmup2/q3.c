#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
   if(fork() == 0){
       execl("./alice", NULL);
       return 0;
   }
   wait(NULL);
   if(fork() == 0){
       execl("./bob", NULL);
       return 0;
   }
   wait(NULL);
   return 0;
}
