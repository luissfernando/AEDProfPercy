#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
//reserva memoria
int **reserveM(int rows, int cols){
    int **arr = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i)
        arr[i] = malloc(cols * sizeof(int));
    return arr;
}
//libera memoria 
void freeM(int **M, int rows){
    for (int i = 0; i < rows; ++i)
        free(M[i]);
}

//agrega 1 ala matriz
void valM(int **M,int rows,int cols){
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            M[i][j] = 1;
}

//imprime la matriz
void printM(int **M,int rows,int cols){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            printf("%d ", M[i][j]);
        putchar('\n');
    }
}

// si la matrix es simetrica
int IsSymmetric(int **M,int rows,int cols){
    for (int i = 0; i < rows; ++i)
        for (int j = i+1; j < cols; ++j)
            if (M[i][j] != M[j][i]) return 0;
    return 1;
}

//matriz transpuesta
void matrixT(int **M,int rows,int cols){
    for (int i = 0; i < rows; ++i)
        for (int j = i+1; j < cols; ++j) {
            int tmp    = M[i][j];
            M[i][j]    = M[j][i];
            M[j][i]    = tmp;
        }
}
//determinante de la matriz 3x3
int determinant3x3(int **M){
    int a = M[0][0], b = M[0][1], c = M[0][2];
    int d = M[1][0], e = M[1][1], f = M[1][2];
    int g = M[2][0], h = M[2][1], i = M[2][2];

    return a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g);
}

//producto de una matriz
int **producM(int **A,int r1,int c1, int **B,int r2,int c2){
    if (c1 != r2){
        printf("No se pueden multiplicar\n");
        return NULL;
    }
    int **P = reserveM(r1, c2);

    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c2; ++j){
            P[i][j] = 0;
            for (int k = 0; k < c1; ++k)
                P[i][j] += A[i][k] * B[k][j];
        }
    return P;
}
