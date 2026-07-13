#ifndef STACK_H
#define STACK_H

#include "../linkedList/linkedList.h"
#include <stdexcept> 

template <typename T>
class Stack {
  private:
    LinkedList<T> *lista;
  public:
    Stack();
    void push(T data);
    T pop();
    T top();
    bool isEmpty();
    ~Stack();
};
#include "Stack.tpp"
#endif

