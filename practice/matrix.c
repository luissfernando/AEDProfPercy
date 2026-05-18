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
void valM(int **M,int rows,int cols){
     // Initialize the matrix with values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            M[i][j] = 1;
        }
    }
}
void zerosM(int **M,int rows,int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            M[i][j] = 0;
        }
    }
}
//EXERCICE 2
//returna 1 si es simetrica o 0 si no lo es
int IsSymmetric(int **M,int rows,int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = i+1; j < cols; j++) {
            if (M[i][j] != M[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}
//EXERCICE 3
// transpuesta de una matriz swap entre filas y columnas
void matrixT(int **M,int rows,int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = i+1; j < cols; j++) {
            M[i][j] = M[i][j] ^ M[j][i];
            M[j][i] = M[i][j] ^ M[j][i];
            M[i][j] = M[i][j] ^ M[j][i];
        }
    }
}
//EXERCICE 4
//determinante de la matriz
int determinant3x3(int **M) {
    int a = M[0][0], b = M[0][1], c = M[0][2];
    int d = M[1][0], e = M[1][1], f = M[1][2];
    int g = M[2][0], h = M[2][1], i = M[2][2];

    return a * (e * i - f * h)
         - b * (d * i - f * g)
         + c * (d * h - e * g);
}
//EXERCICE 5
//multiplicaion de la matrz
int **producM(int **M,int rows,int cols, int **N,int rows2,int cols2){
    int** producM = reserveM(rows,cols2);
    if(cols == rows2){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols2;j++){
                producM[i][j] = 0;
                for(int k=0;k<cols;k++){
                    producM[i][j] += M[i][k] * N[k][j];
                }
            }
        }
        return producM;
    }
    else{
        printf("no es posible\n");
        return 0;
    }
}
//matriz donde no deba tener mas de 1 en una fila como en una columnas
int matrixPermutacion(int **M,int n){ // por que es cuadrada
  for(int i=0;i<n;i++){
    int sumFilas=0;
    int sumColum=0;
    for(int j=0;j<n;j++){
      sumFilas += M[i][j];
      sumColum += M[j][i];
    }
    if(sumColum != 1 || sumFilas != 1){
      return 0;
    }
  }
  return 1;
}

int main() {

    int rows = 4, cols = 4;
    int **matrix;
    matrix = reserveM(rows,cols);
    zerosM(matrix,rows,cols);
    matrix[0][1]=1;
    matrix[1][0]=1;
    matrix[2][2]=1;
    matrix[3][3]=1;
    printM(matrix,rows,cols);
    printf("%d",matrixPermutacion(matrix,4));

    return 0;
}
