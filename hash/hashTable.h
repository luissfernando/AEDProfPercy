#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "entry.h"
#include <iostream>
using namespace std;

class HashTable {
  Entry *table;
  int capacity;
  public:
    HashTable(int cap);
    int hash(int key);
    void insert(int key,int value);
    bool search(int key);
    void remove(int key);
    void printHash();
  
    ~HashTable(); 
};

HashTable::HashTable(int cap) {
  capacity = cap;
  table = new Entry[cap];
}
int HashTable::hash(int key){
  return key%capacity;
}
void HashTable::insert(int key, int value){
  int index = hash(key);
  *(table+index) = Entry(key,value);
}
void HashTable::printHash(){
  for(int i=0;i<capacity;i++){
    cout<<"key : "<<table->key<<endl;
    cout<<"valor " <<table->value<<endl;
  }
}

HashTable::~HashTable() {
  delete []table;
}

#endif // HASHTABLE_H
