#include <iostream>
#include "../vector/vector.h"
using namespace std;
namespace Sort{
    void bubbleSort(Vector* v){
        int* data = v->get_ptrData();
        for(int i = 0; i < v->getSize() - 2; i++){
            bool cambio = false;
            for(int j = 0; j < v->getSize() - i - 2; j++){
                if(*(data+j) > *(data+j + 1)){
                    v->swap(*(data+j), *(data + j + 1));
                    cambio = true;
                } 
            }
            if(cambio == true) return;
        }
    }
      // insert sort
    void insertSort(Vector *v){
        int* data = v->get_ptrData();
        for(int i=1;i<v->getSize()-1;i++){
            int *key = data+i;
            while( key!=data && *(key) < *(key-1)){
                v->swap(*key,*(key-1));
                key--;
            }
        }
    }

    // selection sort
    void selectionSort(Vector *v){
        int *data = v->get_ptrData();
        for(int i = 0; i < v->getSize() - 2; i++){
            int *minimo = data+i;
            for(int j = i; j < v->getSize()-i-2; j++){
                if( *minimo > *(data+j) ){
                    minimo = data+j;
                }
            }
            v->swap( *minimo, *(data+i));
        }
    }
    int partition(Vector *v, int low, int high){
      int* data = v->get_ptrData();
      int pivot = data[high];
      int i = low - 1;
        for(int j = low; j < high; j++){
            if(data[j] < pivot){
                i++;
                v->swap(data[i], data[j]);
            }
        }
        v->swap(data[i + 1], data[high]);
        return i + 1;
    }
    void quickSort(Vector *v, int low, int high){
        if(low < high){
            int pivotIndex = partition(v, low, high);
            quickSort(v, low, pivotIndex - 1);
            quickSort(v, pivotIndex + 1, high);
        }
    }
}

int main(){

    Vector *v = new Vector();
    v->push_back(20);
    v->push_back(3);
    v->push_back(2);
    v->push_back(17);

    cout << "Original:\n";
    v->print();
    
    /*Sort::bubbleSort(v);
    cout << "\nBubble Sort:\n";
    v->print();
    */
    
    /*Sort::insertSort(v);
    cout << "\nInsert sort:\n";
    v->print();
    */
    
    /*Sort::selectionSort(v);
    cout << "\nSelection sort:\n";
    v->print();
    */
    Sort::quickSort(v, 0, v->getSize() - 2);
    cout << "\nQuick sort:\n";
    v->print();
}
