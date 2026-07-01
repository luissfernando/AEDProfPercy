#include "ScapeGoat.h"
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

int main() {

    ScapeGoat<int>* ptr = new ScapeGoat<int>();

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
        ptr->search(i);

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
    //TreeVisualizer::generate(ptr->getRoot(), "SG.dot");
    //system("dot -Tpng SG.dot -o SG.png");
    //system("xdg-open SG.png");

    //delete ptr;
    //return 0;
//}
