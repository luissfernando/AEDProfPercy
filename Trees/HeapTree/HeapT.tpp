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
template<typename T>
void Heap<T>::heapifyDown(int index){
  int n = data.getSize();
  while(true){
    int l = left(index);
    int r = right(index);
    int largest = index;
    if(l < n && data[l] > data[largest])
      largest = l;
    if(r < n && data[r] > data[largest])
      largest = r;
    if(largest == index)
      break;
    data.swap(data[index], data[largest]);
    index = largest;
  }
}
template <typename T>
T Heap<T>::extractMax(){
  T tmp = data[0];
  data[0] = data[data.getSize()-1];
  data.pop();
  heapifyDown(0);
  return tmp;
}
template <typename T>
void Heap<T>::print(){
  data.print();
}
