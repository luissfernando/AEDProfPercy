#ifndef VECTOR_H
#define VECTOR_H

class Vector{
    int *data;
    int index;
    int capasity;
    public:
        Vector(int);
        Vector();
        ~Vector();
        void push_back(int);
        void remove_index(int);
        int search(int);
        void print();
        int *get_ptrData();
        void swap(int &a, int &b);
        void swapPtr(int *&a, int*&b);
        int getSize();
};
#endif // !VECTOR_H
