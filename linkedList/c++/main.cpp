#include <iostream>
#include "linkedList.h"

using namespace std;
int main(int argc, char const *argv[])
{
    LinkedList *f1 = new LinkedList();
    f1->addInit(3);
    f1->addInit(4);
    f1->push(5);
    f1->printLS();
    return 0;
}
