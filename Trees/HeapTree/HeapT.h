#ifndef HEAPT_H
#define HEAPT_H
#include "../../vector/vector.h"
template <typename T>
class Heap{
private:
    Vector<T> data;
    int left(int);
    int right(int);
    int parent(int);
    
    void heapifyUp(int i);
    void heapifyDown(int i);

public:
    void push(T val);
    void pop();
    T top();
    void print();
};
#include "HeapT.tpp"
#endif // !DEBUG
