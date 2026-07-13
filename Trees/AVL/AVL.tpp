#include "AVL.h"
#include <iostream>
using namespace std;

#define MAX(A,B) ( (A) > (B) ? (A) :  (B) )
inline int max(int a, int b){
  return (a>b) ? a : b;
} 
template<typename T>
AVL<T>::AVL(T data){
  root = new NodeAVL<T>(data);
  stack = new Stack<NodeAVL<T>**>();
  root->left = root->right = nullptr;
}
template<typename T>
NodeAVL<T>* AVL<T>::getRoot(){
  return root;
}
template<typename T>
int AVL<T>::factor_balance(NodeAVL<T>* node){
  if(!node) return 0;
  return height(node->right)-height(node->left);
}
template<typename T>
int AVL<T>::height(NodeAVL<T>* node){
  if(!node) return -1;
  return 1 + max( height(node->left),height(node->right) );
}
template<typename T>
bool AVL<T>::find(NodeAVL<T>**& p, T data){
  p = &root;
  stack->clear();
  while(*p && (*p)->data != data ){
    stack->push(p);
    if( data < (*p)->data )
      p = &((*p)->left);
    else{
      p = &((*p)->right);
    }
  }
  return *p;
}

template<typename T>
void AVL<T>::insert(T data){
  NodeAVL<T>** p;
  if( find(p,data) ) return ;
  *p = new NodeAVL<T>(data);
  rebalancing();
}
template<typename T>
void AVL<T>::rebalancing(){
  int fb;
  while(!stack->isEmpty()){
    NodeAVL<T>** tmp;
    //cout<< (*stack->pop())->data;

  }
}
