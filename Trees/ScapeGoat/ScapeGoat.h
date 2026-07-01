#ifndef SCAPEGOAT_H
#define SCAPEGOAT_H
#include "../nodeP/nodeP.h"
#include <cmath>
#include <iostream>
template<typename T>
class ScapeGoat{
  private:
    NodeP<T>* root;
    int n_total;
    int n_max;
    bool find(NodeP<T>*&,NodeP<T>**&,T);
    void printInOrder(NodeP<T>*);
    void successor(NodeP<T>**&);
    int size(NodeP<T>*);
    int flatten(NodeP<T>*,NodeP<T>**,int);
    NodeP<T>* buildBalanced(NodeP<T>**,int,int);
    void rebuild(NodeP<T>*);
    int depth(NodeP<T>* );
    NodeP<T>* findScapeGoat(NodeP<T>*);
  public:
    ScapeGoat();
    ScapeGoat(T);
    bool insert(T);
    bool remove(T);
    bool search(T);

    void printInOrder();
    NodeP<T>* getRoot();
};
#include "ScapeGoat.tpp"

#endif
