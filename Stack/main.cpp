#include <iostream>
#include "Stack.h"
using namespace  std;
int main() {
    Stack<int> pilaNumeros;
    pilaNumeros.push(10);
    pilaNumeros.push(20);
    pilaNumeros.push(30);
    cout<< "Elemento en el tope: " <<pilaNumeros.top() <<endl;
    
    return 0;
}
