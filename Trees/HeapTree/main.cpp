#include "HeapT.h"
int main (int argc, char *argv[]) {
  Heap<int> heap;
  heap.push(3);
  heap.push(2);
  heap.push(7);
  heap.print();
  
  return 0;
}

