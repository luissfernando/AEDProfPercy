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
        ~LinkedList();
};

#endif // DEBUG