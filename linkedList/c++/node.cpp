#include "node.h"
Node::Node(int date){
    this->date = date;
    this->next = nullptr;
}
Node::~Node(){
    //no hace falta liberar next ya que lo gestiona la lista
}