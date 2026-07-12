#include "nodeAVL.h"

template<typename T>
NodeAVL<T>::NodeAVL(){
  left = right = nullptr;
  height = 0;
}

template <typename T>
NodeAVL<T>::NodeAVL(T data){
  left = right = nullptr;
  this->data = data;
  height = 1;
}

template <typename T>
NodeAVL<T>::~NodeAVL<T>() = default;
