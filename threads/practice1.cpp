#include <iostream>
#include <chrono>
using namespace std;

void n_primos(int n){
    for(int i=1 ; i<n+1 ; i++){
        int tmp=0;
        for(int j=1;j<=i;j++){
            if(i%j==0){
                tmp++;
            }
        }
        if(tmp==2){
            //cout<<i<<" ";
        }
    }
}
void n_primos_mejorado(int n) {
    if (n >= 2) { // El primer número primo es 2
        //std::cout << 2 << " ";
    }

    // Iteramos solo sobre números impares a partir de 3
    for (int i = 3; i <= n; i += 2) {
        bool es_primo = true; // Asumimos que es primo hasta que se demuestre lo contrario

        // El bucle interno ahora va de 3 hasta la raíz cuadrada de i, incrementando de 2 en 2
        for (int j = 3; j * j <= i; j += 2) {
            if (i % j == 0) {
                es_primo = false; // Encontramos un divisor, no es primo
                break;            // Salimos del bucle interno, ya sabemos que no es primo
            }
        }
        if (es_primo) {
            //std::cout << i << " ";
        }
    }
    std::cout << std::endl; // Para una salida más limpia
}

int main(int argc, char const *argv[])
{   
    int n=100000;
    auto start = chrono::high_resolution_clock::now();
    n_primos(n);
    auto end = chrono::high_resolution_clock::now();
    auto duracion = chrono::duration_cast<chrono::duration<double>>(end-start);
    cout<<"\nTIEMPO : "<< duracion.count()<<" s\n";

    //funcion 2
    start = chrono::high_resolution_clock::now();
    n_primos_mejorado(n);
    end = chrono::high_resolution_clock::now();
    duracion = chrono::duration_cast<chrono::duration<double>>(end-start);
    cout<<"\nTIEMPO : "<< duracion.count()<<" s\n";
    return 0;
}
