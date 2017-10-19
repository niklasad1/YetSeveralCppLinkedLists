#include <iostream>
#include <chrono>
#include "linked_list_tests.h"
#include "linked_list.h"

using namespace std::chrono;

int main(void) {
  auto startTime = high_resolution_clock::now();
  LListTests::run();
  auto endTime = high_resolution_clock::now();
  std::cout << "\n\nExecution time: " 
            << duration_cast<milliseconds>(endTime - startTime).count() 
            << " ms" << "\n\n";
  return 0;
}
