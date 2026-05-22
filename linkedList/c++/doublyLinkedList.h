#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

struct DNode {
  DNode *next;
  DNode *prev;
  int data;
  DNode(int val){
    data = val;
    next = nullptr;
    prev = nullptr;
  }
};
class DoublyLinkedList{
  private:
    DNode* head;
  public:
    DoublyLinkedList();
    void insertToBegin(int);
    void insertToEnd(int);
    bool deletedVal(int);
    void printList();
   ~DoublyLinkedList(); 
};





#endif // !DOUBLYLINKEDLIST_H
