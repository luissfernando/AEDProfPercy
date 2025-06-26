
#include "tree.h"
#include <iostream>
using namespace std;
//constructor
BinaryTree::BinaryTree(int data){
    this->root = new Node(data);
}
//insertar
bool BinaryTree::insert(int data){
    Node **p;
    if(find(data,p))
        return false;
    *p = new Node(data);
    return true;
}
//buscar un nodo 
bool BinaryTree::find(int _data, Node **&p){
    p = &root;
    while(*p && _data != (*p)->data){
        if(_data > (*p)->data ){
            p = &((*p)->right);
        }
        else{
            p = &((*p)->left);
        }
    }
    return *p;
}


// //imprimir inOrder
void BinaryTree::inOrderRecursivo(Node *root){
    if(root == nullptr){
        return;
    }
    inOrderRecursivo(root->left);
    cout<<root->data<<" ";
    inOrderRecursivo(root->right);
}
void BinaryTree::mostrarInOrder(){
    inOrderRecursivo(root);
}
//proximo ala derecha
void BinaryTree::go_to_next(Node **&q){
    q = &((*q)->right);
    while((*q)->left != nullptr){
        q = &((*q)->left);
    }
}
//eliminar
bool BinaryTree::deleted(int data){
    Node **p;
    if (!find(data, p)) {
        return false;  // No se encontró el nodo
    }
    // Caso: dos hijos
    if ((*p)->left != nullptr && (*p)->right != nullptr) {
        Node **q = p;
        go_to_next(q);                // Buscar sucesor
        (*p)->data = (*q)->data;      // Copiar valor del sucesor
        p = q;                        // Ahora eliminar el sucesor
    }

    // Caso: 0 o 1 hijo
    Node *tmp = *p;
    if ((*p)->left != nullptr)
        *p = (*p)->left;
    else
        *p = (*p)->right;
    
    delete tmp;
    return true;
}
