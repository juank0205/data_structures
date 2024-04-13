#pragma once

template <typename T>
class LinkedList {
private:
  class Node {
  private:
    T data;
    Node *next;

  public:
    Node(T newData) : data(newData), next(nullptr) {}
    T getData();
    Node *getNext();
    void setData(T data);
    void setNext(Node *next);
  };

  Node *first;
  Node *last;
  int size;

public:
  LinkedList() : first(nullptr), last(nullptr), size(0) {}
  LinkedList(T item);
  ~LinkedList();

  int getSize();
  T getFirst();
  T getLast();

  void printList();
  void insert(T item, int index);
  void deleteIndex(int index);
  void deleteItem(int item);
  T getItemByIndex(int index);
  T pop_back();
  void push_back(T item);
};
