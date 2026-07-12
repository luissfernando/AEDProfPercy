#include "node.h"

template <typename T>
Node<T>::Node(T data) {
  this->data = data; 
  this->next = nullptr;
}
template <typename T>
Node<T>::~Node() {}
