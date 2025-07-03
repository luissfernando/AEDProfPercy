#include <iostream>
#include "linkedList.h"

using namespace std;

int main(int argc, char const *argv[])
{   
    Node **ptr = NULL;
    Node *ptr2 = NULL;
    LinkedList *f1 = new LinkedList();
    f1->addInit(2);
    f1->addInit(1);
    f1->push(3);
    f1->push(4);
    f1->push(5);
    f1->push(6);
    f1->push(7);
    f1->push(8);
    //f1->printLS();
    f1->find_2(3,ptr2);
    cout<<"si ha encontrado : "<< ptr2->date;
    return 0;
}
