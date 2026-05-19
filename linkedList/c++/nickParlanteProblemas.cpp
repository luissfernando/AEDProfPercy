#include "linkedList.h"
#include <iostream>
using namespace  std;

int count(Node *head,int val){
  int cont=0;
  while(head){
    if(head->date == val){
      cont++;
    }
    head = head->next;
  }
  return cont;
}
int countRecursivo(Node *head,int val){
  if(!head){
    return 0;
  }
  return (head->date == val) ? 1 + countRecursivo(head->next,val) : countRecursivo(head->next,val);
}

int getNth(Node* head,unsigned int index){
  while(head && index > 0){
    
    head = head->next;
    index--;
  }

  return (index==0) ? head->date : 0;
}

int main (int argc, char *argv[]) {
  LinkedList *f1 = new LinkedList();
  f1->push(1);
  f1->push(2);
  f1->push(3);
  f1->push(4);
  f1->push(5);

  Node* head = f1->getHead();
  cout<<getNth(head,2);
  return 0;
}
