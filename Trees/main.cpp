#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char const *argv[])
{
    BinaryTree *tree = new BinaryTree(1);
    tree->insert(2);
    tree->insert(3);
    tree->insert(4);
    tree->insert(5);
    tree->mostrarInOrder();
    tree->deleted(4);
    cout<<"deted: \n";
    tree->mostrarInOrder();

    return 0;
}
