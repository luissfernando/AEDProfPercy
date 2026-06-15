#include "vector.h"
#include <iostream>
#include <stdexcept>

Vector::Vector(int size){
    this->data = new int[size];
    this->index = 0;
    this->capacity = size;
}
Vector::Vector(){
  index=capacity=0;
  data = nullptr;
}
void Vector::push_back(int item){
    if(index == capacity){
        if(capacity == 0) capacity = 1;
        int *tmp = data;
        capacity = (5 * capacity +3)/4 ; //aumenta  en su 25%
        data = new int[capacity];
        for(int i=0;i<index;i++){
            data[i] = tmp[i];
        }
        delete []tmp;
    }
    data[index] = item;
    index++;
}
void Vector::remove_index(int idx){
    if(idx < index){
        data[idx-1] = data[index-1];
        index--;
    }
    if(idx==1 && index==1){
        index--;
    }
}                           
void Vector::print(){
    for(int i=0;i<index;i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<"\n";
}
int Vector::search(int item){
    for(int i=0;i<index;i++){
        if(data[i]==item){
            return i+1; 
        }
    }
    return -1;
}
int* Vector::get_ptrData(){
  return data;
}
void Vector::swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int Vector::getSize(){
  return index;
}
int Vector::getCapacity(){
  return capacity;
}

//sobrecarga 
int& Vector::operator[](int pos){
  if(pos < 0 || pos > index ){
    throw std::out_of_range("Indice fuera de rango");
  }
  return data[pos];
}

Vector::~Vector(){
  delete []data;
}
