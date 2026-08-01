#include "hashTableG.h"
#include "power.h"
#include "../Trees/AVL/AVL.h"
#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
  HashTable<int,Power<int>,AVL<int>,11> ht;

  ht.insert(20);
  ht.insert(30);
  ht.insert(28);
  ht.insert(40);
  ht.insert(51);

  ht.remove(30);

  if (ht.find(28))
    std::cout << "Encontrado\n"; 
  return 0;
}
