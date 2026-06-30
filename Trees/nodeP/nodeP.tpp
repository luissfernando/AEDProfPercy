#include "nodeP.h"

template<typename T>
NodeP<T>::NodeP(){
  left = right = parent =  nullptr;
}

template <typename T>
NodeP<T>::NodeP(T data){
  left = right = parent = nullptr;
  this->data = data;
}

template <typename T>
NodeP<T>::~NodeP<T>() = default;
