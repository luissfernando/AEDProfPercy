#include "sparce.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    Sparce<char> *ptr = new Sparce<char>(5,5);
    ptr->insert(1,1,'A');
    ptr->insert(1,2,'B');
    ptr->mostrar();
    return 0;
}
