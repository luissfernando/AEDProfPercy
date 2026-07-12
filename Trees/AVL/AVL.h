#ifndef AVL_H
#define AVL_H
#include "../nodeAVL/nodeAVL.h"
template <typename T>
class AVL{
  NodeAVL <T> *root;
  int factor_balance( NodeAVL <T>* );
  int height( NodeAVL <T>* );
  bool find( NodeAVL <T>**&, T );
  public:
    AVL(T data);
    AVL();
    void insert(T data);
    NodeAVL<T>* getRoot();
    ~AVL();

};
#include "AVL.tpp"
#endif // !AVL_H


