#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <memory>

template <typename T>
class LinkedList {
  private:
    struct Node {
      Node(const T& v, std::shared_ptr<Node> n, std::shared_ptr<Node> p) : value(v), next(n), prev(p) {};
      T value;
      std::shared_ptr<Node> next;
      std::shared_ptr<Node> prev;
    };
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    unsigned int size_;
    std::shared_ptr<Node> find(const T& elem);

  public:
    // default ctor
    explicit LinkedList();
    // default dtor
    ~LinkedList() = default;
    // copy ctor
    LinkedList(const LinkedList& b) = default;
    // move ctor
    LinkedList (LinkedList&& b) = default;
    // move assignment
    LinkedList &operator=(LinkedList&& b) = default;
    //copy assignment
    LinkedList &operator=(const LinkedList& b) = default;

    // Modifiers

    // Space complexity - O(1)
    // Time complexity - O(1)
    void clear() noexcept;

    // Space complexity - O(1)
    // Time complexity - O(1)
    bool empty() const noexcept;

    // Space complexity - O(n)
    // Time complexity - O(n)
    unsigned int size() const noexcept;

    // Space complexity - O(1)
    // Time complexity - O(n)
    bool contains(const T& elem) const noexcept;

    // Space complexity - O(1)
    // Time complexity - O(1)
    void addFirst(const T& elem) noexcept;

    // Space complexity - O(n)
    // Time complexity - O(n)
    void add(const T& elem, const unsigned int& index);

    // Space complexity - O(1)
    // Time complexity - O(1)
    void addLast(const T& elem) noexcept;

    // Space complexity - O(1)
    // Time complexity - O(1)
    const T removeFirst();

    // Space complexity - O(1)
    // Time complexity - O(1)
    const T removeLast();

    // Space complexity - O(1)
    // Time complexity - O(n)
    const T remove(const T& elem);

    // Space complexity - O(1)
    // Time complexity - O(n)
    const T get(const int& index);

    // Misc
    void printList();
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size_(0) {}

template <typename T>
bool LinkedList<T>::empty() const noexcept {
  return head == nullptr && tail == nullptr;
}

template <typename T>
void LinkedList<T>::clear() noexcept {
  head = tail = nullptr;
}

template <typename T>
unsigned int LinkedList<T>::size() const noexcept {
  return size_;
}

template <typename T>
bool LinkedList<T>::contains(const T& elem) const noexcept {
  for (auto it = head; it != nullptr; it = it->next) {
    if (it->value == elem) {
      return true;
    }
  }
  return false;
}

template <typename T>
const T LinkedList<T>::get(const int& index) {
  auto i = 0;
  for (auto it = head; it != nullptr; it = it->next) {
    if (i == index) return it->value;
    ++i;
  }
  throw std::runtime_error("get() index not in the list");
}

template <typename T>
auto LinkedList<T>::find(const T &elem) -> std::shared_ptr<Node> {
  for (auto it = head; it != nullptr; it = it->next) {
    if (it->value == elem) {
      return it;
    }
  }
  throw std::runtime_error("find() element not in list");
}

template <typename T>
void LinkedList<T>::add(const T& elem, const unsigned int& index)  {
  if (index > size_) {
    throw std::runtime_error("add() index bigger than the total size");
  }

  else if (index == 0) {
    addFirst(elem);
  }

  else if (index == size_) {
    addLast(elem);
  }

  else {
    unsigned int i = 0;
    for(auto it = head; it != nullptr; it = it->next) {
     if (i == index) {
       auto newNode = std::make_shared<Node>(elem, it, it->prev);
       it->prev->next = newNode;
       it->prev = newNode;
       break;
     }
     ++i;
    }
  }
}


template <typename T>
void LinkedList<T>::addFirst(const T& elem) noexcept {
  if (!head && !tail) {
    head = tail = std::make_shared<Node>(elem, nullptr, nullptr);
  }
  else {
    auto newNode = std::make_shared<Node>(elem, head, nullptr);
    head->prev = newNode;
    head = newNode;
  }
  size_ += 1;
}

template <typename T>
void LinkedList<T>::addLast(const T& elem) noexcept {
  if (!head && !tail) {
    head = tail = std::make_shared<Node>(elem, nullptr, nullptr);
  }
  else {
    auto newNode = std::make_shared<Node>(elem, nullptr, tail);
    tail->next = newNode;
    tail = newNode;
  }
  size_ += 1;
}

template <typename T>
const T LinkedList<T>::remove(const T& elem) {
  T rm;

  if (!head && !tail) {
    throw std::runtime_error("attempt to remove element on empty list");
  }

  else if (elem == head->value) {
    try {
      rm = removeFirst();
    }
    catch (const std::runtime_error &e) {
      throw;
    }
  }
  else if (elem == tail->value) {
    try {
      rm = removeLast();
    }
    catch (const std::runtime_error &e) {
      throw;
    }
  }
  else {
    try {
      auto removeNode = find(elem);
      removeNode->next->prev = removeNode->prev;
      removeNode->prev->next = removeNode->next;
      removeNode->next = removeNode->prev = nullptr;
      rm = removeNode->value;
    }
    catch (std::runtime_error &e) {
      throw;
    }
  }
  size_ -= 1;
  return rm;
}


template <typename T>
const T LinkedList<T>::removeFirst() {
  if (empty()) {
    throw std::runtime_error("removeFirst() on empty list");
  }
  else if (head == tail) {
    auto rm = head;
    head = tail = nullptr;
    return rm->value;
  }
  else {
    auto removeValue = head->value;
    head->next->prev = nullptr;
    head = head->next;
    return removeValue;
  }
}

template <typename T>
const T LinkedList<T>::removeLast() {
  if (empty()) {
    throw std::runtime_error("removeFirst() on empty list");
  }
  else if (head == tail) {
    auto removeNode = tail;
    head = tail = nullptr;
    return removeNode->value;
  }
  else {
    auto removeValue = tail->value;
    tail->prev->next = nullptr;
    tail = tail->prev;
    return removeValue;
  }
}

template <typename T>
void LinkedList<T>::printList() {
  int i = 0;
  for(auto it = head; it != nullptr; it = it->next) {
    std::cout << "item: " << i << " key: " << it->value << "\n";
    i += 1;
  }
}

#endif
