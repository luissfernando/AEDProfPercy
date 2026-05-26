#ifndef CIRCULARDEQUE_H
#define CIRCULARDEQUE_H
#include "node.h"
class CircularDeque{
    private:
        Node *head;
        Node *tail;
    public:
        CircularDeque(int);
        CircularDeque();
        ~CircularDeque();
        void insertAtBegin(int);
        void insertAtEnd(int);
        void removeFromBegin();
        void removeFromEnd();
        void print();

};
#endif //
