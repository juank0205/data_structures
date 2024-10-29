#include "vector.h"
#include <iostream>

int main(int argc, char *argv[]) {
  Vector<int> miPene;
  miPene.push_back(5);
  miPene.push_back(6);
  miPene.push_back(7);
  miPene.push_back(8);
  miPene.push_back(9);
  miPene.print();
  miPene.pop();
  miPene.pop();
  miPene.pop();
  miPene.print();

  std::cout << "Probando el pene alocado: " << std::endl;
  Vector<char> miCharsito(4);
  std::cout << "Size: " << miCharsito.capacity() << std::endl;
  miCharsito.push_back('a');
  miCharsito.push_back('a');
  miCharsito.push_back('a');
  miCharsito.push_back('a');
  miCharsito.push_back('a');
  miCharsito.print();
  std::cout << "Size: " << miCharsito.capacity() << std::endl;
  miCharsito.allocate(10);
  std::cout << "Size alocado 10: " << miCharsito.capacity() << std::endl;
  miCharsito.shrinkToFit();
  std::cout << "Size shrinkeado: " << miCharsito.capacity() << std::endl;

  return 0;
}
