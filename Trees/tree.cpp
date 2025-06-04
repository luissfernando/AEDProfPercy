
#include "tree.h"
#include <iostream>
using namespace std;
BinaryTree::BinaryTree(int data){
    this->root = new Node(data);
}
// bool BinaryTree::insert(int data){

// }
bool BinaryTree::find(int _data, Node **&p){
    p = &root;
    while(*p && _data != *(p)->data){
        if(_data > (*p)->data ){
            p = &((*p)->right);
        }
        else{
            p = &((*p)->left);
        }
    }
    return *p;
}
void BinaryTree::mostrar(){
    cout<<root->data<<" "<<endl;
}