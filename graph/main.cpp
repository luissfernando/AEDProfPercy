#include <iostream>
#include "graph.h"
using namespace std;

// Definir el trait específico del grafo: nodos string, pesos int
typedef traits<string, int> MyGraphTraits;
typedef Graph<MyGraphTraits> MyGraph;
typedef MyGraphTraits::node Node;
typedef MyGraphTraits::edge Edge;

int main() {
    MyGraph g;

    // Agregar nodos
    g.add_node("A");
    g.add_node("B");    
    g.add_node("C");

    // Agregar aristas (A-B con peso 5, B-C con peso 3)
    g.add_edge("A", "B", 5);
    g.add_edge("B", "C", 3);

    // Mostrar adyacencia
    cout << "Lista de adyacencia:\n";
    for (auto v : g.vertices) {
        cout << v->data << ": ";
        for (auto e : v->adjacency) {
            Node* n1 = e->nodes[0];
            Node* n2 = e->nodes[1];
            string other = (n1 == v) ? n2->data : n1->data;
            cout << "--" << e->data << "--> " << other << "   ";
        }
        cout << "\n";
    }

    return 0;
}
