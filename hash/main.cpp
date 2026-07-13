#include "hashTable.h"
#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
  HashTable f1(10);
  f1.insert(1,10);
  f1.insert(2,20);
  f1.printHash();
  return 0;
}
