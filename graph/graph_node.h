#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <vector>

template <class T>
class GraphNode {
public:
    typedef typename T::N N;
    typedef typename T::edge edge;

    N data;
    std::vector<edge*> adjacency;
    GraphNode(N _data) : data(_data) {}
};

#endif