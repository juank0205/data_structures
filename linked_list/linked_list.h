#pragma once

template <typename T> class LinkedList {
private:
  class Node {
    T data;
    Node *next;
  };

public:	
  LinkedList();
  LinkedList(T item);

  Node* first;
  Node* last;
  void printList();
  void insert(T item, int index);
  void deleteIndex(int index);
  void deleteItem(int item);
  T getItemByIndex(int index);
  void push_back();
  void pop_back();
};

