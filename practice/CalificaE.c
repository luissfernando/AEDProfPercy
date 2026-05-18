#include <stdio.h>
#include <stdlib.h>

struct NotasClase {
    int cantidadEstudiantes;
    float *notas;
};

void ingresarNotas(struct NotasClase *clase) {
    printf("Ingrese la cantidad de estudiantes: ");
    scanf("%d", &clase->cantidadEstudiantes);
    clase->notas = (float *)malloc(clase->cantidadEstudiantes * sizeof(float));
    for (int i = 0; i < clase->cantidadEstudiantes; i++) {
        printf("Ingrese la nota del estudiante %d: ", i + 1);
        scanf("%f", &clase->notas[i]);
    }
}

float buscarNotaMayor(struct NotasClase clase) {
    float mayor = clase.notas[0];
    for (int i = 1; i < clase.cantidadEstudiantes; i++) {
        if (clase.notas[i] > mayor) {
            mayor = clase.notas[i];
        }
    }

    return mayor;
}
void mostrarNotaMayor(float notaMayor) {
    printf("La nota mayor es: %.2f\n", notaMayor);
}
int main() {
    struct NotasClase clase;
    float notaMayor;
    ingresarNotas(&clase);
    notaMayor = buscarNotaMayor(clase);
    mostrarNotaMayor(notaMayor);
    free(clase.notas);

    return 0;
}
