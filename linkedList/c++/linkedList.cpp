#include "linkedList.h"
#include "node.h"
#include <iostream>
LinkedList::LinkedList(){
    head = nullptr;
}
LinkedList::LinkedList(int date){
    Node *nuevo = new Node(date);
    this->head = nuevo;
}

void LinkedList::printLS(){
    Node* current = head;
    while(current){
        std::cout<<current->date<<" ";
        current= current->next;
    }
    std::cout<<std::endl;
}
void LinkedList::addInit(int date){
    Node *nuevo = new Node(date);
    nuevo->next = head;
    head = nuevo;
}
void LinkedList::push(int date){
    Node* current = head;
    Node* nuevo = new Node(date);
    while (current){
        current = current->next;
    }
    current = nuevo;
}
LinkedList:: ~LinkedList(){
}
