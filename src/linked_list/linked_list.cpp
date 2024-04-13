#include "linked_list.h"
#include <iostream>

template <typename T> int LinkedList<T>::Node::getData() { return data; }
template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::Node::getNext() {
  return next;
}
template <typename T> void LinkedList<T>::Node::setData(T data) {
  this->data = data;
}
template <typename T> void LinkedList<T>::Node::setNext(Node *next) {
  this->next = next;
}

template <typename T> LinkedList<T>::LinkedList(T data) {
  Node *newNode = new Node(data);
  first = last = newNode;
}

template <typename T> int LinkedList<T>::getSize() { return size; }
template <typename T> int LinkedList<T>::getFirst() { return first->data; }
template <typename T> int LinkedList<T>::getLast() { return last->data; }

template <typename T> void LinkedList<T>::printList() {
  Node *current = first;
  std::cout << "[";
  while (current != nullptr) {
    if (current != last)
      std::cout << current->getData() << ", ";
    else
      std::cout << current->getData();
    current = current->getNext();
  }
  std::cout << "]" << std::endl;
}

template <typename T> void LinkedList<T>::push_back(T item) {
  Node *newNode = new Node(item);
  last->setNext(newNode);
  last = newNode;
}
