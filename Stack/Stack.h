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
    T pop(); //elimina y devuelve el ultimo ele
    T top(); // devuelve el ultimo ele "NO BORRA"
    bool isEmpty();
    void clear();
    ~Stack();
};
#include "Stack.tpp"
#endif

