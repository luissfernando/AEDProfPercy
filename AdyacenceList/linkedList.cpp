#include "linkedList.h"
#include "node.h"
#include <iostream>
LinkedList::LinkedList(){
    head = nullptr;
}
LinkedList::LinkedList(int date,int peso){
    Node *nuevo = new Node(date,peso);
    this->head = nuevo;
}

void LinkedList::printLS(){
    Node* current = head;
    while(current){
        std::cout<<current->date<<" => "<<current->peso;
        current= current->next;
    }
    std::cout<<std::endl;
}
void LinkedList::addInit(int date,int peso){
    Node *nuevo = new Node(date,peso);
    nuevo->next = head;
    head = nuevo;
}
void LinkedList::push(int date,int peso){
    Node* current = head;
    Node* nuevo = new Node(date,peso);
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
// void LinkedList::copiarLista(LinkedList **listanueva){
//     Node* current = this->head;
//     while(current){
//         (*listanueva)->push(current->date);
//         current=current->next;
//     }
// }
//revisar y hacer seguimiento
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
//buscar posision
bool LinkedList::find(int data , Node **&pointer){
    pointer = &head;
    while (*pointer){
        if((*pointer)->date == data){
            return true;
        }
        *pointer = (*pointer)->next;
    }
    return false;

}
bool LinkedList::find_2(int data, Node *&pointer){
    Node *current = head;
    while(current){
        if(current->date == data){
            pointer = current;
            return true;
        }
        current= current->next;
    }
    return false;

}
//si esta vacio
bool LinkedList::is_Empty(){
    if(this->head == nullptr){
        return true;
    }
    return false;
}
