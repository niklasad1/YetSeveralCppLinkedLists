# LinkedListRawPointers
This is LinkedList implementation which is using SmartPointer or more
specifically shared pointers which are "reference counted"  <br/>

This is a poor implementation that aims to illustrate that SmartPointers can
leak memory if they are not used correctly and also end-up in poor performance.
Generally, if it is possible prefer using unique pointers over shared pointers.
But in this case it is not possible because we have a double linked lists which
creates a cyclic dependency.

 This is all I want to say and lets dig into the naive implementation and
 run the tests to see if the implementation passes my acceptance tests,
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
==14668== Memcheck, a memory error detector
==14668== Copyright (C) 2002-2015, and GNU GPL\'d, by Julian Seward et al.
==14668== Using Valgrind-3.12.0 and LibVEX; rerun with -h for copyright info
==14668== Command: ./main.out
==14668==

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


Execution time: 46515 ms

==14668==
==14668== HEAP SUMMARY:
==14668==     in use at exit: 487,788 bytes in 8,709 blocks
==14668==   total heap usage: 29,551 allocs, 20,842 frees, 1,467,572 bytes allocated
==14668==
==14668== 336 (56 direct, 280 indirect) bytes in 1 blocks are definitely lost in loss record 7 of 24
==14668==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14668==    by 0x4074C0: __gnu_cxx::new_allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >::allocate(unsigned long, void const*) (new_allocator.h:104)
==14668==    by 0x40742B: std::allocator_traits<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > >::allocate(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >&, unsigned long) (alloc_traits.h:436)
==14668==    by 0x4071E4: std::__allocated_ptr<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > > std::__allocate_guarded<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > >(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >&) (allocated_ptr.h:103)
==14668==    by 0x406FD2: std::__shared_count<(__gnu_cxx::_Lock_policy)2>::__shared_count<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, LinkedList<int>::Node*, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:613)
==14668==    by 0x406F2E: std::__shared_ptr<LinkedList<int>::Node, (__gnu_cxx::_Lock_policy)2>::__shared_ptr<std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:1099)
==14668==    by 0x406EA6: std::shared_ptr<LinkedList<int>::Node>::shared_ptr<std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:319)
==14668==    by 0x406DC8: std::shared_ptr<LinkedList<int>::Node> std::allocate_shared<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:619)
==14668==    by 0x406BB9: std::shared_ptr<LinkedList<int>::Node> std::make_shared<LinkedList<int>::Node, int const&, decltype(nullptr), decltype(nullptr)>(int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:635)
==14668==    by 0x405B67: LinkedList<int>::addLast(int const&) (linked_list.h:178)
==14668==    by 0x403ADB: LListTests::(anonymous namespace)::test_get_n_elems() (linked_list_tests.h:112)
==14668==    by 0x401A9C: LListTests::(anonymous namespace)::run() (linked_list_tests.h:430)
==14668==
==14668== 420 (80 direct, 340 indirect) bytes in 1 blocks are definitely lost in loss record 8 of 24
==14668==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14668==    by 0x412D40: __gnu_cxx::new_allocator<std::_Sp_counted_ptr_inplace<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node, std::allocator<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node>, (__gnu_cxx::_Lock_policy)2> >::allocate(unsigned long, void const*) (new_allocator.h:104)
==14668==    by 0x412CAB: std::allocator_traits<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node, std::allocator<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node>, (__gnu_cxx::_Lock_policy)2> > >::allocate(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node, std::allocator<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node>, (__gnu_cxx::_Lock_policy)2> >&, unsigned long) (alloc_traits.h:436)
==14668==    by 0x412A64: std::__allocated_ptr<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node, std::allocator<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node>, (__gnu_cxx::_Lock_policy)2> > > std::__allocate_guarded<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node, std::allocator<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node>, (__gnu_cxx::_Lock_policy)2> > >(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node, std::allocator<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node>, (__gnu_cxx::_Lock_policy)2> >&) (allocated_ptr.h:103)
==14668==    by 0x4128C2: std::__shared_count<(__gnu_cxx::_Lock_policy)2>::__shared_count<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node, std::allocator<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node>, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node*, std::allocator<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node> const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:613)
==14668==    by 0x41281E: std::__shared_ptr<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node, (__gnu_cxx::_Lock_policy)2>::__shared_ptr<std::allocator<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node>, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node> const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:1099)
==14668==    by 0x412796: std::shared_ptr<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node>::shared_ptr<std::allocator<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node>, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node> const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:319)
==14668==    by 0x4126D8: std::shared_ptr<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node> std::allocate_shared<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node, std::allocator<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node>, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, decltype(nullptr), decltype(nullptr)>(std::allocator<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node> const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:619)
==14668==    by 0x412599: std::shared_ptr<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node> std::make_shared<LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Node, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, decltype(nullptr), decltype(nullptr)>(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:635)
==14668==    by 0x411917: LinkedList<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::addFirst(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) (linked_list.h:165)
==14668==    by 0x404458: LListTests::(anonymous namespace)::test_add_at_pos_n() (linked_list_tests.h:59)
==14668==    by 0x401ABD: LListTests::(anonymous namespace)::run() (linked_list_tests.h:434)
==14668==
==14668== 5,600 (56 direct, 5,544 indirect) bytes in 1 blocks are definitely lost in loss record 11 of 24
==14668==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14668==    by 0x4074C0: __gnu_cxx::new_allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >::allocate(unsigned long, void const*) (new_allocator.h:104)
==14668==    by 0x40742B: std::allocator_traits<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > >::allocate(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >&, unsigned long) (alloc_traits.h:436)
==14668==    by 0x4071E4: std::__allocated_ptr<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > > std::__allocate_guarded<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > >(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >&) (allocated_ptr.h:103)
==14668==    by 0x406FD2: std::__shared_count<(__gnu_cxx::_Lock_policy)2>::__shared_count<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, LinkedList<int>::Node*, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:613)
==14668==    by 0x406F2E: std::__shared_ptr<LinkedList<int>::Node, (__gnu_cxx::_Lock_policy)2>::__shared_ptr<std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:1099)
==14668==    by 0x406EA6: std::shared_ptr<LinkedList<int>::Node>::shared_ptr<std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:319)
==14668==    by 0x406DC8: std::shared_ptr<LinkedList<int>::Node> std::allocate_shared<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:619)
==14668==    by 0x406BB9: std::shared_ptr<LinkedList<int>::Node> std::make_shared<LinkedList<int>::Node, int const&, decltype(nullptr), decltype(nullptr)>(int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:635)
==14668==    by 0x405B67: LinkedList<int>::addLast(int const&) (linked_list.h:178)
==14668==    by 0x403F19: LListTests::(anonymous namespace)::test_get_invalid_idx() (linked_list_tests.h:131)
==14668==    by 0x401AA7: LListTests::(anonymous namespace)::run() (linked_list_tests.h:431)
==14668==
==14668== 5,600 (56 direct, 5,544 indirect) bytes in 1 blocks are definitely lost in loss record 12 of 24
==14668==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14668==    by 0x4074C0: __gnu_cxx::new_allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >::allocate(unsigned long, void const*) (new_allocator.h:104)
==14668==    by 0x40742B: std::allocator_traits<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > >::allocate(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >&, unsigned long) (alloc_traits.h:436)
==14668==    by 0x4071E4: std::__allocated_ptr<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > > std::__allocate_guarded<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > >(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >&) (allocated_ptr.h:103)
==14668==    by 0x406FD2: std::__shared_count<(__gnu_cxx::_Lock_policy)2>::__shared_count<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, LinkedList<int>::Node*, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:613)
==14668==    by 0x406F2E: std::__shared_ptr<LinkedList<int>::Node, (__gnu_cxx::_Lock_policy)2>::__shared_ptr<std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:1099)
==14668==    by 0x406EA6: std::shared_ptr<LinkedList<int>::Node>::shared_ptr<std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:319)
==14668==    by 0x406DC8: std::shared_ptr<LinkedList<int>::Node> std::allocate_shared<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:619)
==14668==    by 0x406BB9: std::shared_ptr<LinkedList<int>::Node> std::make_shared<LinkedList<int>::Node, int const&, decltype(nullptr), decltype(nullptr)>(int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:635)
==14668==    by 0x40AD57: LinkedList<int>::addFirst(int const&) (linked_list.h:165)
==14668==    by 0x410DB8: LinkedList<int>::add(int const&, unsigned int const&) (linked_list.h:140)
==14668==    by 0x404D73: LListTests::(anonymous namespace)::test_add_invalid_index() (linked_list_tests.h:83)
==14668==
==14668== 32,368 (56 direct, 32,312 indirect) bytes in 1 blocks are definitely lost in loss record 18 of 24
==14668==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14668==    by 0x4074C0: __gnu_cxx::new_allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >::allocate(unsigned long, void const*) (new_allocator.h:104)
==14668==    by 0x40742B: std::allocator_traits<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > >::allocate(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >&, unsigned long) (alloc_traits.h:436)
==14668==    by 0x4071E4: std::__allocated_ptr<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > > std::__allocate_guarded<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > >(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >&) (allocated_ptr.h:103)
==14668==    by 0x406FD2: std::__shared_count<(__gnu_cxx::_Lock_policy)2>::__shared_count<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, LinkedList<int>::Node*, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:613)
==14668==    by 0x406F2E: std::__shared_ptr<LinkedList<int>::Node, (__gnu_cxx::_Lock_policy)2>::__shared_ptr<std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:1099)
==14668==    by 0x406EA6: std::shared_ptr<LinkedList<int>::Node>::shared_ptr<std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:319)
==14668==    by 0x406DC8: std::shared_ptr<LinkedList<int>::Node> std::allocate_shared<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:619)
==14668==    by 0x406BB9: std::shared_ptr<LinkedList<int>::Node> std::make_shared<LinkedList<int>::Node, int const&, decltype(nullptr), decltype(nullptr)>(int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:635)
==14668==    by 0x405B67: LinkedList<int>::addLast(int const&) (linked_list.h:178)
==14668==    by 0x401E15: LListTests::(anonymous namespace)::test_size() (linked_list_tests.h:383)
==14668==    by 0x401A23: LListTests::(anonymous namespace)::run() (linked_list_tests.h:414)
==14668==
==14668== 32,368 (56 direct, 32,312 indirect) bytes in 1 blocks are definitely lost in loss record 19 of 24
==14668==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14668==    by 0x4074C0: __gnu_cxx::new_allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >::allocate(unsigned long, void const*) (new_allocator.h:104)
==14668==    by 0x40742B: std::allocator_traits<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > >::allocate(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >&, unsigned long) (alloc_traits.h:436)
==14668==    by 0x4071E4: std::__allocated_ptr<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > > std::__allocate_guarded<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > >(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >&) (allocated_ptr.h:103)
==14668==    by 0x406FD2: std::__shared_count<(__gnu_cxx::_Lock_policy)2>::__shared_count<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, LinkedList<int>::Node*, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:613)
==14668==    by 0x406F2E: std::__shared_ptr<LinkedList<int>::Node, (__gnu_cxx::_Lock_policy)2>::__shared_ptr<std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:1099)
==14668==    by 0x406EA6: std::shared_ptr<LinkedList<int>::Node>::shared_ptr<std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:319)
==14668==    by 0x406DC8: std::shared_ptr<LinkedList<int>::Node> std::allocate_shared<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:619)
==14668==    by 0x406BB9: std::shared_ptr<LinkedList<int>::Node> std::make_shared<LinkedList<int>::Node, int const&, decltype(nullptr), decltype(nullptr)>(int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:635)
==14668==    by 0x405B67: LinkedList<int>::addLast(int const&) (linked_list.h:178)
==14668==    by 0x402092: LListTests::(anonymous namespace)::test_addlast_contains() (linked_list_tests.h:324)
==14668==    by 0x401A2E: LListTests::(anonymous namespace)::run() (linked_list_tests.h:416)
==14668==
==14668== 32,368 (56 direct, 32,312 indirect) bytes in 1 blocks are definitely lost in loss record 20 of 24
==14668==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14668==    by 0x4074C0: __gnu_cxx::new_allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >::allocate(unsigned long, void const*) (new_allocator.h:104)
==14668==    by 0x40742B: std::allocator_traits<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > >::allocate(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >&, unsigned long) (alloc_traits.h:436)
==14668==    by 0x4071E4: std::__allocated_ptr<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > > std::__allocate_guarded<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > >(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >&) (allocated_ptr.h:103)
==14668==    by 0x406FD2: std::__shared_count<(__gnu_cxx::_Lock_policy)2>::__shared_count<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, LinkedList<int>::Node*, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:613)
==14668==    by 0x406F2E: std::__shared_ptr<LinkedList<int>::Node, (__gnu_cxx::_Lock_policy)2>::__shared_ptr<std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:1099)
==14668==    by 0x406EA6: std::shared_ptr<LinkedList<int>::Node>::shared_ptr<std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:319)
==14668==    by 0x406DC8: std::shared_ptr<LinkedList<int>::Node> std::allocate_shared<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:619)
==14668==    by 0x406BB9: std::shared_ptr<LinkedList<int>::Node> std::make_shared<LinkedList<int>::Node, int const&, decltype(nullptr), decltype(nullptr)>(int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:635)
==14668==    by 0x40AD57: LinkedList<int>::addFirst(int const&) (linked_list.h:165)
==14668==    by 0x40241C: LListTests::(anonymous namespace)::test_addfirst_contains() (linked_list_tests.h:352)
==14668==    by 0x401A39: LListTests::(anonymous namespace)::run() (linked_list_tests.h:417)
==14668==
==14668== 39,256 (56 direct, 39,200 indirect) bytes in 1 blocks are definitely lost in loss record 21 of 24
==14668==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14668==    by 0x4074C0: __gnu_cxx::new_allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >::allocate(unsigned long, void const*) (new_allocator.h:104)
==14668==    by 0x40742B: std::allocator_traits<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > >::allocate(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >&, unsigned long) (alloc_traits.h:436)
==14668==    by 0x4071E4: std::__allocated_ptr<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > > std::__allocate_guarded<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > >(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >&) (allocated_ptr.h:103)
==14668==    by 0x406FD2: std::__shared_count<(__gnu_cxx::_Lock_policy)2>::__shared_count<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, LinkedList<int>::Node*, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:613)
==14668==    by 0x406F2E: std::__shared_ptr<LinkedList<int>::Node, (__gnu_cxx::_Lock_policy)2>::__shared_ptr<std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:1099)
==14668==    by 0x406EA6: std::shared_ptr<LinkedList<int>::Node>::shared_ptr<std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:319)
==14668==    by 0x406DC8: std::shared_ptr<LinkedList<int>::Node> std::allocate_shared<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:619)
==14668==    by 0x406BB9: std::shared_ptr<LinkedList<int>::Node> std::make_shared<LinkedList<int>::Node, int const&, decltype(nullptr), decltype(nullptr)>(int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:635)
==14668==    by 0x40AD57: LinkedList<int>::addFirst(int const&) (linked_list.h:165)
==14668==    by 0x4040CA: LListTests::(anonymous namespace)::test_add_n_elems_clear() (linked_list_tests.h:100)
==14668==    by 0x401AB2: LListTests::(anonymous namespace)::run() (linked_list_tests.h:432)
==14668==
==14668== 339,472 (56 direct, 339,416 indirect) bytes in 1 blocks are definitely lost in loss record 24 of 24
==14668==    at 0x4C2E19F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==14668==    by 0x4074C0: __gnu_cxx::new_allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >::allocate(unsigned long, void const*) (new_allocator.h:104)
==14668==    by 0x40742B: std::allocator_traits<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > >::allocate(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >&, unsigned long) (alloc_traits.h:436)
==14668==    by 0x4071E4: std::__allocated_ptr<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > > std::__allocate_guarded<std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> > >(std::allocator<std::_Sp_counted_ptr_inplace<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, (__gnu_cxx::_Lock_policy)2> >&) (allocated_ptr.h:103)
==14668==    by 0x406FD2: std::__shared_count<(__gnu_cxx::_Lock_policy)2>::__shared_count<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, LinkedList<int>::Node*, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:613)
==14668==    by 0x406F2E: std::__shared_ptr<LinkedList<int>::Node, (__gnu_cxx::_Lock_policy)2>::__shared_ptr<std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr_base.h:1099)
==14668==    by 0x406EA6: std::shared_ptr<LinkedList<int>::Node>::shared_ptr<std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::_Sp_make_shared_tag, std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:319)
==14668==    by 0x406DC8: std::shared_ptr<LinkedList<int>::Node> std::allocate_shared<LinkedList<int>::Node, std::allocator<LinkedList<int>::Node>, int const&, decltype(nullptr), decltype(nullptr)>(std::allocator<LinkedList<int>::Node> const&, int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:619)
==14668==    by 0x406BB9: std::shared_ptr<LinkedList<int>::Node> std::make_shared<LinkedList<int>::Node, int const&, decltype(nullptr), decltype(nullptr)>(int const&, decltype(nullptr)&&, decltype(nullptr)&&) (shared_ptr.h:635)
==14668==    by 0x405B67: LinkedList<int>::addLast(int const&) (linked_list.h:178)
==14668==    by 0x4035D7: LListTests::(anonymous namespace)::test_add_remove_contains_n() (linked_list_tests.h:167)
==14668==    by 0x401A91: LListTests::(anonymous namespace)::run() (linked_list_tests.h:428)
==14668==
==14668== LEAK SUMMARY:
==14668==    definitely lost: 528 bytes in 9 blocks
==14668==    indirectly lost: 487,260 bytes in 8,700 blocks
==14668==      possibly lost: 0 bytes in 0 blocks
==14668==    still reachable: 0 bytes in 0 blocks
==14668==         suppressed: 0 bytes in 0 blocks
==14668==
==14668== For counts of detected and suppressed errors, rerun with: -v
==14668== ERROR SUMMARY: 9 errors from 9 contexts (suppressed: 0 from 0)

```
## Comments
TODO
