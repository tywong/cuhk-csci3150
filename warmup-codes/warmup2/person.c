#include <stdio.h>
#include <string.h>

int person(char* argv0, char* s){
   char * t = strrchr(argv0, (int)'/');
   t = (t == NULL)? argv0 : t+1;
   return strcmp(t, s) == 0;
}

int main(int argc, char* argv[]){
   if(person(argv[0], "bob"))
       printf("I am Bob.\n");
   if(person(argv[0], "alice"))
       printf("I am Alice.\n");
   return 0;
}

