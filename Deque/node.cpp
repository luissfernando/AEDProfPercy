#include "node.h"
Node::Node(int data){
    this->next = this->prev = nullptr;
    this->data = data;
}
Node::Node(){
    this->next = this->prev = nullptr;
}
Node::~Node(){}