//LABORATORIO 1
//Luis Fernando Morales Tacca
#include <stdio.h>
// calula el producto de HADAMARD
void Vector_Hadamard(int *u, int *v, int *result, int size) {
  for (int i = 0; i < size; i++) {
    result[i] = u[i] * v[i];
  }
}
//PRODUCTO PUNTO
int Vector_Dot(int *u,int *v ,int size){
  int result=0;
  for (int i = 0; i < size; i++) {
    result += u[i] * v[i];
  }
  return result;
}
//imprime vectores
void printVect(int *vect,int size){
    printf("Producto de Hadamard:\n");
    for (int i = 0; i < size; i++) {
      printf("%d ", vect[i]);
    }
    printf("\n");
}
int main() {
  int size;
  int u[100], v[100], hadamard[100];
  printf("Tamaño del vector maximo 100  ");
  scanf("%d", &size);
  
  // si no cumple la restrincion de maximo 100 y numero positivo
  if (size > 100 || size <= 0) {
    printf("Valor invalido !!!\n");
    return 1;
  }
  printf("Ingrese los elementos del vector u => \n");
  for (int i = 0; i < size; i++) {
    scanf("%d", &u[i]);
  }

  printf("Ingrese los elementos del vector v => \n");
  for (int i = 0; i < size; i++) {
    scanf("%d", &v[i]);
  } 
  Vector_Hadamard(u, v, hadamard, size);
  printVect(hadamard,size);
  
  printf("Producto punto = %d\n",Vector_Dot(u,v,size));
  //Vector_Dot(u,v,size);
  return 0;
}
