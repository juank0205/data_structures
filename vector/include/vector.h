#pragma once

#include <iostream>
template <typename T> class Vector {
public:
  Vector() {
    T *newArr = new T[m_capacity];
    m_arr = newArr;
  };

  Vector(unsigned int size) {
    T *newArr = new T[size];
    m_arr = newArr;
    m_capacity = size;
  };

  ~Vector() { delete[] m_arr; };

  inline int size() const { return m_elementCount; };
  inline unsigned int capacity() const { return m_capacity; };

  void push_back(T value) {
    m_elementCount++;
    if (m_elementCount > m_capacity)
      grow();
    m_arr[m_elementCount - 1] = value;
  };

  inline void pop() { m_elementCount--; };

  void shrinkToFit() {
    T *newArr = new T[m_elementCount];
    copyContent(newArr);
    m_arr = newArr;
    m_capacity = m_elementCount;
  };

  int allocate(unsigned int amount) {
    if (amount < m_elementCount)
      return -1;
    T *newArr = new T[amount];
    copyContent(newArr);
    m_arr = newArr;
    m_capacity = amount;
    return 0;
  };

  void print() {
    std::cout << "[";
    for (unsigned int i = 0; i < m_elementCount; i++) {
      if (i != m_elementCount - 1)
        std::cout << m_arr[i] << ", ";
      else
        std::cout << m_arr[i] << "]" << std::endl;
    }
  }

private:
  T *m_arr;
  unsigned int m_elementCount = 0;
  unsigned int m_capacity = 1;

  void grow() {
    T *newArr = new T[m_capacity * 2];
    copyContent(newArr);
    m_arr = newArr;
    m_capacity = m_capacity * 2;
  };

  void copyContent(T *destination) {
    for (unsigned int i = 0; i < m_elementCount; i++)
      destination[i] = m_arr[i];
  }
};
