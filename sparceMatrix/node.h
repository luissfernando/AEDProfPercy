#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
public:
    T data;
    Node* right;
    Node* down;
    
    Node(T data);
};

template <class T>
Node<T>::Node(T data) {
    this->data = data;
    this->right = nullptr;
    this->down = nullptr;
}

#endif // NODE_H
