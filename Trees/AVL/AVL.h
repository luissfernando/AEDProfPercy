#ifndef AVL_H
#define AVL_H
#include "../nodeAVL/nodeAVL.h"
#include "../../Stack/Stack.h"
template <typename T>
class AVL{
  NodeAVL <T> *root;
  Stack< NodeAVL<T>** > *stack;
  int factor_balance( NodeAVL <T>* );
  int height(NodeAVL <T>*);
  bool find( NodeAVL <T>**&, T );
  void rebalancing();
  void update_Height(NodeAVL<T>*);
  void rotateRight(NodeAVL<T>**);
  void rotateLeft(NodeAVL<T>**);
  public:
    AVL(T data);
    AVL();
    void insert(T data);
    NodeAVL<T>* getRoot();
    ~AVL();

};
#include "AVL.tpp"
#endif // !AVL_H


