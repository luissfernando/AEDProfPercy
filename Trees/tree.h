#ifndef TREE_h
#define TREE_H
#include "node.h"
class BinaryTree{
    Node *root;
    public:
    BinaryTree(int);
    bool insert(int data);
    bool find(int data, Node **&p);
    bool deleted(int data);
    void inOrderRecursivo(Node *);
    void mostrarInOrder();
    void go_to_next(Node **&);
    
};

#endif // !TREE_h
