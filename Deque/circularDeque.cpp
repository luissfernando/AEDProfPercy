#include "circularDeque.h"
#include <iostream>
CircularDeque::CircularDeque(int data){
  Node *nuevo = new Node(data);
  this->head = this->tail = nuevo;
}
CircularDeque::CircularDeque(){
  Node *nuevo = new Node();
  head = tail = nullptr;
}
void CircularDeque::print(){
  Node *current = head;
  if(!current) return;  
  do {
    std::cout<<current->data<<" ";
    current= current->next;

  }while(current != head);
  std::cout<<std::endl;
}
void CircularDeque::insertAtBegin(int data){
  Node *nuevo = new Node(data);
  nuevo->next = head;
  if(!head){
    head = tail = nuevo;
  }
  tail->next = nuevo;
  nuevo->prev = tail;
  head->prev = nuevo;
  head = nuevo;
}
void CircularDeque::insertAtEnd(int data){
  Node *nuevo = new Node(data);
  if(!head){
    head = tail = nuevo;
  }
  tail->next = nuevo;
  nuevo->prev = tail;
  nuevo->next = head;
  tail = nuevo;
  head->prev = tail;
}
void CircularDeque::removeFromBegin(){
  if(!head || head->next == head ){
    delete head;
    head = tail = nullptr;
    return ;
  }
  head = head->next;
  delete head->prev;
  head->prev = tail;
  tail->next = head;
}
void CircularDeque::removeFromEnd(){
  if(!head || head->next == head){
    delete head;
    head = tail = nullptr;
    return;
  }
  tail = tail->prev;
  delete tail->next;
  tail->next = head;
  head->prev = tail;
}
CircularDeque::~CircularDeque(){}
