#ifndef VECTOR_H
#define VECTOR_H

class Vector{
    int *data;
    int index;
    int capasity;
    public:
        Vector(int);
        ~Vector();
        void add_item(int);
        void remove_index(int);
        int search(int);
        void print();
};
#endif // !VECTOR_H