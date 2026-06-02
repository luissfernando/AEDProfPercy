#include "vector.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    Vector *r1 = new Vector(0);
    r1->push_back(1);
    r1->push_back(2);
    r1->push_back(3);
    r1->push_back(8);
    r1->push_back(4);
    (*r1)[2] = 10;
    r1->print();

    return 0;
}
