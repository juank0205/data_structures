#include "linked_list.h"
#include <iostream>

template <typename T> T LinkedList<T>::Node::getData() { return data; }
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
  size = 1;
}

template <typename T> LinkedList<T>::~LinkedList() {
  Node *precedent = first;
  Node *current = precedent->getNext();
  while (current != nullptr) {
    delete precedent;
    precedent = current;
    current = current->getNext();
  }
  delete precedent;
}

template <typename T> int LinkedList<T>::getSize() { return size; }
template <typename T> T LinkedList<T>::getFirst() { return first->getData(); }
template <typename T> T LinkedList<T>::getLast() { return last->getData(); }

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
  return;
}

template <typename T> void LinkedList<T>::push_back(T item) {
  Node *newNode = new Node(item);
  if (size == 0) {
    first = newNode;
  } else {
    last->setNext(newNode);
  }
  last = newNode;
  size++;
  return;
}

template <typename T> T LinkedList<T>::pop_back() {
  Node *current = first;
  while (current->getNext() != last)
    current = current->getNext();
  T temp = last->getData();
  last = current;
  current->setNext(nullptr);
  return temp;
}

template class LinkedList<int>;
template class LinkedList<short>;
template class LinkedList<long>;
template class LinkedList<float>;
template class LinkedList<double>;
template class LinkedList<char>;
template class LinkedList<bool>;
