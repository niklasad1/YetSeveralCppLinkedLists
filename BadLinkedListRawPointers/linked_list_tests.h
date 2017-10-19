#ifndef LINKED_LIST_TESTS_H
#define LINKED_LIST_TESTS_H

#include "linked_list.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <cassert>


namespace LListTests {
  namespace {

    // Test Declarations
    int test_simple_empty(void);

    int test_size_empty(void);
    int test_size(void);

    int test_addlast_contains(void);
    int test_addfirst_contains(void);

    int test_contains_empty(void);

    int test_insert_removeFirst_to_empty(void);
    int test_insert_removeLast_to_empty(void);
    int test_insert_remove_to_empty_random(void);

    int test_removeFirst_on_empty(void);
    int test_removeLast_on_empty(void);
    int test_remove_on_empty(void);

    int test_add_remove_contains_n(void);

    int test_get_n_elems(void);
    int test_get_invalid_idx(void);

    int test_add_n_elems_clear(void);
    
    int test_add_at_pos_n(void);
    int test_add_invalid_index(void);

    template <typename T>
      int verify_test(std::string, T exp, T got);

    // ---------------------------------------------------------------

    // Test definitions
    int test_add_at_pos_n() {
      LinkedList<std::string> l;
      int rc = 0;
      std::vector<std::string> w = {"Niklas is the FIRST", "NEW SECOND HAHA", "SECOND", "THIRD", "FOUTH"};

      l.addFirst(w[0]);
      l.add(w[2], 1);
      l.add(w[3], 2);
      l.add(w[4], 3);
      l.add(w[1], 1);
     
      std::string test = __func__;

      rc += verify_test(test + "_1", l.get(0), w[0]);
      rc += verify_test(test + "_2", l.get(1), w[1]);
      rc += verify_test(test + "_3", l.get(2), w[2]);
      rc += verify_test(test + "_4", l.get(3), w[3]);
      rc += verify_test(test + "_5", l.get(4), w[4]);
      return rc;
    }
    
   
    int test_add_invalid_index() {
      LinkedList<int> l;
      bool exp = true;
      bool got = false;

      // add 100 elements -> index 99 is the last
      for(int i = 0; i < 100; ++i) {
        l.add(i, i);
      }
      
      try {
        l.add(101, 1337);
      }
      catch (std::runtime_error &e) {
        got = !got;
      }
      return verify_test(__func__, got, exp);
    }

    int test_add_n_elems_clear() {
      LinkedList<int> l;
      auto n = (std::rand() % 1000) + 500;

      for (auto i = 0; i < n; i++) {
        (i & 1) ? l.addLast(i) : l.addFirst(i);
      }
      l.clear();
      return verify_test(__func__, l.empty(), true);
    }

    int test_get_n_elems() {
      std::vector<int> exp {1, 39, 88, 11, -11, 88};
      LinkedList<int> l;
      int rc = 0;

      for (auto i : exp) {
        l.addLast(i);
      }
      
      std::string test = __func__;
      rc += verify_test(test + "_1", 1, exp[0]);
      rc += verify_test(test + "_2", 39, exp[1]);
      rc += verify_test(test + "_3" , 88, exp[2]);
      rc += verify_test(test + "_4", 11, exp[3]);
      rc += verify_test(test + "_5", -11, exp[4]);
      rc += verify_test(test + "_6", 88, exp[5]);
      return rc;
    }

    int test_get_invalid_idx(void) {
      LinkedList<int> l;
      bool exp = true;
      bool got = false;

      for (auto i = 0; i < 100; i++) {
        l.addLast(i);
      }

      try {
        l.get(100);
      }
      catch (std::runtime_error &e) {
        got = !got;
      }
      return verify_test(__func__, got, exp);
    }


    int test_add_remove_contains_n() {
      LinkedList<int> l;

      int rc = 0;
      std::string test = __func__;
      std::set<int> added;
      std::set<int> removed;
      bool got = true;
      bool exp = true;

      // feed seed
      srand(std::time(0));

      const unsigned int n = 10000;

      for (unsigned int i = 0; i < n; i++) {
        added.insert(i);
      }

      for(auto i : added) {
        auto r = std::rand() % 2;
        
        if (r == 0) {
          l.addLast(i);
        }
        else if (r == 1) {
          l.addFirst(i);
        }
        else {
          auto pos = std::rand() % l.size();
          l.add(i, pos);
        }
      }

      for (unsigned int i = 0; i < n/2; i++) {
        auto r = std::rand() % n;
        removed.insert(r);
      }

      for(auto i : removed) {
        l.remove(i);
      }

      // the list should not contain any of the unique removed elements
      for(auto i : removed) {
        if (l.contains(i)) {
          got = false;
          break;
        }
      }
      rc += verify_test(test + "_2", got, exp);

      unsigned long ll = l.size();
      unsigned long rr = n-removed.size();
      rc += verify_test(test + "_3", ll, rr);
      return rc;
    }


    int test_remove_on_empty() {
      LinkedList<double> d;
      auto got = false;
      auto exp = true;

      try {
        d.remove(1232.221);
      }
      catch (std::runtime_error &e) {
        got = !got;
      }
      return verify_test(__func__, got, exp);
    }

    int test_removeLast_on_empty() {
      LinkedList<std::string> d;
      auto got = false;
      auto exp = true;

      try {
        d.remove("hello_world");
      }
      catch (std::runtime_error &e) {
        got = !got;
      }
      return verify_test(__func__, got, exp);
    }

