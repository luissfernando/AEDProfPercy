#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // mutex global para proteger la consola

void imprimir(const std::string& mensaje, int veces) {
    for (int i = 0; i < veces; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // bloquea el mutex durante este bloque
        std::cout << mensaje << " (" << i + 1 << ")\n";
    // mutex se libera automáticamente al salir del bloque
    }
}

int main() {
    std::thread hilo1(imprimir, "Hola desde hilo 1", 5);
    std::thread hilo2(imprimir, "Hola desde hilo 2", 5);

    hilo1.join();
    hilo2.join();

    std::cout << "Fin del main\n";
    return 0;
}
