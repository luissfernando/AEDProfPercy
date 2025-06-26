#include "deque.h"
#include <iostream>
Deque::Deque(int data){
    Node *nuevo = new Node(data);
    this->head = this->tail = nuevo;
}
Deque::Deque(){
    Node *nuevo = new Node();
    
}
void Deque::print(){
    Node *current = head;
    while(current){
        std::cout<<current->data<<" ";
        current= current->next;
    }
}
void Deque::insertAtBegin(int data){
    Node *nuevo = new Node(data);
    if(!head){
        head = tail = nuevo;
    }
    else{
        nuevo->next=head;
        head->prev=nuevo;
        head = nuevo;
    }

}  
void Deque::insertAtEnd(int data){
    Node *nuevo = new Node(data);
    if(!head){
        head = tail = nuevo;
    }
    else{
        tail->next = nuevo;
        nuevo->prev = tail;
        tail = nuevo;
    }
}
void Deque::removeFromBegin(){
    if(!head){
        return ; // lista vacia    
    }
    if(head->next){
        Node *tmp = head;
        head = head->next;
        head->prev = nullptr;
        delete tmp;
    }
    else{
        delete head;
        head = tail = nullptr;
    }
}

Deque::~Deque(){}
