#include "BST.h"
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

int main() {

    BST<int>* ptr = new BST<int>();

    // ==========================
    // Inserción
    // ==========================
    auto inicio = high_resolution_clock::now();

    for (int i = 1; i <= 100000; i++)
        ptr->insert(i);

    auto fin = high_resolution_clock::now();

    cout << "Inserción: "
         << duration_cast<nanoseconds>(fin - inicio).count()
         << " ns\n";

    // ==========================
    // Búsqueda
    // ==========================
    inicio = high_resolution_clock::now();

    for (int i = 1; i <= 100000; i++)
        ptr->search(i);      // o search(i), según tu implementación

    fin = high_resolution_clock::now();

    cout << "Búsqueda: "
         << duration_cast<nanoseconds>(fin - inicio).count()
         << " ns\n";

    // ==========================
    // Eliminación
    // ==========================
    inicio = high_resolution_clock::now();

    for (int i = 1; i <= 100000; i++)
        ptr->remove(i);

    fin = high_resolution_clock::now();

    cout << "Eliminación: "
         << duration_cast<nanoseconds>(fin - inicio).count()
         << " ns\n";

    delete ptr;

    return 0;
}
  //ptr->treeDegenerado();

  /*TreeVisualizer::generate(ptr->getRoot(),"bst.dot");
  system("dot -Tpng bst.dot -o bst.png");
  system("xdg-open bst.png");
  return 0;
}*/
