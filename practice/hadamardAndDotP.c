//Luis Fernando Morales Tacca
#include <stdio.h>
#define VAL_MAXIMO 100
// calula el producto de HADAMARD
void Vector_Hadamard(int *u, int *v, int *result, int size) {
  for (int i = 0; i < size; i++) {
    *(result+i) = *(u+i) * *(v+i);
  }
}
//PRODUCTO PUNTO
int Vector_Dot(int *u,int *v ,int size){
  int result=0;
  for (int i = 0; i < size; i++) {
    result += *(u+i) * *(v+i);
  }
  return result;
}
//imprime vectores
void printVect(int *vect,int size){
    printf("Producto de Hadamard:\n");
    for (int i = 0; i < size; i++) {
      printf("%d ", *(vect+i));
    }
    printf("\n");
}
void readVector(int *vect, int size){
  printf("Ingrese los elementos del vector:\n");

  for(int i = 0; i < size; i++){
    printf("Valor %d: ", i + 1);
    scanf("%d", & *(vect+i));
  }
}
int main() {
  int size;
  int u[VAL_MAXIMO], v[VAL_MAXIMO], hadamard[VAL_MAXIMO];
  printf("Tamaño del vector maximo 100:   ");
  scanf("%d", &size);
  
  // si no cumple la restrincion de maximo 100 y numero positivo
  if (size > VAL_MAXIMO || size <= 0) {
    printf("Valor invalido !!!\n");
    return 1;
  }
  readVector(u,size);
  readVector(v,size);
  Vector_Hadamard(u, v, hadamard, size);
  printVect(hadamard,size);
  
  printf("Producto punto = %d\n",Vector_Dot(u,v,size));
  return 0;
}
