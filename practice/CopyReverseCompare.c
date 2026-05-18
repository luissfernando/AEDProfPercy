#include <stdio.h>
#include <stdlib.h>
void crear(int ***M,int n){ // & referencias  no existen en c
  *M = malloc(sizeof(int*) * n);
  for (int i = 0; i < n; i++) {
    *(*M+i) = malloc(sizeof(int) * n);
  }
}
void insert(int **M, int n){
  for (int i = 0; i < n ;i++) {
    for(int j =0 ;j<n;j++){
      scanf("%d",&M[i][j]);
    }
  }
}
void mostrar(int **M,int n){
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }
}
void copy(int **M, int ***N, int n){
  crear(N, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      (*N)[i][j] = M[i][j];
    }
  }
}
void reverse(int **M, int n){
  int temp;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n/2; j++){

      temp = M[i][j];
      M[i][j] = M[i][n-1-j];
      M[i][n-1-j] = temp;

    }
  }
}
int compare(int **M, int **N, int n){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(M[i][j] != N[i][j]){
        return 0;
      }
    }
  }

  return 1;
}
int main(int argc, char *argv[])
{
  int cuadradaOrde = 2;
  int **M, **N;
  crear(&M, cuadradaOrde);
  insert(M, cuadradaOrde);
  copy(M, &N, cuadradaOrde);
  printf("Matriz original:\n");
  mostrar(M, cuadradaOrde);
  reverse(N, cuadradaOrde);
  printf("Matriz invertida:\n");
  mostrar(N, cuadradaOrde);
  if(compare(M, N, cuadradaOrde)){
    printf("Son iguales\n");
  }else{
    printf("Son diferentes\n");
  }
  return 0;
}
