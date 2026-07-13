#include <iostream>
#include "../vector/vector.h"
using namespace std;
namespace Sort{
    void swap (int &a,int &b){
      int tmp = a;
      a = b;
      b = tmp;
    }
    void bubbleSort(int *begin, int *end){
        for(int i = 0; i < end-begin ; i++){
            bool cambio = false;
            for(int j = 0; j < end-begin - i - 1; j++){
                if(*(begin+j) > *(begin+j + 1)){
                  Sort::swap(*(begin+j), *(begin + j + 1));
                    cambio = true;
                } 
            }
            if(!cambio) break;
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
        for(int i = 0; i < v->getSize() - 1; i++){
            int *minimo = data+i;
            for(int j = i; j < v->getSize()-i-1; j++){
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
      int i = low ;
        for(int j = low; j < high; j++){
            if(data[j] < pivot){
                v->swap(data[i], data[j]);
                i++;
            }
        }
        v->swap(data[i], data[high]);
        return i;
    }
    void quickSort(Vector *v, int low, int high){
        if(low < high){
            int pivotIndex = partition(v, low, high);
            quickSort(v, low, pivotIndex - 1);
            quickSort(v, pivotIndex + 1, high);
        }
    }

    //merge
    void merge(Vector *v, int left, int mid, int right){
        int *data = v->get_ptrData();
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int *L = new int[n1];
        int *R = new int[n2];
        for(int i = 0; i < n1; i++)
            L[i] = data[left + i];
        for(int i = 0; i < n2; i++)
            R[i] = data[mid + 1 + i];
        int i = 0;
        int j = 0;
        int k = left;
        while(i < n1 && j < n2){
            if(L[i] <= R[j])
                data[k++] = L[i++];
            else
                data[k++] = R[j++];
        }
        while(i < n1)
            data[k++] = L[i++];
        while(j < n2)
            data[k++] = R[j++];
        delete[] L;
        delete[] R;
    }
    void mergeSort(Vector *v, int left, int right){
        if(left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);
        merge(v, left, mid, right);
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
    
    Sort::bubbleSort();
    cout << "\nBubble Sort:\n";
    v->print();
    
    
    /*Sort::insertSort(v);
    cout << "\nInsert sort:\n";
    v->print();
    */
    
    /*Sort::selectionSort(v);
    cout << "\nSelection sort:\n";
    v->print();
    */
    
    /*Sort::quickSort(v, 0, v->getSize() - 1);
    cout << "\nQuick sort:\n";
    v->print(); 
    */

    /*Sort::mergeSort(v, 0, v->getSize() - 1);
    cout << "\nMerge sort:\n";
    v->print();
    */
}
