#include "vector.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    Vector *r1 = new Vector(2);
    r1->add_item(1);
    r1->add_item(2);
    r1->add_item(3);

    r1->print();
    cout<<"pos: "<<r1->search(8)<<endl;
    return 0;
}
