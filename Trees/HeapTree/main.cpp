#include "HeapT.h"
#include <iostream>
using namespace std;
int main (int argc, char *argv[]) {
  Heap<int> heap;
  heap.push(3);
  heap.push(2);
  heap.push(7);
  heap.print();
  cout<<"maximo: "<<heap.extractMax()<<endl;
  heap.print();
  
  return 0;
}

