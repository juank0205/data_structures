#pragma once

template <typename T> class LinkedList {
private:
  class Node {
  private:
    T data;
    Node *next;

  public:
    Node(T newData) : data(newData), next(nullptr) {}
    int getData();
    Node *getNext();
    void setData(T data);
    void setNext(Node *next);
  };

  Node *first;
  Node *last;
  int size;

public:
  LinkedList() : first(nullptr), last(nullptr) {}
  LinkedList(T item);

  int getSize();
  int getFirst();
  int getLast();

  void printList();
  /*
  void insert(T item, int index);
  void deleteIndex(int index);
  void deleteItem(int item);
  T getItemByIndex(int index);
  void pop_back();
  */
  void push_back(T item);
};
