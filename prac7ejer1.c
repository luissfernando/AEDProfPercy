#include <stdio.h>
#include <stdlib.h>
int* select_positive(const int* v, int n, int* size_positives) {
    //  for para saber el tamaño del primer arreglo
    for (int i = 0; i < n; i++) {
        if (v[i] >= 0) {
            (*size_positives)++; // *size_positives++
        }
    }
    //si el tamaño del segundo arreglo es mayor a 0 entonses hay numeros positivos
    if(*size_positives!=0){
        int *positives = malloc(*size_positives *(sizeof(int)));
        for(int i=0,j=0;i<n;i++){
            if(v[i] >=0){
                positives[j] = v[i];
                j++;
            }
        }
        return positives;
    }
}
int main() {
    int size_n=6; // tamaño del primer arreglo
    int v[] = {-1, 2, 0, 3, -5, 7};
    int size_positives=0; //tamaño del arreglo de positivos

    int* positives = select_positive(v, size_n, &size_positives);
    
    if(positives != NULL) {
        printf("%d\n ",size_positives);
        printf("Numeros posistivos : ");
        for (int i = 0; i < size_positives; i++) {
            printf("%d ", positives[i]);
        }
        printf("\n");
        free(positives);
    } else {
        printf("No hay numeros positivos.\n");
    }

    return 0;
}
