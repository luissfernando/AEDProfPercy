#ifndef MATRIX_H
#define MATRIX_H

//reserva  memoria para la matriz
int  **reserveM(int rows, int cols);
//libera memoria de la matrix
void freeM(int **M, int rows);

//llena con 1 la matriz
void valM   (int **M, int rows, int cols);

//imprime la matriz              
void printM (int **M, int rows, int cols);

/* operaciones */
int  IsSymmetric (int **M, int rows, int cols);          // 1 si simétrica
void matrixT     (int **M, int rows, int cols);          //transpuesta de una matriz
int  determinant3x3(int **M);                            // determinante de una matriz 3x3
int **producM(int **A,int r1,int c1, int **B,int r2,int c2); //producto de dos matrices A x B

#endif
