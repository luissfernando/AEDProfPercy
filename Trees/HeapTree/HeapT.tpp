#include "HeapT.h"
template <typename T>
int Heap<T>::left(int index){
  return 2 * index + 1;
}
template <typename T>
int Heap<T>::right(int index){
  return 2 * index + 2;
}
template <typename T>
int Heap<T>::parent(int index){
  return (index - 1) / 2;
}

template <typename T>
void Heap<T>::push(T value) {
  data.push_back(value);
  heapifyUp( data.getSize()-1 );
}
template< typename T>
void Heap<T>::heapifyUp(int index){
  int p = parent(index);
  while( index>0 && data[p]<data[index] ){
    data.swap(data[p],data[index]);
    index = p;
    p = parent(p);
  }
}
template <typename T>
void Heap<T>::print(){
  data.print();
}
