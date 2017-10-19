# LinkedListRawPointers
This is LinkedList implementation which is using raw pointers. <br/>
Please be aware that this implementation violates the [CppCoreGuidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-raii) <br/>

Lets run the tests to see if the implementation passes my acceptance tests,
how fast the tests executes and it leaks any memory.

## Tools
* acceptance tests:         linked_list_tests.h
* measure execution time:   chrono
* memory leaks:             valgrind

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
==14279== Memcheck, a memory error detector
==14279== Copyright (C) 2002-2015, and GNU GPL\'d, by Julian Seward et al.
==14279== Using Valgrind-3.12.0 and LibVEX; rerun with -h for copyright info
==14279== Command: ./main.out
==14279==

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


Execution time: 5479 ms

==14279==
==14279== HEAP SUMMARY:
==14279==     in use at exit: 0 bytes in 0 blocks
==14279==   total heap usage: 31,735 allocs, 31,735 frees, 1,115,638 bytes allocated
==14279==
==14279== All heap blocks were freed -- no leaks are possible
==14279==
==14279== For counts of detected and suppressed errors, rerun with: -v
==14279== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Comments
TODO
