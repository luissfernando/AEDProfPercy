#include "BST.h"
#include <iostream>
using namespace  std;

template <typename T>
BST<T>::BST(){
  root = nullptr;
}

template <typename T>
BST<T>::BST(T data){
  root = new Node<T>(data);
}

template <typename T>
bool BST<T>::insert(T data){
  Node<T>** p = nullptr; 
  if(find(p,data)) return false;
  *p = new Node<T>(data);
  return true;
}
template <typename T>
void BST<T>::printInOrder(Node<T> *node){
  if(!node)
    return;
  printInOrder(node->left);
  cout<<node->data<<" ";
  printInOrder(node->right);
}

template <typename T>
void BST<T>::printInOrder(){
  printInOrder(root);
  cout<<endl;
}

template <typename T>
bool BST<T>::find(Node<T>**&p , T data){
  p = &(root);
  while (*p && (*p)->data != data ) {
    if( data < (*p)->data ){
      p = &((*p)->left);
    }
    else{
      p = &((*p)->right);
    }
  }
  return *p;
}

template<typename T>
void BST<T>::successor(Node<T>** &s){
  s = &((*s)->right);
  while ( (*s)->left ) {
    s = &((*s)->left);
  }
}

template <typename T>
bool BST<T>::remove(T data){
  Node<T>**p = nullptr;
  if( !find(p,data) ) return false;
  if( (*p)->left && (*p)->right ){
    Node<T> **tmp = p;
    successor(tmp);
    (*p)->data = (*tmp)->data;
    p = tmp;
  }
  Node<T>* q = *p;
  if( (*p)->right ){
    *p = (*p)->right;
  }
  else{
    *p = (*p)->left;
  }
  delete q;
  return true;
}

template <typename T>
Node<T>* BST<T>::getRoot(){
  return root;
}

/*template <typename T>
void BST<T>::treeDegenerado(){
  degeneradoR(root);
}

template <typename T>
Node<T>* BST<T>::degeneradoR(Node<T>* node){
  if(!node) return node;
  
  if(node->left)
  degeneradoR(node->left);
  
  node->right=degeneradoR(node->right);
}
*/

/*template<typename T>
void BST<T>::recorridoAmplitud(){
  recorrAmRecur(root);
}
*/

template <typename T>
int BST<T>::numNodos(Node<T>* node){
  if(!node) return 0;
  return 1 + numNodos(node->left) + numNodos(node->right);
}
template<typename T>
void BST<T>::numHojas(){
  cout<<"total Hojas: "<<numNodos(root)-1<<endl;
}
template <typename T>
bool BST<T>::compararEstruc(Node<T> *root1, Node<T> *root2){
  if(!root1 && !root2) return true;
  if(!root1 || !root2) return false;
  if(root1->data != root2->data) return false;
  return compararEstruc(root1->left) &&
          compararEstruc(root2->right);
}




