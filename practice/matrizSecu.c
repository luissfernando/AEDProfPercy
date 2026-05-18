#include <stdio.h>

int main() {

    int n = 4;
    int num = 0;
    int M[4][4];

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            // Solo llenar diagonal principal y diagonales vecinas
            if(i == j || i == j + 1 || j == i + 1) {

                M[i][j] = num;
                num++;

            } else {

                M[i][j] = 0;
            }
        }
    }

    // Ajustar para que coincida exactamente con tu ejemplo
 //   M[0][0] = 0;

    // Mostrar matriz
    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {
            printf("%d ", M[i][j]);
        }

        printf("\n");
    }

    return 0;
}
