#ifndef SET_H
#define SET_H

class Set {
private:
    int data[100];
    int size;
    bool contains(int value) const;
public:
    Set();
    bool add(int value);
    int getSize() const;
    Set setUnion(const Set& other) const;
    Set intersection(const Set& other) const;
    Set difference(const Set& other) const;
    void print() const;
};

#endif
