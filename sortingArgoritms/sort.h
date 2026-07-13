#ifndef SORT_H
#define SORT_H
namespace Sort {
template<typename T>
void swap(T& a, T& b){
    T tmp = a;
    a = b;
    b = tmp;
}
// bubble Sort
template<typename T>
void bubbleSort(T* begin, T* end){
    int n = end - begin;

    for(int i = 0; i < n - 1; i++){
        bool cambio = false;

        for(int j = 0; j < n - i - 1; j++){
            if(begin[j] > begin[j + 1]){
                swap(begin[j], begin[j + 1]);
                cambio = true;
            }
        }
        if(!cambio)
            break;
    }
}
// insertion Sort
template<typename T>
void insertSort(T* begin, T* end){
    for(T* i = begin + 1; i < end; i++){
        T* current = i;

        while(current > begin &&
              *current < *(current - 1)){
            swap(*current, *(current - 1));
            current--;
        }
    }
}

// selection Sort
template<typename T>
void selectionSort(T* begin, T* end){
    for(T* i = begin; i < end - 1; i++){
        T* minimo = i;
        for(T* j = i + 1; j < end; j++){
            if(*j < *minimo)
                minimo = j;
        }
        swap(*i, *minimo);
    }
}

// particion para quick sort
template<typename T>
T* partition(T* begin, T* end){
    T pivot = *(end - 1);
    T* i = begin;
    for(T* j = begin; j < end - 1; j++){
        if(*j < pivot){
            swap(*i, *j);
            i++;
        }
    }
    swap(*i, *(end - 1));
    return i;
}

// quickSort
template<typename T>
void quickSort(T* begin, T* end){
    if(end - begin <= 1)
        return;
    T* pivot = partition(begin, end);
    quickSort(begin, pivot);
    quickSort(pivot + 1, end);
}

// merge
template<typename T>
void merge(T* begin, T* mid, T* end){
    int n1 = mid - begin;
    int n2 = end - mid;
    T* left = new T[n1];
    T* right = new T[n2];
    for(int i = 0; i < n1; i++)
        left[i] = begin[i];
    for(int i = 0; i < n2; i++)
        right[i] = mid[i];
    int i = 0;
    int j = 0;
    T* current = begin;
    while(i < n1 && j < n2){
        if(left[i] <= right[j])
            *current++ = left[i++];
        else
            *current++ = right[j++];
    }
    while(i < n1)
        *current++ = left[i++];
    while(j < n2)
        *current++ = right[j++];
    delete[] left;
    delete[] right;
}

// merge sort
template<typename T>
void mergeSort(T* begin, T* end){

    if(end - begin <= 1)
        return;
    T* mid = begin + (end - begin) / 2;
    mergeSort(begin, mid);
    mergeSort(mid, end);
    merge(begin, mid, end);
}
}
#endif
