#include <iostream>
#include "LinkedList.h"

int main() {
  LinkedList<int> *myLinkedList = new LinkedList(10);
  myLinkedList->append(20);
  myLinkedList->append(30);
  myLinkedList->prepend(5); 
  myLinkedList->insert(2,15);
  myLinkedList->insert(99,99);
  myLinkedList->insert(0,0);

  myLinkedList->printList(); std::cout << "\n";

  myLinkedList->remove(0);
  myLinkedList->remove(568);

  myLinkedList->printList(); std::cout << "\n";

  delete myLinkedList;

  return 0;
}