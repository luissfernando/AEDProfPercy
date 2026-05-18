#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

template <class T>
class GraphEdge {
public:
    typedef typename T::E E;
    typedef typename T::node node;

    E data;
    node* nodes[2];
    GraphEdge(E _data, node* n1, node* n2) : data(_data) {
        nodes[0] = n1;
        nodes[1] = n2;
    }
};

#endif