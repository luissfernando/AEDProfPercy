#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include "linkedList.h"
class AdjacencyList{
    int size_V;
    bool directed;
    LinkedList **adjacency;
    public:
        AdjacencyList(int,bool);
        void insertLis(int A ,int B,int w);
        void mostrar();
};

#endif 
