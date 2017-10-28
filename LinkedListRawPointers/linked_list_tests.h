#ifndef LINKED_LIST_TESTS_H
#define LINKED_LIST_TESTS_H

#include "linked_list.h"
#include <cstdlib>
#include <ctime>
#include <gtest/gtest.h>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <vector>

TEST(LinkedList, AddAtPositionNAndGet) {
  LinkedList<std::string> l;
  std::vector<std::string> w = {"Niklas is the FIRST", "NEW SECOND HAHA",
                                "SECOND", "THIRD", "FOUTH"};

  l.addFirst(w[0]);
  l.add(w[2], 1);
  l.add(w[3], 2);
  l.add(w[4], 3);
  l.add(w[1], 1);
  ASSERT_EQ(w[0], l.get(0));
  ASSERT_EQ(w[1], l.get(1));
  ASSERT_EQ(w[2], l.get(2));
  ASSERT_EQ(w[3], l.get(3));
  ASSERT_EQ(w[4], l.get(4));
}

TEST(LinkedList, AddAtInvalidPosition) {
  LinkedList<int> l;
  bool exp = true;
  bool got = false;

  // add 100 elements -> index 99 is the last
  for (int i = 0; i < 100; ++i) {
    l.add(i, i);
  }

  try {
    l.add(101, 1337);
  } catch (std::runtime_error &e) {
    got = !got;
  }
  ASSERT_EQ(exp, got);
}

TEST(LinkedList, AddNElemsThenClear) {
  LinkedList<int> l;
  auto n = (std::rand() % 1000) + 500;

  for (auto i = 0; i < n; i++) {
    (i & 1) ? l.addLast(i) : l.addFirst(i);
  }
  l.clear();
  ASSERT_EQ(true, l.empty());
}

TEST(LinkedList, GetInvalidIndex) {
  LinkedList<int> l;
  bool exp = true;
  bool got = false;

  for (auto i = 0; i < 100; i++) {
    l.addLast(i);
  }

  try {
    l.get(100);
  } catch (std::runtime_error &e) {
    got = !got;
  }
  ASSERT_EQ(exp, got);
}

TEST(LinkedList, AddElemsAndListContains) {
  LinkedList<int> l;

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

  for (auto i : added) {
    auto r = std::rand() % 2;

    if (r == 0) {
      l.addLast(i);
    } else if (r == 1) {
      l.addFirst(i);
    } else {
      auto pos = std::rand() % l.size();
      l.add(i, pos);
    }
  }

  for (unsigned int i = 0; i < n / 2; i++) {
    auto r = std::rand() % n;
    removed.insert(r);
  }

  for (auto i : removed) {
    l.remove(i);
  }

  // the list should not contain any of the unique removed elements
  for (auto i : removed) {
    if (l.contains(i)) {
      got = false;
      break;
    }
  }
  ASSERT_EQ(got, exp);

  unsigned long ll = l.size();
  unsigned long rr = n - removed.size();
  ASSERT_EQ(ll, rr);
}

TEST(LinkedList, RemoveOnEmptyList) {
  LinkedList<double> d;
  auto got = false;
  auto exp = true;

  try {
    d.remove(1232.221);
  } catch (std::runtime_error &e) {
    got = !got;
  }
  ASSERT_EQ(exp, got);
}

TEST(LinkedList, RemoveLastOnEmptyList) {
  LinkedList<std::string> d;
  auto got = false;
  auto exp = true;

  try {
    d.remove("hello_world");
  } catch (std::runtime_error &e) {
    got = !got;
  }
  ASSERT_EQ(exp, got);
}

TEST(LinkedList, RemoveFirstOnEmptyList) {
  LinkedList<char> d;
  auto got = false;
  auto exp = true;

  try {
    d.remove('c');
  } catch (std::runtime_error &e) {
    got = !got;
  }
  ASSERT_EQ(exp, got);
}

TEST(LinkedList, AddLastThenRemoveFirstUntilEmpty) {
  LinkedList<int> l;
  std::vector<int> input{1, 2, 3, 4, 5};

  for (auto insert : input) {
    l.addLast(insert);
  }
  for (size_t i = 0; i < input.size(); i++) {
    l.removeFirst();
  }
  ASSERT_EQ(true, l.empty());
}

TEST(LinkedList, AddFirstThenRemoveLastUntilEmpty) {
  LinkedList<int> l;
  std::vector<int> input{1, 2, 3, 4, 5};

  for (auto insert : input) {
    l.addFirst(insert);
  }
  for (size_t i = 0; i < input.size(); i++) {
    l.removeLast();
  }
  ASSERT_EQ(true, l.empty());
}

TEST(LinkedList, AddFirstOrLastThenRemoveRandom) {
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

  for (auto i : uniq) {
    auto r = std::rand() % 1;
    if (r)
      l.addLast(i);
    else
      l.addFirst(i);
  }

  for (auto i : uniq) {
    l.remove(i);
  }
  ASSERT_EQ(exp, l.size());
}

TEST(LinkedList, EmptyListDoesNotContain) {
  LinkedList<std::string> s;
  auto got = s.contains("hej");
  auto exp = false;
  ASSERT_EQ(exp, got);
}

TEST(LinkedList, AddLastContains) {
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

  for (auto i : uniq) {
    l.addLast(i);
  }

  for (auto i : uniq) {
    auto r = l.contains(i);
    got[r] += 1;
  }
  ASSERT_EQ(0, got[false]);
}

TEST(LinkedList, AddFirstContains) {
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

  for (auto i : uniq) {
    l.addFirst(i);
  }

  for (auto i : uniq) {
    auto r = l.contains(i);
    got[r] += 1;
  }
  ASSERT_EQ(exp, got[false]);
}

TEST(LinkedList, EmptyListHasSizeZero) {
  LinkedList<double> l;
  unsigned int exp = 0;
  ASSERT_EQ(exp, l.size());
}

TEST(LinkedList, ListSize) {
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
  ASSERT_EQ(l.size(), uniq.size());
}

TEST(LinkedList, EmptyListIsEmpty) {
  LinkedList<std::string> l;
  ASSERT_EQ(true, l.empty());
}

#endif
