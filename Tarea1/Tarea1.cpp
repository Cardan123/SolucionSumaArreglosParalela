#include <iostream>
#include <omp.h>
#include <vector>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para inicializar la semilla aleatoria

int main() {
    const int size = 1000; // Tamaño de los arreglos
    std::vector<int> A(size), B(size), R(size);

    // Inicializar arreglos con valores aleatorios
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    // Paralelización con OpenMP
#pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        R[i] = A[i] + B[i];
    }

    // Verificar resultados (imprime solo los primeros 10 para no saturar la salida)
    std::cout << "Primeros 10 elementos de los arreglos:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << "A[" << i << "] = " << A[i]
            << ", B[" << i << "] = " << B[i]
            << ", R[" << i << "] = " << R[i] << '\n';
    }

    return 0;
}