#include "linked_list/linked_list.h"

int duplicate(int x) { return x*2; }

int main(int argc, char *arvg[]) {
  LinkedList<int> *myList = new LinkedList<int>();
  myList->push_back(1);
  myList->push_back(2);
  myList->push_back(3);
  myList->insert(5, 2);
  myList->insert(7, 0);
  myList->insert(10, 4);
  myList->printList();
  myList->callback(duplicate);
  myList->printList();
  delete myList;
  return 0;
}
