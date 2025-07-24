#include "adjacencyList.h"
#include <iostream>
AdjacencyList::AdjacencyList(int size,bool directed){
    this->size_V = size;
    this->directed = directed;
    this->adjacency = new LinkedList* [size_V];
    for(int i=0;i<size;i++){
        adjacency[i] = new LinkedList();
    }
}
void AdjacencyList::insertLis(int A,int B,int w){
    adjacency[A]->push(B,w);
    if(!directed){
        adjacency[B]->push(A,w);
    }

    }

void AdjacencyList::mostrar(){
    for(int i=0;i< size_V;i++){
        std::cout<< i <<": ";
        adjacency[i]->printLS();
    }
}
