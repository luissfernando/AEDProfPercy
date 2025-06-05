#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Bandera para optimizar el algoritmo si ya está ordenado
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            // Intercambiar si el elemento actual es mayor que el siguiente
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Si no se hizo ningún intercambio, el arreglo ya está ordenado
        if (!swapped)
            break;
    }
}
void imprimirArreglo(int *arr, int n) {
    for (int i = 0; i < n; i++)
        cout << *(arr+i) << " ";
    cout << endl;
}
int main(int argc, char const *argv[])
{
    int arreglo[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    cout << "Arreglo original: ";
    imprimirArreglo(arreglo, n);

    bubbleSort(arreglo, n);

    cout << "Arreglo ordenado: ";
    imprimirArreglo(arreglo, n);
    return 0;
}

