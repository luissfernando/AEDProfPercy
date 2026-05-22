#include "doublyLinkedList.h"
#include <iostream>
DoublyLinkedList::DoublyLinkedList(){
  head = nullptr;
}
void DoublyLinkedList::printList(){
  DNode *current = head;
  while(current){
    std::cout<< current->data <<" ";
    current = current->next;
  }
}
void DoublyLinkedList::insertToBegin(int val){
  DNode* nuevo = new DNode(val);
  nuevo->next = head;
  if(head){
    head->prev = nuevo;
  }
  head = nuevo;
}
void DoublyLinkedList::insertToEnd(int val){
  DNode** current = &head;
  DNode*  anterior = nullptr;
  while(*current){
    anterior = *current;
    current = &(*current)->next;
  }
  *current = new DNode(val);
  (*current)->prev = anterior;
}
