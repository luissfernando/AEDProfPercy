#include "vector.h"
#include <iostream>
Vector::Vector(int size){
    this->data = new int[size];
    this->index = 0;
    this->capasity = size;
}
void Vector::add_item(int item){
    if(index == capasity){
        int *tmp = data;
        capasity*=2;
        data = new int[capasity];
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
}
int Vector::search(int item){
    for(int i=0;i<index;i++){
        if(data[i]==item){
            return i+1;
        }
    }
    return -1;
}