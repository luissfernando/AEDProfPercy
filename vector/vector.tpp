#include "vector.h"
#include <iostream>
#include <stdexcept>

template <typename T>
Vector<T>::Vector(int _capacity) {
  data = new T[_capacity];
  size = 0;
  capacity = _capacity;
}

template <typename T>
Vector<T>::Vector() {
  size = 0;
  capacity = 0;
  data = nullptr;
}

template <typename T>
Vector<T>::~Vector() {
  delete[] data;
}

template <typename T>
void Vector<T>::push_back(T item) {
  if (size == capacity) {
    if (capacity == 0)
      capacity = 1;
    else
      capacity = (5 * capacity + 3) / 4;

    T* tmp = data;
    data = new T[capacity];

    for (int i = 0; i < size; i++) {
      data[i] = tmp[i];
    }

    delete[] tmp;
  }

  data[size] = item;
  size++;
}

template <typename T>
void Vector<T>::remove_index(int idx) {
  if (idx < 0 || idx >= size)
    return;

  data[idx] = data[size - 1];
  size--;
}

template <typename T>
void Vector<T>::print() {
  for (int i = 0; i < size; i++) {
    std::cout << data[i] << " ";
  }
  std::cout << "\n";
}

template <typename T>
int Vector<T>::search(T item) {
  for (int i = 0; i < size; i++) {
    if (data[i] == item)
      return i;
  }
  return -1;
}

template <typename T>
T* Vector<T>::get_ptrData() {
  return data;
}

template <typename T>
void Vector<T>::swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
int Vector<T>::getSize() {
  return size;
}

template <typename T>
int Vector<T>::getCapacity() {
  return capacity;
}

template <typename T>
T& Vector<T>::operator[](int pos) {
  if (pos < 0 || pos >= size) {
    throw std::out_of_range("Indice fuera de rango");
  }
  return data[pos];
}
