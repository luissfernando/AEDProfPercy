#include "node.h"

template<typename T>
Node<T>::Node(){
  left = right = nullptr;
}

template <typename T>
Node<T>::Node(T data){
  left = right = nullptr;
  this->data = data;
}

