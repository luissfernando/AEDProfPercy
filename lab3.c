//Permutation matrix
//Copy
//Reverse
//Compare
#include <stdio.h>
#include <stdlib.h>
//reserva memoria para la matriz
int** reserveM(int rows, int cols) {
    int **arr = malloc(rows * sizeof(int *));
    for(int i=0;i<rows;i++)
        arr[i] = malloc(cols * sizeof(int));
    return arr;

}
//imprime la  matriz
void printM(int **M,int rows,int cols){
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

}
//libera memoria del array de punteros
void freeM(int **M,int rows){
     // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(M[i]);
    }
}
//llena con ceros la matriz para luego ser agregado los 1 en la funcion main
void valM(int **M,int rows,int cols){
     // Initialize the matrix with values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            M[i][j] = 0;
        }
    }
}
//EJERCISE 1
//busca en la matriz de un valor sus coincidencias de 1 tanto en su fila y columna
int search_filas_columnas(int **M, int rows, int cols, int fila, int col) {
  // Busca otro 1 en la misma fila 
    for (int j = 0; j < cols; j++) {
        if (j != col && M[fila][j] == 1) {
            printf("Otro 1 en fila %d, columna %d\n", fila+1, j+1);
            return 1;
        }
    }

  // Busca otro 1 en la misma columna (distinta fila)
    for (int i = 0; i < rows; i++) {
        if (i != fila && M[i][col] == 1) {
            printf("Otro 1 en fila %d, columna %d\n", i+1, col+1);
            return 1;
        }
    }
    return 0;
}
//funcion si la matriz es permutada
int isMatrixPermut(int **M, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (M[i][j] == 1) {
                printf("Primer 1 en [%d][%d]\n", i+1, j+1);
                if(search_filas_columnas(M, rows, cols, i, j)){
                    printf("No es matrix permutacion\n");
                    return 0;
                }
            }
        }
    }
    printf("Si es matriz permutacion\n");
    return 1;
}

//EXERCICE 2
//copia una cadena a otra
void copy(char *str1, char *str2) {
    while (*str1 != '\0') {
        *str2 = *str1;
        str1++;
        str2++;
    }
    *str2 = '\0';
}
//imprime la cadena
void printS(char*str){
    while (*str!='\0'){
        printf("%c",*str);
        str++;
    }
    printf("\n");
}

//EXERCICE 3
//reversa de una cadena a nibel de bits con el XOR
void reverseStr(char *str){
    int endChar=0;
    int firstChar=0;
    while(*str!='\0'){
        endChar++;
        str++;
    }
    str = str-endChar;
    endChar--;
    int totalIteraciones = endChar/2;
    while(firstChar<endChar){
        //intercambio a nivel de bits 
        str[firstChar] = str[firstChar] ^ str[endChar];
        str[endChar] = str[ firstChar] ^ str[endChar];
        str[firstChar] = str[firstChar] ^ str[endChar];

        firstChar++;
        endChar--;
    }
}

//EXERCICE 4
//comprar con el codigo ascii dos caracteres < > o 0 
int compare(char str1[], char str2[]) {
    int i=0;
    for(i;str1[i] != '\0',str2[i] != '\0';i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    return str1[i] - str2[i];
}
int main() {

    // int rows = 4, cols = 4;
    // int **matrix;
    // matrix = reserveM(rows,cols);
    // valM(matrix,rows,cols);
    // //matrix[0][0] = 1;
    // matrix[0][2]=1;
    // matrix[1][3]=1;
    // matrix[2][0]=1;
    // matrix[3][1]=1;
    
    // isMatrixPermut(matrix,rows,cols);
    // printM(matrix,rows,cols);

    // freeM(matrix,rows);
    // free(matrix);
    
    char string1[] = "computer science";
    char stringcopy[100]; 
    copy(string1,stringcopy);
    printf("cadena :");
    printS(string1);
    printf("cadena copia : ");
    printS(stringcopy);

    reverseStr(string1);
    printf("cadena con reverse: ");
    printS(string1);

    printf("%d\n", compare("computacion", "computacion"));   
    printf("%d\n", compare("ab", "ac"));       
    printf("%d\n", compare("zzzaa", "aaaaa")); 


    return 0;
}
