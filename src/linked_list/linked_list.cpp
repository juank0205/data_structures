#include "linked_list.h"
#include <iostream>
#include <stdexcept>

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
  Node *precedent = getNode(size - 2);
  T temp = last->getData();
  last = precedent;
  precedent->setNext(nullptr);
  size--;
  return temp;
}

template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::getNode(int index) {
  if (index >= size)
    return nullptr;
  Node *current = first;
  for (; index > 0; index--)
    current = current->getNext();
  return current;
}

template <typename T> T LinkedList<T>::getItemByIndex(int index) {
  Node* node = getNode(index);
  return node->getData();
}

template <typename T> void LinkedList<T>::deleteIndex(int index) {
  if (index >= size)
    throw std::out_of_range("Not valid index");
  if (index == 0)
    first = first->getNext();
  if (index == size-1){
    Node* current = getNode(index-1);
    last = current;
    current->setNext(nullptr);
  } else {
    Node* current = first->getNext();
    Node* precedent = first;
    while (index > 1){
      precedent = current;
      current = current->getNext();
      index--;
    }
    precedent->setNext(current->getNext());
  }
  size--;
}

template <typename T> void LinkedList<T>::deleteItem(int item){
  Node* current = first->getNext();
  Node* precedent = first;
  while (current != nullptr) {
    if (current->getData() == item){
      precedent->setNext(current->getNext());
      size--;
      return;
    }
    precedent = current; 
    current = current->getNext();
  }
  throw std::invalid_argument("Item not found");
}

template <typename T> void LinkedList<T>::insert(T item, int index){
  if (index >= size)
    throw std::out_of_range("Not valid index");
  Node *newNode = new Node(item);
  if (index == 0){
    newNode->setNext(first);  
    first = newNode;
    size++;
    return;
  }
  Node *current = first->getNext();
  Node *precedent = first;
  while (index>1){
    precedent = current;
    current = current->getNext();
    index--;
  }
  precedent->setNext(newNode);
  newNode->setNext(current);
  size++;
}

template class LinkedList<int>;
template class LinkedList<short>;
template class LinkedList<long>;
template class LinkedList<float>;
template class LinkedList<double>;
template class LinkedList<char>;
template class LinkedList<bool>;
