#include "deque.h"
int main(int argc, char const *argv[])
{
    //Deque *r1 = new Deque(3);
    Deque *r1= new Deque();
    r1->insertAtBegin(4);
    r1->insertAtBegin(3);
    r1->insertAtEnd(5);
    r1->removeFromBegin();
    r1->print();

    delete r1;
    return 0;
}
