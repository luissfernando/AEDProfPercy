#include <iostream>
#include "linkedList.h"
#include "doublyLinkedList.h"
using namespace std;

int main(int argc, char const *argv[])
{   
    Node **ptr = NULL;
    Node *ptr2 = NULL;
    LinkedList *f1 = new LinkedList();
    f1->addInit2(2);
    f1->addInit2(1);
    f1->push(3);
    f1->push(4);
    f1->push(5);
    f1->push(6);
    f1->push(7);
    f1->push(8);
    f1->printLS();
    f1->deletedValue(3);
    f1->printLS();

    // lista doblemnete enlazada
    cout<<"doble lista enlazada\n";
    DoublyLinkedList *f2 = new DoublyLinkedList();
    f2->insertToEnd(2);
    f2->insertToEnd(3);
    f2->printList();
    

    return 0;
}
