
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

            M[i][j] = 1;
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
int main() {

    int rows = 4, cols = 4;
    int **matrix;
    int **matrix2;
    int **product;
    matrix = reserveM(rows,cols);
    valM(matrix,rows,cols);
    //matrix[0][0] = 1;
    matrix[0][2]=-2;
    matrix[1][3]=1;
    matrix[2][0]=-1;
    matrix[3][1]=0;
    //printM(matrix,rows,cols);
    //if(IsSymmetric(matrix,rows,cols)){printf("Es simetrica\n");}
    //else{printf("No es simetrica\n");}
    matrixT(matrix,rows,cols);
    printf("matriz transpuesta\n");
    printM(matrix,rows,cols);
    //printf("determinante:%d\n ",determinant3x3(matrix));
    
    matrix2 = reserveM(rows,cols);
    valM(matrix2,rows,cols);
    printM(matrix2,rows,cols);
    product=producM(matrix,rows,cols,matrix2,rows,cols);
    printf("PRODUCTO\n");
    printM(product,rows,cols);
    
    //liberrar memoria
    freeM(matrix,rows);
    free(matrix);

    freeM(matrix2,rows);
    free(matrix2);
    freeM(product,rows);
    free(product);
    
    


    return 0;
}
