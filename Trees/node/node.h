#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{
  public:
    T data;
    Node<T> *left;
    Node<T> *right;
    Node();
    Node(T);
    ~Node();
};
#include "node.tpp"
#endif // !NODE_H
