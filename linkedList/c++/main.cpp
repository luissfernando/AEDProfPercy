#include <iostream>
#include "linkedList.h"

using namespace std;
int main(int argc, char const *argv[])
{
    LinkedList *f1 = new LinkedList();
    f1->addInit(2);
    f1->addInit(1);
    f1->push(3);
    f1->push(4);
    f1->push(5);
    f1->push(6);
    f1->push(7);
    f1->push(8);
    LinkedList *f2 = new LinkedList();
    f1->copiarLista(&f2);
    f1->invertir();
    f1->invertirListaYoni();
    f1->printLS();
    return 0;
}