    int test_removeFirst_on_empty() {
      LinkedList<char> d;
      auto got = false;

      auto exp = true;

      try {
        d.remove('c');
      }
      catch (std::runtime_error &e) {
        got = !got;
      }
      return verify_test(__func__, got, exp);
    }

    int test_insert_removeFirst_to_empty() {
      LinkedList<int> l;
      std::vector<int> input {1, 2, 3, 4, 5};

      for (auto insert : input) {
        l.addLast(insert);
      }
      for (size_t i = 0; i < input.size(); i++) {
        l.removeFirst();
      }
      return verify_test(__func__, true, l.empty());
    }

    int test_insert_removeLast_to_empty() {
      LinkedList<int> l;
      std::vector<int> input {1, 2, 3, 4, 5};

      for (auto insert : input) {
        l.addFirst(insert);
      }
      for (size_t i = 0; i < input.size(); i++) {
        l.removeLast();
      }
      return verify_test(__func__, true, l.empty());
    }

    int test_insert_remove_to_empty_random(void) {
      LinkedList<int> l;
      std::set<int> uniq;
      std::map<bool, unsigned int> got;
      unsigned int exp = 0;

      // feed seed
      srand(std::time(0));

      auto n = (std::rand() % 1000) + 100;

      for (auto i = 0; i < n; i++) {
        uniq.insert(std::rand() % std::numeric_limits<int>::max());
      }

      for (auto i: uniq) {
        auto r = std::rand() % 1;
        if (r) l.addLast(i);
        else l.addFirst(i);
      }

      for (auto i: uniq) {
        l.remove(i);
      }
      return verify_test(__func__, l.size(), exp);
    }

    int test_contains_empty() {
      LinkedList<std::string> s;
      auto got = s.contains("hej");
      auto exp = false;
      return verify_test(__func__, got, exp);
    }


    int test_addlast_contains() {
      LinkedList<int> l;
      std::set<int> uniq;
    
      std::map<bool, int> got;

      // feed seed
      srand(std::time(0));

      auto n = (std::rand() % 1000) + 100;

      for (auto i = 0; i < n; i++) {
        auto r = std::rand() % std::numeric_limits<int>::max();
        uniq.insert(r);
      }

      for (auto i: uniq) {
        l.addLast(i);
      }

      for (auto i: uniq) {
        auto r = l.contains(i);
        got[r] += 1;
      }

      return verify_test(__func__, got[false], 0);
    }

    int test_addfirst_contains() {
      LinkedList<int> l;
      std::set<int> uniq;

      std::map<bool, unsigned int> got;
      unsigned int exp = 0;

      // feed seed
      srand(std::time(0));

      auto n = (std::rand() % 1000) + 100;

      for (auto i = 0; i < n; i++) {
        uniq.insert(std::rand() % std::numeric_limits<int>::max());
      }

      for (auto i: uniq) {
        l.addFirst(i);
      }

      for (auto i: uniq) {
        auto r = l.contains(i);
        got[r] += 1;
      }

      return verify_test(__func__, got[false], exp);
    }

    int test_size_empty() {
      LinkedList<double> l;
      unsigned int exp = 0;
      return verify_test(__func__, l.size(), exp);
    }

    int test_size() {
      LinkedList<int> l;
      std::set<int> uniq;

      // feed seed
      srand(std::time(0));

      auto exp = (std::rand() % 1000) + 100;

      for (auto i = 0; i < exp; i++) {
        uniq.insert(std::rand() % std::numeric_limits<int>::max());
      }

      for (auto i : uniq) {
        l.addLast(i);
      }
      return verify_test(__func__, (int)l.size(), (int)uniq.size());
    }

    // internal interface definitions/implementation
    int test_simple_empty() {
      LinkedList<std::string> l;
      return verify_test(__func__, true, l.empty());
    }

    template <typename T>
      int verify_test(std::string testName, T got, T exp) {
        std::cout << testName << std::endl;
        if (exp != got) {
           std::cout << "FAILED\n" << "EXPECTED: " << exp << "\nGOT: " << got << std::endl;
          return -1;
        }
        return 0;
      }
    //--------------------------------------------------------------------

    // public interface
    void run(void) {
      std::cout << "\n######################################\n";
      std::cout << "STARTING TESTS\n\n";

      int rc = 0;

      rc += test_simple_empty();
      rc += test_size_empty();
      rc += test_size();

      rc += test_addlast_contains();
      rc += test_addfirst_contains();
      rc += test_contains_empty();

      rc += test_insert_removeFirst_to_empty();
      rc += test_insert_removeLast_to_empty();
      rc += test_insert_remove_to_empty_random();

      rc += test_remove_on_empty();
      rc += test_removeLast_on_empty();
      rc += test_removeFirst_on_empty();

      rc += test_add_remove_contains_n();

      rc += test_get_n_elems();
      rc += test_get_invalid_idx();
      rc += test_add_n_elems_clear();

      rc += test_add_at_pos_n();
      rc += test_add_invalid_index();
      
      if (rc < 0) {
        std::cout << "\n\nTESTS FAILED!!!\n";
      }
      else {
        std::cout << "\n\bTESTS PASSED!!!\n";
      }
      std::cout << "######################################\n";
    }
  }
}

#endif
