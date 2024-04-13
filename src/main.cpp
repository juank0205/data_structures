#include "linked_list/linked_list.h"

int main(int argc, char *arvg[]) {
  LinkedList<int> *myList = new LinkedList<int>();
  myList->push_back(5);
  myList->push_back(6);
  myList->push_back(7);
  myList->push_back(8);
  myList->push_back(9);
  myList->printList();
  return 0;
}
