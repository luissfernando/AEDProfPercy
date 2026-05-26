#include "deque.h"
#include "circularDeque.h"
#include <iostream>
using namespace  std;
int main(int argc, char const *argv[])
{
    //Deque *r1 = new Deque(3);
    std::cout<<"\nDeque\n";
    Deque *r1= new Deque();
    r1->insertAtBegin(4);
    r1->insertAtBegin(3);
    r1->insertAtEnd(5);
    r1->removeFromBegin();
    r1->print();
    delete r1;

    //CircularDeque
    std::cout<<"\nCircularDeque\n";
    CircularDeque *f1 = new CircularDeque();
    f1->insertAtBegin(5);
    f1->insertAtBegin(3);
    f1->insertAtBegin(2);
    f1->print();
    f1->removeFromBegin();
    f1->print();
    f1->removeFromBegin();
    f1->print();
    f1->removeFromBegin();
    f1->print();
    
    return 0;
}
