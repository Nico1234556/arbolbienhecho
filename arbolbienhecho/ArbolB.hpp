#ifndef __ARBOLB_HPP__
#define __ARBOLB_HPP__

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template <class T>
class Nodo {
public:
    T elemento;
    Nodo* izq;
    Nodo* der;

    Nodo(const T& elem) : elemento(elem), izq(nullptr), der(nullptr) {}
};

template <class T>
class ArbolB {
    Nodo<T>* raiz;

public:
    ArbolB() {
        raiz = nullptr;
    }

    bool insertar(const T& e) {
        return _insertar(raiz, e);
    }

    void enOrden() {
        _enOrden(raiz);
    }

    void preOrden() {
        _preOrden(raiz);
    }

    void postOrden() {
        _postOrden(raiz);
    }

    int cantidad() {
        return _cantidad(raiz);
    }

    int altura() {
        return _altura(raiz);
    }

        vector<T> buscar(const T& e) {
        vector<T> resultados;
        _buscar(raiz, e, resultados);
        return resultados;
    }

    void imprimirArbol() {
        _imprimirArbol(raiz, "", true);
    }

    void limpiar() {
        _limpiar();
    }

         vector<T> obtenerElementos() {
        vector<T> elementos;
        _obtenerElementos(raiz, elementos);
        return elementos;
    }

    // Funciones de búsqueda binaria
    vector<int> buscarTodosLosIndices(const vector<T>& elementos, const T& e) {
        vector<int> indices;
        int primerIndice = buscarPrimerIndice(elementos, e);
        if (primerIndice == -1) {
            return indices;
        }
        int ultimoIndice = buscarUltimoIndice(elementos, e);
        for (int i = primerIndice; i <= ultimoIndice; ++i) {
            indices.push_back(i);
        }
        return indices;
    }

private:
    bool _insertar(Nodo<T>*& nodo, const T& e) {
        if (nodo == nullptr) {
            nodo = new Nodo<T>(e);
            return true;
        }
        if (*e < *(nodo->elemento)) {
            return _insertar(nodo->izq, e);
        }
        else {
            return _insertar(nodo->der, e);
        }
    }

    void _enOrden(Nodo<T>* nodo) {
        if (nodo == nullptr) return;
        _enOrden(nodo->izq);
        std::cout << *(nodo->elemento) << " ";
        _enOrden(nodo->der);
    }

    void _preOrden(Nodo<T>* nodo) {
        if (nodo == nullptr) return;
        std::cout << *(nodo->elemento) << " ";
        _preOrden(nodo->izq);
        _preOrden(nodo->der);
    }

    void _postOrden(Nodo<T>* nodo) {
        if (nodo == nullptr) return;
        _postOrden(nodo->izq);
        _postOrden(nodo->der);
        std::cout << *(nodo->elemento) << " ";
    }

    int _cantidad(Nodo<T>* nodo) {
        if (nodo == nullptr) return 0;
        return 1 + _cantidad(nodo->izq) + _cantidad(nodo->der);
    }

    int _altura(Nodo<T>* nodo) {
        if (nodo == nullptr) return 0;
        return 1 + std::max(_altura(nodo->izq), _altura(nodo->der));
    }

    void _buscar(Nodo<T>* nodo, const T& e, vector<T>& resultados) {
        if (nodo == nullptr) return;
        if (*(nodo->elemento) == *e) {
            resultados.push_back(nodo->elemento);
        }
        _buscar(nodo->izq, e, resultados);
        _buscar(nodo->der, e, resultados);
    }

    void _imprimirArbol(Nodo<T>* nodo, string ident, bool last) {
        if (nodo != nullptr) {
            cout << ident;
            if (last) {
                cout << "R----";
                ident += "   ";
            }
            else {
                cout << "L----";
                ident += "|  ";
            }
            cout << *(nodo->elemento) << std::endl;
            _imprimirArbol(nodo->izq, ident, false);
            _imprimirArbol(nodo->der, ident, true);
        }
    }

    void _limpiar() {
        raiz = nullptr; // Establece la raíz del árbol como nula, lo que efectivamente elimina todos los nodos del árbol
    }

    void _obtenerElementos(Nodo<T>* nodo, vector<T>& elementos) {
        if (nodo == nullptr) return;
        _obtenerElementos(nodo->izq, elementos);
        elementos.push_back(nodo->elemento);
        _obtenerElementos(nodo->der, elementos);
    }

    // Búsqueda binaria modificada para encontrar el primer índice de aparición
    int buscarPrimerIndice(const vector<T>& elementos, const T& e) {
        int low = 0, high = elementos.size() - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (*(elementos[mid]) == *e) {
                result = mid;
                high = mid - 1;
            }
            else if (*(elementos[mid]) < *e) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return result;
    }

    // Búsqueda binaria modificada para encontrar el último índice de aparición
    int buscarUltimoIndice(const vector<T>& elementos, const T& e) {
        int low = 0, high = elementos.size() - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (*(elementos[mid]) == *e) {
                result = mid;
                low = mid + 1;
            }
            else if (*(elementos[mid]) < *e) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return result;
    }
};

#endif
