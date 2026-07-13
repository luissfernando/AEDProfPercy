#include <iostream>
#include "../vector/vector.h"
#include "sort.h"

int main(){
    Vector v;

    v.push_back(20);
    v.push_back(3);
    v.push_back(2);
    v.push_back(17);
    v.push_back(8);

    std::cout <<"vector inicial\n";
    v.print();

    /*Sort::bubbleSort(
        v.get_ptrData(),
        v.get_ptrData() + v.getSize()
    );
    */

    /*Sort::insertSort(
        v.get_ptrData(),
        v.get_ptrData() + v.getSize());
    */
    
    /*Sort::selectionSort(
        v.get_ptrData(),
        v.get_ptrData() + v.getSize()
    );
    */

    /*Sort::cocktailSort(
        v.get_ptrData(),
        v.get_ptrData() + v.getSize()
     );
    */

    /*Sort::shellSort(
        v.get_ptrData(),
        v.get_ptrData() + v.getSize()
     );
    */
    
    Sort::quickSort(
        v.get_ptrData(),
        v.get_ptrData() + v.getSize()
    );
    
    
    /*Sort::mergeSort(
        v.get_ptrData(),
        v.get_ptrData() + v.getSize()
    );
    */
    std::cout << "\nOrdenado\n";
    v.print();

    return 0;
}
