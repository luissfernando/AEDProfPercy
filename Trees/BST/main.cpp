#include "BST.h"
#include <iostream>
#include "../treeVisualizer/treeVisualizer.h"
using namespace  std;

int main (int argc, char *argv[]) {
  BST<int> *ptr = new BST<int>();
  ptr->insert(5);
  ptr->insert(8);
  ptr->insert(2);
  ptr->insert(12);
  ptr->insert(6);
  ptr->insert(7);
  
  ptr->numHojas();
  //ptr->recorridoAmplitud();




  //ptr->treeDegenerado();

  TreeVisualizer::generate(ptr->getRoot(),"bst.dot");
  system("dot -Tpng bst.dot -o bst.png");
  system("xdg-open bst.png");
  return 0;
}
