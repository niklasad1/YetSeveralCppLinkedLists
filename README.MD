# YetSeveralCppLinkedLists
I have implemented several versions of double LinkedLists in C++ to demonstrate
and learn how modern features in C++ can be used to write better code.
But also demonstrate that SmartPointers are not magic but can be useful if they
are used correctly.

## [BadLinkedListRawPointers](LinkedListRawPointers)
A very naive LinkedList implementation that never manages memory after deletion

## [LinkedListRawPointers](LinkedListRawPointers)
A fairly ok LinkedLists implementation of raw pointers that handles memory and
do not leak memory

## [LinkedListSmartPointersBad](LinkedListSmartPointerBad)
A very naive double LinkedList implementation using `shared_ptr`

## [LinkedListSmartPointers](LinkedListSmartPointers)
A double linkedlist implementation using `shared_ptr` and `weak_ptr` (WIP)

## Required Tools

### [Google Test](https://github.com/google/googletest/tree/master/googletest)
Used for unit tests

#### Installation Guide Debian
```bash
$ sudo apt update
$ sudo apt upgrade
$ sudo apt install libgtest-dev
$ sudo cp *.a /usr/lib
```

### [Clang](https://clang.llvm.org/)
Compiler and address sanitizer

#### Installation Guide Debian
``` bash
$ sudo apt update
$ sudo apt upgrade
$ sudo apt install clang
```
