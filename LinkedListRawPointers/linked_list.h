#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// LinkedList using raw pointers
// The implementation assumes that the "values" allocated stack with a bigger
// than lifetime than the heap allocated data

template <typename T>
class LinkedList {
  private:
    struct Node {
      Node(T const &v, Node *n, Node *p) : value(v), prev(p), next(n) {};
      T value;
      Node *prev;
      Node *next;
    };

    // Helper Functions
    unsigned int sizeHelper(Node *n) const noexcept;
    bool containsHelper(Node *n, T const elem) const noexcept;
    Node* removeLastHelper();
    Node* removeFirstHelper();
    Node* removeHelper(Node *n, T const elem);

    // Data
    Node* head;
    Node* tail;

  public:
    explicit LinkedList();
    ~LinkedList();
    // default copy constructor -> let the compiler generate this
    LinkedList(const LinkedList& b) = default;
    // default move constructor -> let the compiler generate this
    LinkedList (LinkedList&& b) = default;
    // default move assignment -> let the compiler generate this
    LinkedList &operator=(LinkedList&& b) = default;
    // default assignment -> let the compiler generate this
    LinkedList &operator=(const LinkedList& b) = default;

    // Space complexity - O(1)
    // Time complexity - O(1)
    void clear() noexcept;

    // Space complexity - O(1)
    // Time complexity - O(1)
    bool empty() const noexcept;

    // this implementation is very inefficient but I like recursion
    // Space complexity - O(n)
    // Time complexity - O(n)
    unsigned int size() const noexcept;

    // Recursive version
    // Space complexity - O(n)
    // Time complexity - O(n)
    bool contains(const T& elem) const noexcept;

    // Space complexity - O(1)
    // Time complexity - O(1)
    void addFirst(const T& elem) noexcept;

    // Space complexity - O(1)
    // Time complexity - O(1)
    void addLast(const T& elem) noexcept;

    // Space complexity - O(1)
    // Time complexity - O(n)
    void add(const T& elem, const unsigned int& index);

    // Space complexity - O(1)
    // Time complexity - O(1)
    T const removeFirst();

    // Space complexity - O(1)
    // Time complexity - O(1)
    T const removeLast();

    // Space complexity - O(n)
    // Time complexity - O(n)
    T const remove(const T& elem);

    // Space complexity - O(1)
    // Time complexity - O(n)
    T const get(const int& index);

};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
  clear();
}

template <typename T>
bool LinkedList<T>::empty() const noexcept {
  return head == nullptr && tail == nullptr;
}

template <typename T>
void LinkedList<T>::clear() noexcept {
  while (head != nullptr) {
    auto rm = removeFirstHelper();
    delete rm;
    rm = nullptr;
  }
}

template <typename T>
unsigned int LinkedList<T>::size() const noexcept {
  return sizeHelper(head);
}

template <typename T>
bool LinkedList<T>::contains(const T& elem) const noexcept {
  return containsHelper(head, elem);
}

template <typename T>
T const LinkedList<T>::get(const int& index) {
  int i = 0;
  for (auto it = head; it != nullptr; it = it->next) {
    if (i == index) return it->value;
    else if (i >= index) break;
    i += 1;
  }
  throw std::runtime_error("invalid index");
}


template <typename T>
void LinkedList<T>::addFirst(const T& elem) noexcept {
  if (head == nullptr && tail == nullptr) {
    head = tail = new Node(elem, nullptr, nullptr);
  }
  else {
    Node *newNode = new Node(elem, head, nullptr);
    head->prev = newNode;
    head = newNode;
  }
}

template <typename T>
void LinkedList<T>::addLast(const T& elem) noexcept {
  if (head == nullptr && tail == nullptr) {
    head = tail = new Node(elem, nullptr, nullptr);
  }
  else {
    Node *newNode = new Node(elem, nullptr, tail);
    tail->next = newNode;
    tail = newNode;
  }
}

template <typename T>
void LinkedList<T>::add(const T& elem, const unsigned int& index)  {
  // remember O(n)
  auto listSize = size();

  if (index > listSize) {
    throw std::runtime_error("add() index bigger than the total size");
  }

  else if (index == 0) {
    addFirst(elem);
  }

  else if (index == listSize) {
    addLast(elem);
  }

  else {
    unsigned int i = 0;
    for(auto it = head; it != nullptr; it = it->next) {
     if (i == index) {
       auto newNode = new Node(elem, it, it->prev);
       it->prev->next = newNode;
       it->prev = newNode;
       break;
     }
     i += 1;
    }
  }
}

template <typename T>
T const LinkedList<T>::remove(const T& elem) {
  try {
    Node *rm = removeHelper(head, elem);
    T t = rm->value;
    delete rm;
    rm = nullptr;
    return t;
  }
  catch (const std::runtime_error) {
    throw;
  }
}

template <typename T>
T const LinkedList<T>::removeFirst() {
  auto rm = removeFirstHelper();
  T t = rm->value;
  delete rm;
  rm = nullptr;
  return t;
}

template <typename T>
T const LinkedList<T>::removeLast() {
  auto rm = removeLastHelper();
  T t = rm->value;
  delete rm;
  rm = nullptr;
  return t;
}


template <typename T>
auto LinkedList<T>::removeFirstHelper() -> Node* {
  if (!head && !tail) {
    throw std::runtime_error("removeFirst() on emptyList");
    return nullptr;
  }
  // list with only one node
  else if (head == tail) {
    Node *rm = head;
    head = tail = nullptr;
    return rm;
  }
  else {
    Node *rm = head;
    head->next->prev = nullptr;
    head = head->next;
    return rm;
  }
}

template <typename T>
auto LinkedList<T>::removeLastHelper() -> Node* {
  if (!head && !tail) {
    throw std::runtime_error("removeLast() on emptyList");
    return nullptr;
  }
  // list with only one node
  else if (head == tail) {
    Node *rm = head;
    head = tail = nullptr;
    return rm;
  }
  else {
    Node *rm = tail;
    tail->prev->next = nullptr;
    tail = tail->prev;
    return rm;
  }
}

// Implementaton - Helper Functions
template <typename T>
unsigned int LinkedList<T>::sizeHelper(Node *curr) const noexcept {
  if (!curr) return 0;
  else return 1+sizeHelper(curr->next);
}

template <typename T>
bool LinkedList<T>::containsHelper(Node *curr, T elem) const noexcept {
  if (!curr) return false;
  else if (curr->value == elem) {
    return true;
  }
  else return containsHelper(curr->next, elem);
}

template <typename T>
auto LinkedList<T>::removeHelper(Node *curr, T elem) -> Node* {
  if (!curr) {
    throw std::runtime_error("element not in the list");
  }

  else if (curr->value == elem) {
    if (curr == head) {
      try{
        return removeFirstHelper();
      }
      catch (std::runtime_error) {
        throw;
      }
    }
    else if (curr == tail) {
      try {
        return removeLastHelper();
      }
      catch (std::runtime_error) {
        throw;
      }
    }
    else {
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
      return curr;
    }
  }
  else return removeHelper(curr->next, elem);
}

#endif
