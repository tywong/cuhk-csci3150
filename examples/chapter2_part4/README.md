# Summary

The program `reparent_example.c` demonstrates that re-paraent operation in Unix-like system. When the parent process dies before the child process dies, the child process finds her parent becomes the first process:
  - `/sbin/init` in Linux;
  - `/sbin/launchd` in Mac OSX.
