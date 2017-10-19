# BadLinkedListRawPointers
This is LinkedList implementation which is using raw pointers but that manages
memory incorrectly e.g, when a Node is deleted from the List it is not deleted
from the free-store correctly (heap). <br/>

It should be viewed as an example how NOT to implement a LinkedList in Cpp. <br/>

Please be aware that this implementation violates the [CppCoreGuidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-raii) <br/>

Lets run the tests to see if the implementation passes my acceptance tests,
how fast the tests executes and it leaks any memory.

## Tools
* Acceptance tests:         linked_list_tests.h
* Measure execution time:   chrono
* Memory leaks:             valgrind

## Notes
The exact measured execution time should be not taken to seriously because
it depends of all stuff such as:
  * Operating System
  * Cache
  * Compiler
  * How many processes are running
  * etc....

However, to achieve more accurate measurements it the measurements should be
performed many times and calculate the average

But for this purpose use the execution time to compare the implementations
very roughly i.e. if there differ in several magnitudes.

## Result
```bash
==14542== Memcheck, a memory error detector
==14542== Copyright (C) 2002-2015, and GNU GPL\'d, by Julian Seward et al.
==14542== Using Valgrind-3.12.0 and LibVEX; rerun with -h for copyright info
==14542== Command: ./main.out
==14542==

######################################
STARTING TESTS

test_simple_empty
test_size_empty
test_size
test_addlast_contains
test_addfirst_contains
test_contains_empty
test_insert_removeFirst_to_empty
test_insert_removeLast_to_empty
test_insert_remove_to_empty_random
test_remove_on_empty
test_removeLast_on_empty
test_removeFirst_on_empty
test_add_remove_contains_n_2
test_add_remove_contains_n_3
test_get_n_elems_1
test_get_n_elems_2
test_get_n_elems_3
test_get_n_elems_4
test_get_n_elems_5
test_get_n_elems_6
test_get_invalid_idx
test_add_n_elems_clear
test_add_at_pos_n_1
test_add_at_pos_n_2
test_add_at_pos_n_3
test_add_at_pos_n_4
test_add_at_pos_n_5
test_add_invalid_index

TESTS PASSED!!!
######################################


Execution time: 5963 ms

==14542==
==14542== HEAP SUMMARY:
==14542==     in use at exit: 313,508 bytes in 13,058 blocks
==14542==   total heap usage: 28,951 allocs, 15,893 frees, 1,022,854 bytes allocated
==14542==
==14542== 120 (24 direct, 96 indirect) bytes in 1 blocks are definitely lost in loss record 9 of 32
==14542==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14542==    by 0x4051AC: LinkedList<int>::addLast(int const&) (linked_list.h:145)
==14542==    by 0x4025D0: LListTests::(anonymous namespace)::test_insert_removeFirst_to_empty() (linked_list_tests.h:251)
==14542==    by 0x4018CF: LListTests::(anonymous namespace)::run() (linked_list_tests.h:420)
==14542==    by 0x4017AC: main (main.cpp:10)
==14542==
==14542== 120 (24 direct, 96 indirect) bytes in 1 blocks are definitely lost in loss record 10 of 32
==14542==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14542==    by 0x4088CC: LinkedList<int>::addFirst(int const&) (linked_list.h:133)
==14542==    by 0x4027E0: LListTests::(anonymous namespace)::test_insert_removeLast_to_empty() (linked_list_tests.h:264)
==14542==    by 0x4018DA: LListTests::(anonymous namespace)::run() (linked_list_tests.h:421)
==14542==    by 0x4017AC: main (main.cpp:10)
==14542==
==14542== 144 (24 direct, 120 indirect) bytes in 1 blocks are definitely lost in loss record 11 of 32
==14542==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14542==    by 0x4051AC: LinkedList<int>::addLast(int const&) (linked_list.h:145)
==14542==    by 0x4036FF: LListTests::(anonymous namespace)::test_get_n_elems() (linked_list_tests.h:112)
==14542==    by 0x40191C: LListTests::(anonymous namespace)::run() (linked_list_tests.h:430)
==14542==    by 0x4017AC: main (main.cpp:10)
==14542==
==14542== 260 (48 direct, 212 indirect) bytes in 1 blocks are definitely lost in loss record 12 of 32
==14542==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14542==    by 0x40C9CC: LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::addFirst(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) (linked_list.h:133)
==14542==    by 0x404008: LListTests::(anonymous namespace)::test_add_at_pos_n() (linked_list_tests.h:59)
==14542==    by 0x40193D: LListTests::(anonymous namespace)::run() (linked_list_tests.h:434)
==14542==    by 0x4017AC: main (main.cpp:10)
==14542==
==14542== 2,400 (24 direct, 2,376 indirect) bytes in 1 blocks are definitely lost in loss record 15 of 32
==14542==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14542==    by 0x4051AC: LinkedList<int>::addLast(int const&) (linked_list.h:145)
==14542==    by 0x403B29: LListTests::(anonymous namespace)::test_get_invalid_idx() (linked_list_tests.h:131)
==14542==    by 0x401927: LListTests::(anonymous namespace)::run() (linked_list_tests.h:431)
==14542==    by 0x4017AC: main (main.cpp:10)
==14542==
==14542== 2,400 (24 direct, 2,376 indirect) bytes in 1 blocks are definitely lost in loss record 16 of 32
==14542==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14542==    by 0x4088CC: LinkedList<int>::addFirst(int const&) (linked_list.h:133)
==14542==    by 0x40C5F9: LinkedList<int>::add(int const&, unsigned int) (linked_list.h:163)
==14542==    by 0x4048D9: LListTests::(anonymous namespace)::test_add_invalid_index() (linked_list_tests.h:83)
==14542==    by 0x401948: LListTests::(anonymous namespace)::run() (linked_list_tests.h:435)
==14542==    by 0x4017AC: main (main.cpp:10)
==14542==
==14542== 11,448 (24 direct, 11,424 indirect) bytes in 1 blocks are definitely lost in loss record 23 of 32
==14542==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14542==    by 0x4051AC: LinkedList<int>::addLast(int const&) (linked_list.h:145)
==14542==    by 0x401C50: LListTests::(anonymous namespace)::test_size() (linked_list_tests.h:383)
==14542==    by 0x4018A3: LListTests::(anonymous namespace)::run() (linked_list_tests.h:414)
==14542==    by 0x4017AC: main (main.cpp:10)
==14542==
==14542== 11,448 (24 direct, 11,424 indirect) bytes in 1 blocks are definitely lost in loss record 24 of 32
==14542==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14542==    by 0x4051AC: LinkedList<int>::addLast(int const&) (linked_list.h:145)
==14542==    by 0x401EA7: LListTests::(anonymous namespace)::test_addlast_contains() (linked_list_tests.h:324)
==14542==    by 0x4018AE: LListTests::(anonymous namespace)::run() (linked_list_tests.h:416)
==14542==    by 0x4017AC: main (main.cpp:10)
==14542==
==14542== 11,448 (24 direct, 11,424 indirect) bytes in 1 blocks are definitely lost in loss record 25 of 32
==14542==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14542==    by 0x4088CC: LinkedList<int>::addFirst(int const&) (linked_list.h:133)
==14542==    by 0x4021EE: LListTests::(anonymous namespace)::test_addfirst_contains() (linked_list_tests.h:352)
==14542==    by 0x4018B9: LListTests::(anonymous namespace)::run() (linked_list_tests.h:417)
==14542==    by 0x4017AC: main (main.cpp:10)
==14542==
==14542== 11,448 (24 direct, 11,424 indirect) bytes in 1 blocks are definitely lost in loss record 26 of 32
==14542==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14542==    by 0x4088CC: LinkedList<int>::addFirst(int const&) (linked_list.h:133)
==14542==    by 0x402AD3: LListTests::(anonymous namespace)::test_insert_remove_to_empty_random() (linked_list_tests.h:290)
==14542==    by 0x4018E5: LListTests::(anonymous namespace)::run() (linked_list_tests.h:422)
==14542==    by 0x4017AC: main (main.cpp:10)
==14542==
==14542== 22,272 (24 direct, 22,248 indirect) bytes in 1 blocks are definitely lost in loss record 27 of 32
==14542==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14542==    by 0x4088CC: LinkedList<int>::addFirst(int const&) (linked_list.h:133)
==14542==    by 0x403C97: LListTests::(anonymous namespace)::test_add_n_elems_clear() (linked_list_tests.h:100)
==14542==    by 0x401932: LListTests::(anonymous namespace)::run() (linked_list_tests.h:432)
==14542==    by 0x4017AC: main (main.cpp:10)
==14542==
==14542== 45,864 (28,632 direct, 17,232 indirect) bytes in 1,193 blocks are definitely lost in loss record 28 of 32
==14542==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14542==    by 0x408932: LinkedList<int>::addFirst(int const&) (linked_list.h:136)
==14542==    by 0x403240: LListTests::(anonymous namespace)::test_add_remove_contains_n() (linked_list_tests.h:170)
==14542==    by 0x401911: LListTests::(anonymous namespace)::run() (linked_list_tests.h:428)
==14542==    by 0x4017AC: main (main.cpp:10)
==14542==
==14542== 48,168 (28,704 direct, 19,464 indirect) bytes in 1,196 blocks are definitely lost in loss record 29 of 32
==14542==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14542==    by 0x405212: LinkedList<int>::addLast(int const&) (linked_list.h:148)
==14542==    by 0x40321E: LListTests::(anonymous namespace)::test_add_remove_contains_n() (linked_list_tests.h:167)
==14542==    by 0x401911: LListTests::(anonymous namespace)::run() (linked_list_tests.h:428)
==14542==    by 0x4017AC: main (main.cpp:10)
==14542==
==14542== 145,968 (24 direct, 145,944 indirect) bytes in 1 blocks are definitely lost in loss record 32 of 32
==14542==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14542==    by 0x4088CC: LinkedList<int>::addFirst(int const&) (linked_list.h:133)
==14542==    by 0x403240: LListTests::(anonymous namespace)::test_add_remove_contains_n() (linked_list_tests.h:170)
==14542==    by 0x401911: LListTests::(anonymous namespace)::run() (linked_list_tests.h:428)
==14542==    by 0x4017AC: main (main.cpp:10)
==14542==
==14542== LEAK SUMMARY:
==14542==    definitely lost: 57,648 bytes in 2,401 blocks
==14542==    indirectly lost: 255,860 bytes in 10,657 blocks
==14542==      possibly lost: 0 bytes in 0 blocks
==14542==    still reachable: 0 bytes in 0 blocks
==14542==         suppressed: 0 bytes in 0 blocks
==14542==
==14542== For counts of detected and suppressed errors, rerun with: -v
==14542== ERROR SUMMARY: 14 errors from 14 contexts (suppressed: 0 from 0)
```

## Comments
TODO
