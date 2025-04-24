#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(){
    int rows = 4, cols = 4;
    int **mat  = reserveM(rows, cols);
    int **mat2 = reserveM(rows, cols);

    valM(mat,  rows, cols);
    valM(mat2, rows, cols);

    mat[0][2] = -2;
    mat[1][3] =  1;
    mat[2][0] = -1;
    mat[3][1] =  0;

    puts("Matriz original:");
    printM(mat, rows, cols);

    if (IsSymmetric(mat,rows,cols))
        puts("Es simétrica");
    else
        puts("No es simétrica");

    matrixT(mat, rows, cols);
    puts("\nTranspuesta:");
    printM(mat, rows, cols);

    int **prod = producM(mat, rows, cols, mat2, rows, cols);
    if (prod){
        puts("\nProducto:");
        printM(prod, rows, cols);
    }

    /* liberar memoria */
    freeM(mat, rows);   free(mat);
    freeM(mat2, rows);  free(mat2);
    if (prod){ freeM(prod, rows); free(prod); }

    return 0;
}
