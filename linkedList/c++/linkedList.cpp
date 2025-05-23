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
    if(!current){
        head = nuevo;
    }
    else{
        while (current->next){
            current = current->next;
        }
        current->next = nuevo; //
    }
    
}
void LinkedList::copiarLista(LinkedList **listanueva){
    Node* current = this->head;
    while(current){
        (*listanueva)->push(current->date);
        current=current->next;
    }
}
void LinkedList::invertir(){
    Node* anterior = nullptr;
    Node* actual = head;
    Node* siguiente = nullptr;

    while (actual != nullptr) {
        siguiente = actual->next;    // Guardar el siguiente nodo
        actual->next = anterior;     // Revertir el puntero
        anterior = actual;           // Avanzar anterior
        actual = siguiente;          // Avanzar actual
    }

    head = anterior;
}
LinkedList:: ~LinkedList(){

}
