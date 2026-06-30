#ifndef NODE_H
#define NODE_H

template <typename T>
class NodeP{
  public:
    T data;
    NodeP<T> *left;
    NodeP<T> *right;
    NodeP<T> *parent;
    NodeP();
    NodeP(T);
    ~NodeP();
};
#include "nodeP.tpp"
#endif // !NODE_H
