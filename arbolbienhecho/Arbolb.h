#ifndef __ARBOLB_HPP__
#define __ARBOLB_HPP__

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Arbol.h"

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
    void(*procesar)(const T&); // Puntero a función

public:
    ArbolB(void(*otroPunteroAFuncion)(const T&)) {
        this->procesar = otroPunteroAFuncion;
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

    bool buscar(const T& e) {
        return _buscar(raiz, e);
    }

    void imprimirArbol() {
        _imprimirArbol(raiz, "", true);
    }

    // Otras declaraciones de funciones y miembros de la clase

    // Método para limpiar el árbol (eliminar todos los nodos)
    void limpiar()
    {
        _limpiar();
    }
    // Método para obtener todos los elementos del árbol en un vector
    std::vector<T> obtenerElementos() {
        std::vector<T> elementos;
        _obtenerElementos(raiz, elementos);
        return elementos;
    }
private:
    bool _insertar(Nodo<T>*& nodo, const T& e) {
        if (nodo == nullptr) {
            nodo = new Nodo<T>(e);
            return true;
        }
        if (e < nodo->elemento) {
            return _insertar(nodo->izq, e);
        }
        else {
            return _insertar(nodo->der, e);
        }
    }

    void _enOrden(Nodo<T>* nodo) {
        if (nodo == nullptr) return;
        _enOrden(nodo->izq);
        procesar(nodo->elemento);
        _enOrden(nodo->der);
    }

    void _preOrden(Nodo<T>* nodo) {
        if (nodo == nullptr) return;
        procesar(nodo->elemento);
        _preOrden(nodo->izq);
        _preOrden(nodo->der);
    }

    void _postOrden(Nodo<T>* nodo) {
        if (nodo == nullptr) return;
        _postOrden(nodo->izq);
        _postOrden(nodo->der);
        procesar(nodo->elemento);
    }

    int _cantidad(Nodo<T>* nodo) {
        if (nodo == nullptr) return 0;
        return 1 + _cantidad(nodo->izq) + _cantidad(nodo->der);
    }

    int _altura(Nodo<T>* nodo) {
        if (nodo == nullptr) return 0;
        return 1 + std::max(_altura(nodo->izq), _altura(nodo->der));
    }

    bool _buscar(Nodo<T>* nodo, const T& e) {
        if (nodo == nullptr) return false;
        if (e < nodo->elemento) return _buscar(nodo->izq, e);
        if (e > nodo->elemento) return _buscar(nodo->der, e);
        return true;
    }

    void _imprimirArbol(Nodo<T>* nodo, std::string ident, bool last) {
        if (nodo != nullptr) {
            cout << ident;
            if (last) {
                std::cout << "R----";
                ident += "   ";
            }
            else {
                std::cout << "L----";
                ident += "|  ";
            }
            cout << nodo->elemento.Edad << " (" << nodo->elemento.Especie << ")" << std::endl;
            _imprimirArbol(nodo->izq, ident, false);
            _imprimirArbol(nodo->der, ident, true);
        }
    }
    void _limpiar() {
        raiz = nullptr; // Establece la raíz del árbol como nula, lo que efectivamente elimina todos los nodos del árbol
    }
    // Método para obtener todos los elementos del árbol en un vector
    void _obtenerElementos(Nodo<T>* nodo, std::vector<T>& elementos) {
        if (nodo == nullptr) return;
        _obtenerElementos(nodo->izq, elementos);
        elementos.push_back(nodo->elemento);
        _obtenerElementos(nodo->der, elementos);
    }
};

#endif
