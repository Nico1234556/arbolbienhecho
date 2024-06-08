#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Arbolb.h"
#include "ArbolB.hpp"
#include "Sorting.hpp"
#include <vector>
#include "HashEntidad.hpp"
#include "HashTabla.hpp"

using namespace std;

// MENÚ PARA AMBAS ESTRUCTURAS 

void mostrarmenu() {
    std::cout << "\n========================================\n";
    std::cout << "===            Menu arboles          ===\n";
    std::cout << "========================================\n\n";
    std::cout << "1. Insertar 500 arboles a hashtable\n";
    std::cout << "2. Insertar 500 arboles a arbol binario\n";
    std::cout << "3. Buscar por edad  \n";
    std::cout << "4. Ordenar\n";
    std::cout << "5. Buscar por edad con búsqueda binaria\n";
    std::cout << "6. Salir\n";

    std::cout << "========================================\n";
    std::cout << "Seleccione una opcion: ";
}

//PARA LA HASH TABLE 
void imprimirTablaHash(const HashTabla& ht, const std::vector<std::string>& keys) {
    cout << "SIZE TABLA: " << ht.size() << endl;
    cout << "SIZE ACTUAL: " << ht.sizeActual() << endl;

    cout << "Especie - Edad" << endl;
    for (const auto& key : keys) {
        const Arbol* arbol = ht.buscar(key);
        if (arbol != nullptr) {
            cout << arbol->Especie << " - " << arbol->Edad << endl;
        }
        else {
            cout << key << " : Not Found" << endl;
        }
    }
}
// más especies de arboles "Haya", "Ciprés", "Secuoya", "Baobab", "Teca", "Acacia", "Eucalipto", "Magnolio"

string generarEspecieAleatoria() {
    const vector<string> especies = { "Sauce", "Pino", "Roble", "Arce", "Olmo", "Cedro", "Abeto", "Cerezo", "Fresno" };
    return especies[rand() % especies.size()];
}

int generarEdadAleatoria(int min, int max) {
    return min + (rand() % (max - min + 1));
}
// PARA EL ARBOL BINARIO 

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

void generarDatosArbol(ArbolB<Arbol*>& ArboldeArboles, int n, vector<Arbol*>& arbolesVector) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        Arbol* nuevoArbol = generarDatosAleatorios();
        bool insertado = ArboldeArboles.insertar(nuevoArbol);
        if (insertado) {
            arbolesVector.push_back(nuevoArbol);
            cout << "Insertado: Id=" << nuevoArbol->Id << ", Especie=" << nuevoArbol->Especie << ", Altura=" << nuevoArbol->Altura << ", Diametro=" << nuevoArbol->Diametro << ", Edad = " << nuevoArbol->Edad << ", Salud=" << nuevoArbol->Salud << endl;
        }
        else {
            cout << "No se pudo insertar el arbol con Id=" << nuevoArbol->Id << endl;
        }
    }
}

bool compararPorEdad(const Arbol* a, const Arbol* b) {
    return a->Edad < b->Edad;
}

int main() {
    HashTabla ht(500);
    srand(static_cast<unsigned int>(time(0)));
    ArbolB<Arbol*> arbolBinario;
    vector<Arbol*> arbolesVector;
    Sorting<Arbol*> sorter;
    int opcion;
    vector<string> keys;

    do {
        mostrarmenu();
        cin >> opcion;
        switch (opcion) {
        case 1:
            system("cls");

          
            for (int i = 0; i < 500; ++i) 
            {
                string especie = generarEspecieAleatoria();
                int edad = generarEdadAleatoria(1, 100);
                Arbol arbol(especie, edad);
                ht.insertar(especie, arbol);
                keys.push_back(especie);
            }
            imprimirTablaHash(ht, keys);
            cout << "Se han insertado 500 arboles en la tabla hash lineal ." << endl;
            break;
        case 2:
            system("cls");
            generarDatosArbol(arbolBinario, 500, arbolesVector);
            cout << "Se han insertado 500 arboles en el arbol binario." << endl;
            break;
        case 3: {
            system("cls");
            int edadBuscada;
            cout << "Ingrese la edad del arbol que desea buscar: ";
            cin >> edadBuscada;

            Arbol arbolBusqueda(0, "", 0, 0, edadBuscada, 0);
            std::vector<Arbol*> encontrados = arbolBinario.buscar(&arbolBusqueda);

            if (!encontrados.empty()) {
                cout << "Arboles con edad " << edadBuscada << " encontrados en el arbol binario:\n";
                for (const auto& arbol : encontrados) {
                    cout << "Id=" << arbol->Id << ", Especie=" << arbol->Especie << ", Altura=" << arbol->Altura << ", Diametro=" << arbol->Diametro << ", Salud=" << arbol->Salud << endl;
                }
            }
            else {
                cout << "No se encontraron arboles con edad " << edadBuscada << " en el arbol binario.\n";
            }
            break;
        }
        case 4:
            system("cls");
            if (arbolesVector.empty()) {
                cout << "No hay arboles para ordenar. Inserta primero los arboles." << endl;
                break;
            }
            cout << "Ordenando con QuickSort..." << endl;
            sorter.quicksort(arbolesVector, compararPorEdad);
            for (const auto& arbol : arbolesVector) {
                cout << *arbol << endl;
            }

            cout << "Ordenando con MergeSort..." << endl;
            sorter.mergesort(arbolesVector, compararPorEdad);
            for (const auto& arbol : arbolesVector) {
                cout << *arbol << endl;
            }

            cout << "Ordenando con HeapSort..." << endl;
            sorter.heapsort(arbolesVector, compararPorEdad);
            for (const auto& arbol : arbolesVector) {
                cout << *arbol << endl;
            }
            break;
        case 5: {
            system("cls");
            if (arbolesVector.empty()) {
                cout << "No hay arboles para buscar. Inserta primero los arboles." << endl;
                break;
            }
            int edadBuscadaBinaria;
            cout << "Ingrese la edad del arbol que desea buscar con búsqueda binaria: ";
            cin >> edadBuscadaBinaria;

            sorter.quicksort(arbolesVector, compararPorEdad); // Asegúrate de que el vector esté ordenado

            Arbol arbolBusquedaBinaria(0, "", 0, 0, edadBuscadaBinaria, 0);
            vector<int> indices = arbolBinario.buscarTodosLosIndices(arbolesVector, &arbolBusquedaBinaria);

            if (!indices.empty()) {
                cout << "El arbol con edad " << edadBuscadaBinaria << " fue encontrado en los Indices: ";
                for (int indice : indices) {
                    cout << indice << " ";
                }
                cout << endl;
            }
            else {
                cout << "El arbol con edad " << edadBuscadaBinaria << " no fue encontrado." << endl;
            }
            break;
        }
        case 6:
            system("cls");
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida\n";
            break;
        }
    } while (opcion != 6);

    return 0;
}
