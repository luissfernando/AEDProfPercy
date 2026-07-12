#include "node.h"
#include <iostream>
using namespace std;
void swap(int &a ,int &b){
  int tmp = a;
  a = b;
  b = tmp;
}
class CircularLinkedList{
  Node *head;
  public:
    CircularLinkedList(){
      head = nullptr;
    }
    void mostrar(){
      if(!head) return;
      Node* current = head;
      do{
        cout<<current->date<<" ";
        current = current->next;
      } while (current != head );
      cout<<endl;
    
    }
    //O(1()
    bool insertAtBegin(int data){
      Node *p = head;
      Node *tmp = new Node(data);
      if(!head){
        head = tmp;
        head->next = head;
        return true;
      }
      tmp->next = head->next;
      head->next = tmp;
      
      swap(head->date,tmp->date);
      return true;
      
    }
    bool removeFromBegin(){
      if( !head || !(head->next) ){
        delete head;
        head = nullptr;
        return true;
      }
      Node *tmp = head->next;
      head->date = tmp->date;
      head->next = tmp->next;
      delete tmp;
      return true;
    }


};


int main (int argc, char *argv[]) {
  CircularLinkedList *ptr = new CircularLinkedList();
  ptr->insertAtBegin(8);
  ptr->insertAtBegin(6);
  ptr->insertAtBegin(4);
  ptr->mostrar();

  ptr->removeFromBegin();
  ptr->mostrar();

  ptr->removeFromBegin();
  ptr->mostrar();

  return 0;
}
