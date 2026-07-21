#include "Stack.h"
#include <iostream>
using namespace std;
template <typename T>
Stack<T>::Stack() {
  lista = new LinkedList<T>();
}

//PUSH  inserta al inicio de la list
template <typename T>
void Stack<T>::push(T data) {
  lista->addInit(data);
}

// POP  elimina y devuelve el elemento del tope de la pila
template <typename T>
T Stack<T>::pop() {
  if (isEmpty()) {
    throw std::runtime_error("stack vacio.");
  }
  T valorTope = (*lista->getHead())->data;
  lista->deleteInit();
  return valorTope;
}

// TOP devuelve el elemento del tope no borra
template <typename T>
T Stack<T>::top() {
    if (isEmpty()) {
        throw std::runtime_error("Error: El Stack esta vacio.");
    }
    return (*lista->getHead())->data;
}

template <typename T>
bool Stack<T>::isEmpty() {
    return *lista->getHead() == nullptr;
}

template <typename T>
void Stack<T>::clear(){
  while(!isEmpty()){
    pop();
  }
}

template <typename T>
Stack<T>::~Stack() {
}
