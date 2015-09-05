# CSCI 3150 Example Archive

This archive contains all the examples used in the lectures of [CSCI 3150](http://course.cse.cuhk.edu.hk/~csci3150).

## Compilation

You are recommended to compile and run the examples on Intel-based, Linux system (no matter it is virtual or not).

Start a terminal and `cd` to any directories in this archive. Then, run:

```
make
```

Note: make sure you have installed `gcc` and `make`. If not, please do so, e.g., in Ubuntu:

```
sudo apt-get install build-essential
```

## Chapter 2 - Process Management

This chapter is divided into six parts:

  1. Basic Process Management.
  - Process and Kernel.
  - POSIX Signals.
  - Process Scheduling.
  - Interprocess Communication.
  - POSIX threads.

## Chapter 3 - File Systems

In this chapter, we will first explain file system's behavior provided by the GNU C library, as well as the role of the linux kernel. Then, we will look in the on-disk layout of a file system.

  1. File Systems from a Programmer's Perspective.
  - File System Layout (FAT 32)

## Chapter 4 - Memory Management

This chapter is about memory management. First, we discover the memory alignment & allocation on the user-space side. Then, we teach what is virtual memory & paging.

1. User-Space Memory of a Process
- System-Level Memory Management
