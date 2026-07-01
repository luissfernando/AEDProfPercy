#ifndef BST_H
#define BST_H
#include "../node/node.h"
template <typename T>
class BST{
  Node<T> *root;

  void printInOrder( Node<T> * );
  bool find( Node<T> **&,T );
  void successor( Node<T>**& );
  //Node<T>* degeneradoR(Node<T>*);
  int numNodos(Node<T>*);

  public:
    BST();
    BST(T);
    bool insert(T);
    void printInOrder();
    bool remove(T);
    Node<T> *getRoot();
    //void treeDegenerado();
    //void recorridoAmplitud();
    void numHojas();
    bool search(T);
    bool compararEstruc(Node<T>*, Node<T>*);
   };
#include "BST.tpp"
#endif // !BST_H
