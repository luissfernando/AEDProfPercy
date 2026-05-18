#ifndef GRAPH_H
#define GRAPH_H

#include "traits.h"
#include "graph_node.h"
#include "graph_edge.h"
#include <vector>
//#include "../vector/vector.h"
using namespace std;

template <class T>
class Graph {
public:
    typedef typename T::node node;
    typedef typename T::edge edge;
    typedef typename T::N N;
    typedef typename T::E E;

    vector<node*> vertices;
    //Vector <node *> vertices;

    Graph() {}
    ~Graph();

    void add_node(N _data);
    void add_edge(N u, N v, E w);
    bool find(N _data, int& pos);
};

template <class T>
Graph<T>::~Graph() {
    for (auto v : vertices)
        delete v;
}

template <class T>
bool Graph<T>::find(N _data, int& pos) {
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices[i]->data == _data) {
            pos = i;
            return true;
        }
    }
    return false;
}

template <class T>
void Graph<T>::add_node(N _data) {
    node* n = new node(_data);
    vertices.push_back(n);
}

template <class T>
void Graph<T>::add_edge(N u, N v, E w) {
    int p, q;
    if (find(u, p) && find(v, q)) {
        edge* e = new edge(w, vertices[p], vertices[q]);
        vertices[p]->adjacency.push_back(e);
        vertices[q]->adjacency.push_back(e); // si el grafo es no dirigido
    }
}

#endif
