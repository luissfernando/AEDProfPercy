#include "AVL.h"
#include <iostream>
using namespace std;
#include "../treeVisualizer/treeVisualizer.h"
int main (int argc, char *argv[]) {
  AVL<int> *root = new AVL<int>(4);
  NodeAVL<int>* temp = root->getRoot();
  NodeAVL<int>** p = &temp;
  temp->right = new NodeAVL<int>(8);
  temp->left = new NodeAVL<int>(2);
  temp->right->right = new NodeAVL<int>(10);
  temp->left->left = new NodeAVL<int>(1);
  temp->left->right = new NodeAVL<int>(3);
  
  root->insert(9);
  //root->insert(34);
  //root->insert(70);
  TreeVisualizer::generate(root->getRoot(),"AVL.dot");
  system("dot -Tpng AVL.dot -o AVL.png");
  system("xdg-open AVL.png");
  return 0;
}
