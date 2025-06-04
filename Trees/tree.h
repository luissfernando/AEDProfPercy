#ifndef TREE_h
#define TREE_H
#include "node.h"
class BinaryTree{
    Node *root;
    public:
    BinaryTree(int);
    bool insert(int data);
    bool find(int data, Node **&p);
    void mostrar();
};

#endif // !TREE_h
