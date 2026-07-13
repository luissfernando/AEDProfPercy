#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node/node.h"

template <typename T>
class LinkedList {
  private:
    Node<T>* head; 

  public:
    LinkedList(T);
    LinkedList();
    void printLS();
    void addInit(T);
    void deleteInit();
    void push(T);
    void copiarLista(LinkedList<T>**); 
    void invertir();
    bool find(T data, Node<T>**& pointer); 
    void deletedValue(T val);
    T getInit();
    Node<T>** getHead();
    ~LinkedList();
};

#include "linkedList.tpp"

#endif
