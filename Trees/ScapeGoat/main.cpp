#include "ScapeGoat.h"
#include <iostream>
#include "../treeVisualizer/treeVisualizer.h"
using namespace  std;

int main (int argc, char *argv[]) {
  ScapeGoat<int> *ptr = new ScapeGoat<int>();
  for(int i=1;i<=60;i++)
    ptr->insert(i);
  
  
  TreeVisualizer::generate(ptr->getRoot(),"SG.dot");
  system("dot -Tpng SG.dot -o SG.png");
  system("xdg-open SG.png");
  return 0;
}
