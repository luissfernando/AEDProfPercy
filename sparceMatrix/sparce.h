#ifndef SPARCE_H
#define SPARCE_H

#include "node.h"  // Asegúrate de incluir el archivo de nodos
#include <iostream>
template <class T>
class Sparce {
public:
    Node<T>** v_columns;
    Node<T>** v_rows;
    unsigned rows_size, cols_size; 

    
    Sparce(unsigned x, unsigned y);
    bool find(Node<T>**& p, Node<T>**& q, int x, int y, T data);
    void insert(int pos_x, int pos_y, T data);
    void mostrar();
};

template <class T>
Sparce<T>::Sparce(unsigned x, unsigned y) {
    v_columns = new Node<T>*[x];
    v_rows = new Node<T>*[y];
    cols_size = x;
    rows_size = y;
    
}

template <class T>
bool Sparce<T>::find(Node<T>**& p, Node<T>**& q, int x, int y, T data) {
    p = &(v_columns[x]);
    q = &(v_rows[y]);
    while (*p && (*p)->data != data) {
        *p = (*p)->right;
    }
    while (*q && (*q)->data != data) {
        *q = (*q)->down;
    }
    return true;
}

template <class T>
void Sparce<T>::insert(int pos_x, int pos_y, T data) {
    Node<T> **p, **q;
    Node<T>* nuevo = new Node<T>(data);
    find(p, q, pos_x, pos_y, data);
    nuevo->right = *p;
    nuevo->down = *q;
    *p = nuevo;
    *q = nuevo;
}
template <class T>
void Sparce<T>::mostrar() {
    for (unsigned i = 0; i < rows_size; ++i) {
        Node<T>* cabecera = v_rows[i];
        Node<T>* actual = cabecera->right;

        std::cout << "Fila " << i << ": ";

        // Recorremos hasta volver al nodo cabecera
        while (actual != cabecera) {
            std::cout << actual->data << " -> ";
            actual = actual->right;
        }

        std::cout << "circular\n";
    }
}

#endif // SPARCE_H
