#ifndef SPARCE_H
#define SPARCE_H

#include "node.h"
#include <iostream>

template <class T>
class Sparce {
public:
    Node<T>** v_columns;
    Node<T>** v_rows;

    unsigned rows_size;
    unsigned cols_size;

    Sparce(unsigned cols, unsigned rows);

    void insert(int x, int y, T data);

    void mostrar();
};

template <class T>
Sparce<T>::Sparce(unsigned cols, unsigned rows) {

    cols_size = cols;
    rows_size = rows;

    v_columns = new Node<T>*[cols_size];
    v_rows = new Node<T>*[rows_size];

    for(unsigned i=0;i<cols_size;i++)
        v_columns[i]=nullptr;

    for(unsigned i=0;i<rows_size;i++)
        v_rows[i]=nullptr;
}

template<class T>
void Sparce<T>::insert(int x,int y,T data){
    Node<T>* nuevo=new Node<T>(data);
    nuevo->right=v_rows[y];
    v_rows[y]=nuevo;
    nuevo->down=v_columns[x];
    v_columns[x]=nuevo;
}

template<class T>
void Sparce<T>::mostrar(){
    for(unsigned i=0;i<rows_size;i++){
        std::cout<<"Fila "<<i<<": ";
        Node<T>* actual=v_rows[i];
        while(actual){
            std::cout<<actual->data;
            actual=actual->right;
            if(actual)
                std::cout<<" -> ";
        }
        std::cout<<std::endl;
    }
}

#endif
