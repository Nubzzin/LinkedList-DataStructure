#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

template <typename type>
class LinkedList {
public:
  struct Node {
    type value;
    Node *next;
  };

  Node *head;
  Node *tail;
  int length;

public:
  LinkedList(type value) {
    head = new Node;
    head->value = value;
    head->next = nullptr;
    tail = head;
    length = 1;
  }

  ~LinkedList() {
    Node *currentNode = this->head;
    while(currentNode != nullptr) {
      Node *temp = currentNode;
      currentNode = currentNode->next;
      delete temp;
    }
  }

  void append(type value) {
    Node *newNode{ new Node };
    newNode->value = value;
    newNode->next = nullptr;
    tail->next = newNode;
    tail = newNode;
    length++;
  }

  void prepend(type value) {
    Node *newNode{ new Node };
    newNode->value = value;
    newNode->next = head;
    this->head = newNode;
    length++;
  }

  void insert(int index, type value) {
    if (index <= 0) { prepend(value); return; }
    else if (index >= length) { append(value); return; }
    Node *pre{ head };
    for(int k{0}; k < index-1; k++) pre = pre->next;
    Node *aft{ pre->next };
    Node *newNode{ new Node };
    newNode->value = value;
    newNode->next = aft;
    pre->next = newNode;
    length++;
  }

  void remove(int index) {
    if (index == 0) {
      Node *tmp = head;
      head = head->next;
      delete tmp;
      return;
    }
    if (index > length-1) {
      Node *pre = head;
      Node *tmp = head->next;
      while (tmp->next != nullptr){
        pre = pre->next;
        tmp = tmp->next;
      }
      pre->next = nullptr;
      tail = pre;
      delete tmp;
      return;
    }
    Node *pre{ head };
    for (int i{0}; i < index-1; i++) pre = pre->next;
    Node *del{ pre->next};
    Node *aft{ del->next};
    pre->next = aft;
    delete del;
  }

  void printList() {
    Node *currentNode = this->head;
    while(currentNode != nullptr) {
      std::cout << currentNode->value << " ";
      currentNode = currentNode->next;
    }
  }
};

#endif // LINKED_LIST_H