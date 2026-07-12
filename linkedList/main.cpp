#include "linkedList.h"
int main (int argc, char *argv[]) {
  LinkedList<int> *f1 = new LinkedList<int>();
  f1->push(3);
  f1->push(2);
  f1->printLS();
  return 0;
}
