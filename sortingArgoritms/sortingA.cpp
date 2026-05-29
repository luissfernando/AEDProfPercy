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
    /*void selectionSort(vector<int>& v){

        int n = v.size();

        for(int i = 0; i < n - 1; i++){

            int minIndex = i;

            for(int j = i + 1; j < n; j++){

                if(v[j] < v[minIndex]){

                    minIndex = j;

                }

            }

            swap(v[i], v[minIndex]);

        }

    }
  */
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
    Sort::insertSort(v);
    cout << "\nInsert sort:\n";
    v->print();
    

}
