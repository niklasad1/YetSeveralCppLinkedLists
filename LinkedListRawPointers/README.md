# LinkedListRawPointers
This is LinkedList implementation which is using raw pointers. <br/>
Please be aware that this implementation violates the [CppCoreGuidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-raii) <br/>

Lets run the tests to see if the implementation passes my acceptance tests,
how fast the tests executes and it leaks any memory.

## Tools
* acceptance tests:         linked_list_tests.h (Google Test)
* measure execution time:   Google Test
* memory leaks:             Clang Address Sanitizer

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

Also, I'm using the address sanitizer which decreases performance significantly

## Result
```bash
[==========] Running 17 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 17 tests from LinkedList
[ RUN      ] LinkedList.AddAtPositionNAndGet
[       OK ] LinkedList.AddAtPositionNAndGet (0 ms)
[ RUN      ] LinkedList.AddAtInvalidPosition
[       OK ] LinkedList.AddAtInvalidPosition (0 ms)
[ RUN      ] LinkedList.AddNElemsThenClear
[       OK ] LinkedList.AddNElemsThenClear (1 ms)
[ RUN      ] LinkedList.GetInvalidIndex
[       OK ] LinkedList.GetInvalidIndex (0 ms)
[ RUN      ] LinkedList.AddElemsAndListContains
[       OK ] LinkedList.AddElemsAndListContains (483 ms)
[ RUN      ] LinkedList.RemoveOnEmptyList
[       OK ] LinkedList.RemoveOnEmptyList (0 ms)
[ RUN      ] LinkedList.RemoveLastOnEmptyList
[       OK ] LinkedList.RemoveLastOnEmptyList (0 ms)
[ RUN      ] LinkedList.RemoveFirstOnEmptyList
[       OK ] LinkedList.RemoveFirstOnEmptyList (0 ms)
[ RUN      ] LinkedList.AddLastThenRemoveFirstUntilEmpty
[       OK ] LinkedList.AddLastThenRemoveFirstUntilEmpty (0 ms)
[ RUN      ] LinkedList.AddFirstThenRemoveLastUntilEmpty
[       OK ] LinkedList.AddFirstThenRemoveLastUntilEmpty (0 ms)
[ RUN      ] LinkedList.AddFirstOrLastThenRemoveRandom
[       OK ] LinkedList.AddFirstOrLastThenRemoveRandom (6 ms)
[ RUN      ] LinkedList.EmptyListDoesNotContain
[       OK ] LinkedList.EmptyListDoesNotContain (0 ms)
[ RUN      ] LinkedList.AddLastContains
[       OK ] LinkedList.AddLastContains (1 ms)
[ RUN      ] LinkedList.AddFirstContains
[       OK ] LinkedList.AddFirstContains (1 ms)
[ RUN      ] LinkedList.EmptyListHasSizeZero
[       OK ] LinkedList.EmptyListHasSizeZero (0 ms)
[ RUN      ] LinkedList.ListSize
[       OK ] LinkedList.ListSize (1 ms)
[ RUN      ] LinkedList.EmptyListIsEmpty
[       OK ] LinkedList.EmptyListIsEmpty (0 ms)
[----------] 17 tests from LinkedList (493 ms total)

[----------] Global test environment tear-down
[==========] 17 tests from 1 test case ran. (493 ms total)
[  PASSED  ] 17 tests.
```

## Comments
TODO
