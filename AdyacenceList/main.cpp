#include <iostream>
#include "adjacencyList.h"

using namespace std;

int main(int argc, char const *argv[])
{
    AdjacencyList *ptr = new AdjacencyList(5,true);
    ptr->insertLis(1,2,10);
    ptr->insertLis(3,2,20);
    ptr->mostrar();
    return 0;
}
