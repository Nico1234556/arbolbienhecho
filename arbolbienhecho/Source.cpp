#include <iostream>
#include "Arbol.h"
#include "Arbolb.h"
#include "Sorting.hpp"

void procesarNodo(const Arbol& arbol) {
    cout << arbol.Edad << " (" << arbol.Especie << ")" << std::endl;
}

void mostrarElementos(const vector<Arbol>& elementos) {
    for (const auto& arbol : elementos) {
        procesarNodo(arbol);
    }
}

int main() {
    ArbolB<Arbol> arbolBinario(procesarNodo);
    Sorting<Arbol> sorter;

    Arbol arbol1(1, "Pino", 10.5, 30.0, 5, 80);
    Arbol arbol2(2, "Roble", 15.0, 40.0, 10, 90);
    Arbol arbol3(3, "Cedro", 8.0, 25.0, 3, 70);

    arbolBinario.insertar(arbol1);
    arbolBinario.insertar(arbol2);
    arbolBinario.insertar(arbol3);

    int opcion;
    std::cout << "Seleccione el método de ordenamiento:\n";
    std::cout << "1. QuickSort\n";
    std::cout << "2. MergeSort\n";
    std::cout << "3. HeapSort\n";
    std::cin >> opcion;

    switch (opcion) {
    case 1:
        sorter.quicksort(arbolBinario, [](const Arbol& a, const Arbol& b) { return a < b; });
        break;
    case 2:
        sorter.mergesort(arbolBinario, [](const Arbol& a, const Arbol& b) { return a < b; });
        break;
    case 3:
        sorter.heapsort(arbolBinario, [](const Arbol& a, const Arbol& b) { return a < b; });
        break;
    default:
        std::cout << "Opción no válida" << std::endl;
        return 1;
    }

    cout << "Elementos ordenados:" << std::endl;
    arbolBinario.enOrden();
   
    cin.get();

    return 0;
}
