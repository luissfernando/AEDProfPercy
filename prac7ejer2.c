#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// llena valores aleatorios entre 0.0 y 10.0
void fill_matrix3D_random(double*** matrix, int m, int n, int k) {
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < k; l++) {
                matrix[i][j][l] = (double)rand() / RAND_MAX * 10.0;
            }
        }
    }
}
//imprime matriz
void print_3d_matrix(double*** matrix, int m, int n, int k) {
    printf("Matriz 3d\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < k; l++) {
                printf("%.2f ", matrix[i][j][l]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

//reserva memoria para una matriz de  m x n x k
double*** reservM_three_dimensional(int m, int n, int k) {
    double*** matrix = malloc(m * sizeof(double**));
    for (int i = 0; i < m; i++) {
        matrix[i] = malloc(n * sizeof(double*));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = malloc(k * sizeof(double));
                    
        }
    }
    return matrix;
}

// liberar memoria
void free_matrix3D(double*** matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int m = 2, n = 3, k = 4;
    double*** M = reservM_three_dimensional(m, n, k);
    fill_matrix3D_random(M,m,n,k);
    print_3d_matrix(M,m,n,k);

    // Liberar la memoria al final
    free_matrix3D(M, m, n);

    return 0;
}
