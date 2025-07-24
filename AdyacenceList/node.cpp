#include "node.h"
Node::Node(int date,int peso){
    this->date = date;
    this->peso = peso;
    this->next = nullptr;
}
Node::~Node(){
    //no hace falta liberar next ya que lo gestiona la lista
}