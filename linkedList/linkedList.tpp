#include "linkedList.h"
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() {
  head = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(T data) {
  Node<T>* nuevo = new Node<T>(data);
  this->head = nuevo;
}

template <typename T>
void LinkedList<T>::printLS() {
  Node<T>* current = head;
    while (current) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
}
template <typename T>
void LinkedList<T>::addInit(T data) {
  Node<T>* nuevo = new Node<T>(data);
  nuevo->next = head;
  head = nuevo;
}

template <typename T>
void LinkedList<T>::deleteInit(){
  if(head){
    Node<T> *tmp = head;
    head = head->next;
    delete tmp;
  }
}

template <typename T>
void LinkedList<T>::push(T data) {
  Node<T>** pointer = &head;
  while (*pointer) {
    pointer = &(*pointer)->next;
  }
  *pointer = new Node<T>(data);
}

template <typename T>
void LinkedList<T>::copiarLista(LinkedList<T>** listanueva) {
  Node<T>* current = this->head;
  while (current) {
    (*listanueva)->push(current->data);
    current = current->next;
  }
}


template <typename T>
void LinkedList<T>::invertir() {
  Node<T>* anterior = nullptr;
  Node<T>* actual = head;
  Node<T>* siguiente = nullptr;
  while (actual != nullptr) {
    siguiente = actual->next;   
    actual->next = anterior;    
    anterior = actual;          
    actual = siguiente;         
  }
  head = anterior;
}

template <typename T>
bool LinkedList<T>::find(T data, Node<T>**& pointer) {
  pointer = &head;
  while (*pointer) {
    if ((*pointer)->data == data) {
      return true;
    }
    pointer = &(*pointer)->next;
  }
  return false;
}

template <typename T>
void LinkedList<T>::deletedValue(T val) {
  Node<T>** pointer;
  if (find(val, pointer)) {
    Node<T>* tmp = *pointer;
    *pointer = (*pointer)->next;
    delete tmp;
  }
}

template <typename T>
Node<T>** LinkedList<T>::getHead() {
  return &head;
}

template <typename T>
LinkedList<T>::~LinkedList() {
  Node<T>* current = head;
  while (current != nullptr) {
    Node<T>* nextNode = current->next;
    delete current;
    current = nextNode;
  }
  head = nullptr;
}
