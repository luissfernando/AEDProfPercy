#ifndef TRAITS_H
#define TRAITS_H

template <typename T>
class GraphNode; // Adelanta declaración
template <typename T>
class GraphEdge; // Adelanta declaración

template <typename N_, typename E_>
struct traits {
    typedef N_ N;
    typedef E_ E;
    typedef traits<N_, E_> self;
    typedef GraphNode<self> node;
    typedef GraphEdge<self> edge;
};

#endif
