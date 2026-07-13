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
  root->height = 0;
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
   NodeAVL<T>** tmp;
  while(!stack->isEmpty()){
    //cout<< (*stack->pop())->data;
    tmp = stack->pop();
    update_Height(*tmp);
    fb = factor_balance(*tmp);
    if(fb > 1){
      //LL
      if( factor_balance((*tmp)->left) >= 0 ){
        rotateRight(tmp);
      }
      //LR
      else{
        rotateLeft( (&(*tmp)->left) );
        rotateRight(tmp);
      }
    }
    else if( fb < -1){
      //RR
      if( factor_balance((*tmp)->right)<= 0 ){
        rotateLeft(tmp);
      }
      //RL
      else{
        rotateRight( &((*tmp)->right) );
        rotateLeft(tmp);
      }
    }
  }
}
template <typename T>
void AVL<T>::update_Height(NodeAVL<T>* node){
  node->height = height(node);
}
template <typename T>
void AVL<T>::rotateRight(NodeAVL<T>** p) {
  NodeAVL<T>* q = (*p)->left;
  (*p)->left = q->right;
  q->right = *p;
  update_Height(q->right);
  update_Height(q);
  *p = q;
}
template <typename T>
void AVL<T>::rotateLeft(NodeAVL<T>** p) {
  NodeAVL<T>* q = (*p)->right;
  (*p)->right = q->left;
  q->left = *p;
  update_Height(q->left);
  update_Height(q);
  *p = q;
}
