#include "ScapeGoat.h"

using namespace  std;

template <typename T>
ScapeGoat<T>::ScapeGoat(){
  root = nullptr;
  n_total = n_max = 0;
}

template <typename T>
ScapeGoat<T>::ScapeGoat(T data){
  root = new NodeP<T>(data);
  n_total = n_max = 1;
}
template <typename T>
void ScapeGoat<T>::printInOrder(NodeP<T> *node){
  if(!node)
    return;
  printInOrder(node->left);
  cout<<node->data<<" ";
  printInOrder(node->right);
}

template <typename T>
void ScapeGoat<T>::printInOrder(){
  printInOrder(root);
  cout<<endl;
}
template <typename T>
bool ScapeGoat<T>::insert(T data){
  NodeP<T>* ptrNodoP;
  NodeP<T>** ptrNodo;
  if(find(ptrNodoP,ptrNodo,data)) 
    return false;
  *ptrNodo = new NodeP<T>(data);
  (*ptrNodo)->parent = ptrNodoP;
  n_total++;
  n_max++;
  
  int d = depth(*ptrNodo);
  double limite = log(n_max) / log(1.5);
  if(d > limite){
    NodeP<T> *scapegoat = findScapeGoat( *ptrNodo );
    if( scapegoat ){
      rebuild(scapegoat);
    }
  }
  return true;
}

template<typename T>
NodeP<T>* ScapeGoat<T>::findScapeGoat(NodeP<T>* ptrNodo){
  while(ptrNodo){
    NodeP<T>* parent = ptrNodo->parent;
    if(3 * size(ptrNodo) > 2 * size(parent))
      return parent;
    ptrNodo = parent;
  }
  return nullptr;
}
template <typename T>
bool ScapeGoat<T>::find(NodeP<T>*& ptrNodoP ,NodeP<T>**& ptrNodo , T data){
  ptrNodoP = nullptr;
  ptrNodo = &root;
  while (*ptrNodo && (*ptrNodo)->data != data ) {
    ptrNodoP = *ptrNodo;
    if( data < (*ptrNodo)->data ){
      ptrNodo = &((*ptrNodo)->left);
    }
    else{
      ptrNodo = &((*ptrNodo)->right);
    }
  }
  return *ptrNodo;
}

template<typename T>
void ScapeGoat<T>::successor(NodeP<T>** &s){
  s = &((*s)->right);
  while ( (*s)->left ) {
    s = &((*s)->left);
  }
}

template <typename T>
bool ScapeGoat<T>::remove(T data){
  NodeP<T>**p = nullptr;
  if( !find(p,data) ) return false;
  if( (*p)->left && (*p)->right ){
    NodeP<T> **tmp = p;
    successor(tmp);
    (*p)->data = (*tmp)->data;
    p = tmp;
  }
  NodeP<T>* q = *p;
  NodeP<T>* child = (q->left) ? q->left : q->right;
  *p = child;
  if(child)
    child->parent = q->parent;
  delete q;

  n_total--;
  if(n_total < n_max / 2){
    rebuild(root);
    n_max = n_total;
  }
  return true;
}

template <typename T>
NodeP<T>* ScapeGoat<T>::getRoot(){
  return root;
}

template<typename T>
int ScapeGoat<T>::size(NodeP<T>* node){
  if(!node) return 0;
  return 1 + size(node->left) + size(node->right);
}

template<typename T>
int ScapeGoat<T>::depth(NodeP<T>* node){
  int d = 0;
  while(node != root){
    node = node->parent;
    d++;
  }
  return d;
}
template<typename T>
int ScapeGoat<T>::flatten(NodeP<T>* node, NodeP<T>** arr, int index){
  if(!node)
    return index;
  index = flatten(node->left, arr, index);
  arr[index++] = node;
  index = flatten(node->right, arr, index);
  return index;
}
template<typename T>
NodeP<T>* ScapeGoat<T>::buildBalanced(NodeP<T>** arr,int left,int right){
  if(left > right)
    return nullptr;
  int mid = (left + right) / 2;
  NodeP<T>* node = arr[mid];
  node->left = buildBalanced(arr, left, mid - 1);
  if(node->left)
    node->left->parent = node;
  node->right = buildBalanced(arr, mid + 1, right);
  if(node->right)
    node->right->parent = node;
  
  return node;
}

template<typename T>
void ScapeGoat<T>::rebuild(NodeP<T>* scapegoat){
  if(!scapegoat)
    return;
  int sz = size(scapegoat);
  NodeP<T>** arr = new NodeP<T>*[sz];
  flatten(scapegoat, arr, 0);
  NodeP<T>* parent = scapegoat->parent;
  NodeP<T>* newRoot = buildBalanced(arr, 0, sz - 1);
  newRoot->parent = parent;
  if(parent == nullptr){
    root = newRoot;
  }
  else if(parent->left == scapegoat){
    parent->left = newRoot;
  }
  else{
    parent->right = newRoot;
  }
    delete[] arr;
}
