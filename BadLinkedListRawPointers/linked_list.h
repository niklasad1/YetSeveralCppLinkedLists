#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T>
class LinkedList {
  private:
    struct Node {
      Node(const T& v, Node *n, Node *p) : value(v), prev(p), next(n) {};
      T value;
      Node *prev;
      Node *next;
    };
    
    // Helper Functions
    unsigned int sizeHelper(Node *n) const noexcept;
    bool containsHelper(Node *n, const T& elem) const noexcept;
    Node* removeHelper(Node *n, const T& elem);
    Node* find(const T& elem);

    // Data members
    Node *head;
    Node *tail;

  public:
    // constructor
    explicit LinkedList();
    // default destructor -> compiler generates this for use
    ~LinkedList() = default;
    // default copy constructor -> compiler generates this for use
    LinkedList(const LinkedList& b) = default;
    // default move constructor -> compiler generates this for use
    LinkedList (LinkedList&& b) = default;
    // move assignment -> compiler generates this for use
    LinkedList &operator=(LinkedList&& b) = default;
    // copy assignment -> compiler generates this for use
    LinkedList &operator=(const LinkedList& b) = default;

    // Exposed User Interface

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
    // Time complexity - O(1)
    void add(const T& elem, const unsigned int index);

    // Space complexity - O(1)
    // Time complexity - O(1)
    Node* removeFirst();
    
    // Space complexity - O(1)
    // Time complexity - O(1)
    Node* removeLast();
    
    // Space complexity - O(n)
    // Time complexity - O(n)
    T const remove(const T& elem);
    
    // Space complexity - O(1)
    // Time complexity - O(n)
    T const get(const unsigned int& index);
    
    // Misc 
    void printList();
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

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
  return sizeHelper(head);
}

template <typename T>
bool LinkedList<T>::contains(const T& elem) const noexcept {
  return containsHelper(head, elem);
}

template <typename T>
T const LinkedList<T>::get(const unsigned int& index) {
  unsigned int i = 0;
  for (auto it = head; it != nullptr; it = it->next) {
    if (i == index) {
      return it->value;
    }
    // not found
    else if (i >= index) {
      break;
    }
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
  if (!head && !tail) {
    head = tail = new Node(elem, nullptr, nullptr);
  }
  else {
    Node *newNode = new Node(elem, nullptr, tail);
    tail->next = newNode;
    tail = newNode;
  }
}

template <typename T>
void LinkedList<T>::add(const T& elem, const unsigned int index) {
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

  // the index is valid here because of the first 
  // if assertion
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
auto LinkedList<T>::remove(const T& elem) -> T const {
  try {
    Node *rm = removeHelper(head, elem);
    return rm->value;
  }
  catch (std::runtime_error &e) {
    throw;
  }
}

template <typename T>
auto LinkedList<T>::removeFirst() -> Node* {
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
auto LinkedList<T>::removeLast() -> Node* {
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

template <typename T>
void LinkedList<T>::printList() {
  for(auto it = head; it != nullptr; it = it->next) {
    std::cout << "elem: " << it->value << " ";
  }
}

// private helper functions
template <typename T>
unsigned int LinkedList<T>::sizeHelper(Node *curr) const noexcept {
  if (!curr) return 0;
  else return 1+sizeHelper(curr->next);
}

template <typename T>
bool LinkedList<T>::containsHelper(Node *curr, const T& elem) const noexcept {
  if (!curr) return false;
  else if (curr->value == elem) {
    return true;
  }
  else return containsHelper(curr->next, elem);
}

template <typename T>
auto LinkedList<T>::removeHelper(Node *curr, const T& elem) -> Node* {
  if (!curr) {
    throw std::runtime_error("element not in the list");
  }

  else if (curr->value == elem) {
    if (curr == head) {
      try{
        return removeFirst();
      }
      catch (std::runtime_error) {
        throw;
      }
    }
    else if (curr == tail) {
      try {
        return removeLast();
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

template <typename T>
auto LinkedList<T>::find(const T& elem) -> Node* {
  for (auto it = head; it != nullptr; it = it->next) {
    if (it->value == elem) return it;
  }
  return nullptr;
}

#endif
