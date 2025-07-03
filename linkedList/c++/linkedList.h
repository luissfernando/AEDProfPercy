#include "node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class LinkedList {
    private:
        Node *head;
    public:
        LinkedList(int);
        LinkedList();
        void printLS();
        void addInit(int);
        void push(int);
        void copiarLista(LinkedList**);
        void invertir();
        bool find(int data, Node **&pointer);
        bool find_2(int ,Node *&);
        ~LinkedList();
};

#endif // DEBUG
