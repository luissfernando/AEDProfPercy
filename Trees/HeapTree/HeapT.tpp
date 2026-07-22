#include "HeapT.h"
template <typename T>
void Heap<T>::push(T value) {
  data.push_back(value);
  int i = data.getSize() - 1;
  while (i > 0) {
    int parent = (i - 1) / 2;
    if (data[parent] >= data[i])
      break;
    data.swap(data[parent], data[i]);
    i = parent;
  }
}
template <typename T>
void Heap<T>::print(){
  data.print();
}
