#ifndef DEQUE_H
#define DEQUE_H
#include "node.h"
class Deque{
    private:
        Node *head;
        Node *tail;
    public:
        Deque(int);
        Deque();
        ~Deque();
        void insertAtBegin(int);
        void insertAtEnd(int);
        void removeFromBegin();
        void removeFromEnd();
        void print();

};
#endif // !DEQUE_H#define DEQUE_H
