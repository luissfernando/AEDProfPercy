#include <iostream>
#include "Set.h"
using namespace std;
Set::Set() {
    size = 0;
}

bool Set::contains(int value) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return true;
        }
    }
    return false;
}

// insert
bool Set::add(int value) {
    if (contains(value)) {
        return false;
    }
    if (size >= 100) {
        return false;
    }
    data[size++] = value;
    return true;
}

// tamaño
int Set::getSize() const {
    return size;
}

// unión
Set Set::setUnion(const Set& other) const {
    Set result;
    for (int i = 0; i < size; i++) {
        result.add(data[i]);
    }
    for (int i = 0; i < other.size; i++) {
        result.add(other.data[i]);
    }
    return result;
}

// intersección
Set Set::intersection(const Set& other) const {
    Set result;
    for (int i = 0; i < size; i++) {
        if (other.contains(data[i])) {
            result.add(data[i]);
        }
    }
    return result;
}

// diferencia
Set Set::difference(const Set& other) const {
    Set result;
    for (int i = 0; i < size; i++) {
        if (!other.contains(data[i])) {
            result.add(data[i]);
        }
    }
    return result;
}

// imprimir
void Set::print() const {
    cout << "{ ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << "}" << endl;
}
