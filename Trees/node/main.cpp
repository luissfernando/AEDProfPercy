#include "node.h"
#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
  Node<float> *ptr = new Node<float>();
  ptr->data = 3.3;
  ptr->right = new Node<float>(4);
  ptr->right->right = new Node<float>(6);

  while (ptr){
    cout<<ptr->data<<" ";
    ptr = ptr->right;
  }
  return 0;
}
