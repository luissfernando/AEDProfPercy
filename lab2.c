//PRACTICE 2
#include <stdio.h>
#include <stdlib.h>
int abs(int val){
    if(val<0)
        return -val;
    return val;
}
//EJER 1
//enumera la cantidad de digitos
int is_n_digit(int val, int digit) {
    val = abs(val);
    if (digit == 0)
        return val == 0;
    if (val == 0)
        return 0;
    return is_n_digit(val / 10, digit - 1);
}

void digit_number_4(int val){
    if(is_n_digit((val),4)){
        int firstV = val/100;
        int seconV = val%100;
        if((firstV+seconV)*(firstV+seconV) == val)
            printf("El valo %d si cumple la propiedad \n RESULTADO:\n %d + %d = (%d)**2 = %d  \n ",val,firstV,seconV,firstV+seconV,val);
        else{
            printf("no cumple la propiedaa\n");
        }
    }
    else{
        printf("no es un numero de 4 digitos\n");
    }
}
//EJER 2
// Calcula 10^n
int pow_10(int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++)
        result *= 10;
    return result;
}
// Invierte un número
int reverseNum(int val) {
    int rev = 0;
    while (val != 0) {
        rev = rev * 10 + val % 10;
        val /= 10;
    }
    return rev;
}
int isCapicua(int val) {
    val = abs(val);
    int tmp = val;
    int sizeVal = 0;
    // cantidad de dígitos
    while (tmp != 0) {
        tmp /= 10;
        sizeVal++;
    }
    // separar en dos mitades y compararlas
    int firstV, endValue;
    if (sizeVal % 2 == 0) {
        // Número par de cifras
        int mitad = sizeVal / 2;
        firstV = val / pow_10(mitad);
        endValue = val % pow_10(mitad);
    } else {
        // Número impar de cifras, ignoramos el dígito central
        int mitad = sizeVal / 2;
        firstV = val / pow_10(mitad + 1);
        endValue = val % pow_10(mitad);
    }

    if (firstV == reverseNum(endValue)) {
        printf("el numero %d es capicua\n",val);
        return 1;
    } else {
        printf("el numero %d no es capicua\n",val);
        return 0;
    }
}
// EJER 3:
void XOR(){
    int x = 3, y = 4;

    printf("Antes del intercambio: x = %d, y = %d\n", x, y);

    // intercambio usando XOR
    x = x ^ y;  // x se convierte en 1 (en binario: 101 ^ 100) => 001
    y = x ^ y;  // y se convierte en 3 (001 ^ 100) => 101
    x = x ^ y;  // x se convierte en 4 (001 ^ 101) => 100
    printf("Después del intercambio: x = %d, y = %d\n", x, y);

}

//EJER 4
void readI(){
    int op;
    float x, y;
    do {
        printf("\nEselccione la operacion:\n");
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("5. Salir\n");
        printf("Ingresa una opcion: ");
        scanf("%d", &op);
        if (op >= 1 && op <= 4) {
            printf("Ingrese dos numeros: ");
            scanf("%f %f", &x, &y);
            switch (op) {
                case 1:
                    printf("Suma : %.2f\n", x + y);
                    break;
                case 2:
                    printf("Resta : %.2f\n", x - y);
                    break;
                case 3:
                    printf("Multiplicaion : %.2f\n", x * y);
                    break;
                case 4:
                    if (y != 0)
                        printf("divicion: %.2f\n", x / y);
                    else
                        printf("Error divion entre cero!!!\n");
                    break;}
        } else if (op != 5) {
            printf("opcion no valida.\n");
        }
    } while (op != 5);
}
//EJER 5
void readList() {
    int size;
    int val, min, max,diff;
    printf("Tamanio de la cantidad e numeros? ");
    scanf("%d", &size);
    printf("Valor 1 : ");
    scanf("%d", &val);
    min = max = val;
    int i=2;
    while(i<= size){
        printf("Valor %d: ", i);
        scanf("%d", &val);
        if (val < min) min = val;
        if (val > max) max = val;
        i++;
    }
    diff = max - min;
    diff = abs(diff);  
    printf("Minimo: %d\n", min);
    printf("Mayor: %d\n", max);
    printf("diferencia abs: %d\n", diff);
}

//EJER 6
// verifica si un elemento es repetido
int repeat(int arr[], int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val)
            return 1;
    }
    return 0;
}
//reservar memoria
int* reserveM(int size) {
    int* arr = (int*)malloc(sizeof(int) * size);
    return arr;
}
// mostrar arrays
void printSet(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//ingrea el array
void getArray(int *arr,int size){
    for (int i = 0; i < size; i++) {
        printf("Elemento %d : ", i + 1);
        scanf("%d" , &arr[i]);
    }
}
int* intersection(int a[], int sizeA, int b[], int sizeB, int* resultSize) {
    int* result = NULL;
    *resultSize = 0;

    for (int i = 0; i < sizeA; i++) {
        if (repeat(b, sizeB, a[i]) && !repeat(result, *resultSize, a[i])) {
            result = realloc(result, (*resultSize + 1) * sizeof(int));
            result[*resultSize] = a[i];
            (*resultSize)++;
        }
    }
    return result;
}
int* unionSet(int a[], int sizeA, int b[], int sizeB, int* resultSize) {
    int* result = NULL;
    *resultSize = 0;
    for (int i = 0; i < sizeA; i++) {
        if (!repeat(result, *resultSize, a[i])) {
            result = realloc(result, (*resultSize + 1) * sizeof(int));
            result[*resultSize] = a[i];
            (*resultSize)++;
        }
    }
    for (int i = 0; i < sizeB; i++) {
        if (!repeat(result, *resultSize, b[i])) {
            result = realloc(result, (*resultSize + 1) * sizeof(int));
            result[*resultSize] = b[i];
            (*resultSize)++;
        }
    }
    return result;
}

int* difference(int a[], int sizeA, int b[], int sizeB, int* resultSize) {
    int* result = NULL;
    *resultSize = 0;
    for (int i = 0; i < sizeA; i++) {
        if (!repeat(b, sizeB, a[i]) && !repeat(result, *resultSize, a[i])) {
            result = realloc(result, (*resultSize + 1) * sizeof(int));
            result[*resultSize] = a[i];
            (*resultSize)++;
        }
    }
    return result;
}
int main() {
        int *set1, *set2;
        int size1, size2;
        printf("Tamaño del array 1 : ");
        scanf("%d", &size1);
        set1 = reserveM(size1); 
        getArray(set1, size1);
    
        printf("Tamaño del array 2 : ");
        scanf("%d", &size2);
        set2 = reserveM(size2); 
        getArray(set2, size2);
    
        int sizeInter, sizeUnion, sizeDiff;
        int *inter = intersection(set1, size1, set2, size2, &sizeInter);
        int *uni = unionSet(set1, size1, set2, size2, &sizeUnion);
        int *diff = difference(set1, size1, set2, size2, &sizeDiff);
    
        printf("La intersección es: ");
        printSet(inter, sizeInter);
    
        printf("La unión es: ");
        printSet(uni, sizeUnion);
    
        printf("La diferencia es: ");
        printSet(diff, sizeDiff);
    
        free(set1);
        free(set2);
        free(inter);
        free(uni);
        free(diff);
    
        return 0;

}
