#include <stdio.h>
#define MAX(A,B) (A > B) ? A : B

int power(int a,int b){
  int cont = 1;
  for (int i=0;i<b;i++) {
    cont = a * cont;
  }
  return cont;
}

int isPrimo(int n){
  if(n<0) 
    n = n * (-1);
  for (int i=2 ; i<n ; i++) {
    if(n % i == 0)
      return 0;
  }
  return 1;
}

int isPrimoR(int n){
  static int total;
  total = n;
  if(n == 2)
    return 1;
  if(total % n-1 == 0){
    return 0;
  }
  return isPrimoR(n-1);
}

int main(int argc, char *argv[])
{
  int max = MAX(2,3);
  printf("maximo : %d\n",MAX(2,3));
  printf("potencia : %d\n ", power(2,3));
  printf("Es primo : %d\n ", isPrimoR(-7));

  return 0;
}
