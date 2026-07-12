#ifndef NODEAVL_H
#define NODEAVL_H

template <typename T>
class NodeAVL{
  public:
    T data;
    NodeAVL<T> *left;
    NodeAVL<T> *right;
    int height;
    NodeAVL();
    NodeAVL(T);
    ~NodeAVL();
};
#include "nodeAVL.tpp"
#endif //
