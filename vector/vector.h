#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector{
    T *data;
    int size;
    int capacity;
    public:
        Vector(int);
        Vector();
        ~Vector();
        void push_back(T);
        void remove_index(int);
        int search(T);
        void print();
        T *get_ptrData();
        void swap(T &a, T &b);
        int getSize();
        int getCapacity();

        //sobrecarga
        T& operator[](int pos);
};

#include "vector.tpp"
#endif // !VECTOR_H
