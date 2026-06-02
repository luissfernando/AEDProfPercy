#ifndef VECTOR_H
#define VECTOR_H
//template <typename T>
class Vector{
    int *data;
    int index;
    int capacity;
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
        int getSize();
        int getCapacity();

        //sobrecarga
        int& operator[](int pos);
};
#endif // !VECTOR_H
