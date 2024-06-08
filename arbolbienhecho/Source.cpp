#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Objeto.h"
#include "ArbolB.h"
#include "Sorting.hpp"
#include <vector>

using namespace std;

int generarNumeroAleatorio(int min, int max) {
    return min + rand() % ((max + 1) - min);
}

int generateId() {
    static int id = 1;
    return id++;
}

Arbol* generarDatosAleatorios() {
    int Id = generateId();

    std::string Especie;
    switch (rand() % 5) {
    case 0: Especie = "Roble"; break;
    case 1: Especie = "Pino"; break;
    case 2: Especie = "Olmo"; break;
    case 3: Especie = "Abedul"; break;
    case 4: Especie = "Arce"; break;
    }

    float Altura = generarNumeroAleatorio(10.0f, 30.0f);
    float Diametro = generarNumeroAleatorio(0.5f, 1.5f);
    int Edad = generarNumeroAleatorio(0, 100);
    int Salud = generarNumeroAleatorio(0, 10);

    return new Arbol(Id, Especie, Altura, Diametro, Edad, Salud);
}

void generarDatosArbol(ArbolB<Arbol*>& ArboldeArboles, int n) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        Arbol* nuevoArbol = generarDatosAleatorios();
        ArboldeArboles.insertar(nuevoArbol);
    }
}

void mostrarmenu() {
    std::cout << "\n========================================\n";
    std::cout << "===            Menu arboles          ===\n";
    std::cout << "========================================\n\n";
    std::cout << "1. Insertar 500 arboles\n";
    std::cout << "2. Buscar por edad \n";
    std::cout << "3. Ordenar \n";
    std::cout << "4. Salir\n";
    std::cout << "========================================\n";
    std::cout << "Seleccione una opcion: ";
}

int main() {
    ArbolB<Arbol*> arbolBinario;
    int opcion;
    do {
        mostrarmenu();
        cin >> opcion;
        switch (opcion) {
        case 1:
            generarDatosArbol(arbolBinario, 500);
            break;
        case 2: {
            int edadBuscada;
            cout << "Ingrese la edad del arbol que desea buscar: ";
            cin >> edadBuscada;

            Arbol arbolBusqueda(0, "", 0, 0, edadBuscada, 0);
            bool encontrado = arbolBinario.buscar(&arbolBusqueda);

            if (encontrado) {
                cout << "El arbol con edad " << edadBuscada << " fue encontrado en el arbol binario." << endl;
            }
            else {
                cout << "El arbol con edad " << edadBuscada << " no fue encontrado en el arbol binario." << endl;
            }
            break;
        }
        case 3:
            // Aquí puedes agregar el código para ordenar
            break;
        case 4:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida\n";
            break;
        }
    } while (opcion != 4);

    return 0;
}
