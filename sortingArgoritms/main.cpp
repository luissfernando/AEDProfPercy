#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib> 

using namespace std;
using namespace std::chrono;
//############### burbuja ####################
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
//############# insertion #################
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];     
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;    
    }
}
//############## selection ##############
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Intercambiar el mínimo encontrado con el primer elemento no ordenado
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

//############## quick-sort #######################
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Intercambio arr[i] con arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high); 
    }
}
//########## merge-sort ####################
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[1000];
    int R[1000];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        // Ordenar ambas mitades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Combinar
        merge(arr, left, mid, right);
    }
}


// llenar el array con numeros de mayor a menor para ordenarlos
int* agregarNInvertido(int size){
    int *tmp = new int[size];
    for(int i=0;i<size;i++){
        tmp[i] = size-i;
    }
    return tmp;
}
//imprimir arrary
void imprimirArreglo(int *arr, int n) {
    for (int i = 0; i < n; i++)
        cout << *(arr+i) << " ";
    cout << endl;
}

// int main(int argc, char const *argv[]){
//     // int arreglo[] = {64, 34, 25, 12, 22, 11, 90};
//     int size = 10;
//     int *arr = agregarNInvertido(size);
//     cout << "Arreglo original: ";
//     imprimirArreglo(arr, size);

//     mergeSort(arr,0,size-1);

//     cout << "Arreglo ordenado: ";
//     imprimirArreglo(arr,size);
//     return 0;
// }

void copiarArreglo(int origen[], int destino[], int n) {
    for (int i = 0; i < n; i++) destino[i] = origen[i];
}
void crearArregloInvertido(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

int main() {
    ofstream archivo("resultados.csv");
    archivo << "N,BubbleSort,InsertionSort,SelectionSort,QuickSort,MergeSort\n";

    const int maxN = 4000;
    int original[maxN], copia[maxN];

    for (int n = 200; n <= maxN; n += 200) {
        crearArregloInvertido(original, n);
        archivo << n;

        // // Bubble Sort
        // copiarArreglo(original, copia, n);
        // auto start = high_resolution_clock::now();
        // bubbleSort(copia, n);
        // auto end = high_resolution_clock::now();
        // archivo << "," << duration_cast<milliseconds>(end - start).count();

        // // Insertion Sort
        // copiarArreglo(original, copia, n);
        // start = high_resolution_clock::now();
        // insertionSort(copia, n);
        // end = high_resolution_clock::now();
        // archivo << "," << duration_cast<milliseconds>(end - start).count();

        // // Selection Sort
        // copiarArreglo(original, copia, n);
        // start = high_resolution_clock::now();
        // selectionSort(copia, n);
        // end = high_resolution_clock::now();
        // archivo << "," << duration_cast<milliseconds>(end - start).count();
        
        //Quick Sort
        copiarArreglo(original, copia, n);
        auto start = high_resolution_clock::now();
        quickSort(copia, 0, n - 1);
        auto end = high_resolution_clock::now();
        archivo << "," << duration_cast<milliseconds>(end - start).count();

        // Merge Sort
        copiarArreglo(original, copia, n);
        start = high_resolution_clock::now();
        mergeSort(copia, 0, n - 1);
        end = high_resolution_clock::now();
        archivo << "," << duration_cast<milliseconds>(end - start).count();

        archivo << "\n";
        cout << "Completado tamaño: " << n << endl;
    }

    archivo.close();
    // cout << "CSV generado como 'resultados.csv'" << endl;

    return 0;
}