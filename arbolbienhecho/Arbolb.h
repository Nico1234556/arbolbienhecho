#pragma once
#pragma once
#ifndef __ARBOLB_HPP__
#define __ARBOLB_HPP__

#include<algorithm>
#include <string>
using namespace std;

template <class T>
class Nodo {
public:
	T elemento;
	Nodo* izq;
	Nodo* der;
};

template <class T>
class ArbolB {
	Nodo<T>* raiz;
	void(*procesar)(T); //Puntero a funcion

public: //Metodos publicos que llaman a metodos internos de la clase
	ArbolB(void(*otroPunteroAFuncion)(T)) { //Constructor del Arbol: recibe como parametro un puntero a una funcion
		this->procesar = otroPunteroAFuncion;
		raiz = nullptr;
	}
	bool insertar(T e) {
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
	bool buscar(T e) {
		return _buscar(raiz, e);
	}
	void imprimirarbol()
	{
		_imprimirArbol(raiz, "", true);
	}

	// =============================================================== //
	// Ejercicios Planetados



private: //Metodos internos de la clase
	//se pasa como parametro el nodo, xq se puede empezar la operación desde cualquier nodo hacia abajo, no necesariamente debe ser el nodo Raiz.
	bool _insertar(Nodo<T>*& nodo, T e) { //Parametros: (Nodo Padre, elemento)
		if (nodo == nullptr) { //Si no hay Nodo
			nodo = new Nodo<T>();
			nodo->elemento = e;
			//OBS: Los nodos izq y der deberian estar en nullptr
		}
		else if (e < nodo->elemento) {
			return _insertar(nodo->izq, e); //recursividad
		}
		else if (e >= nodo->elemento) {
			return _insertar(nodo->der, e);	//recursividad
		}
	}

	void _enOrden(Nodo<T>* nodo) { //recorrido: Izq => Raiz => Der
		if (nodo == nullptr) return;
		_enOrden(nodo->izq);	//por ejemplo imprime Izq
		procesar(nodo->elemento);	//por ejemplo imprime Raiz
		_enOrden(nodo->der);	//por ejemplo imprime Der
	}
	void _preOrden(Nodo<T>* nodo) {	//Recorrido: Raiz => Izq => Der
		if (nodo == nullptr) return;
		procesar(nodo->elemento); //por ejemplo imprime Raiz
		_preOrden(nodo->izq);	//por ejemplo imprime Izq
		_preOrden(nodo->der);	//por ejemplo imprime Der
	}
	void _postOrden(Nodo<T>* nodo) { //Recorrido: Izq => Der => Raiz
		if (nodo == nullptr) return;
		_postOrden(nodo->izq);	//por ejemplo imprime Izq
		_postOrden(nodo->der);	//por ejemplo imprime Der
		procesar(nodo->elemento);	//por ejemplo imprime Raiz
	}

	bool _vacio() {
		return raiz == nullptr;
	}
	int _cantidad(Nodo<T>* nodo) {
		//La cantidad de nodos del árbol es:
		//	0 si es vacío
		//	1 + la cantidad de nodos por la izquierda + la cantidad de nodos por la derecha

		if (nodo == nullptr)
			return 0;
		else
		{
			int ci, cd;
			ci = _cantidad(nodo->izq);
			cd = _cantidad(nodo->der);
			return 1 + ci + cd;
		}

	}
	int _altura(Nodo<T>* nodo) {
		//La altura del árbol es:
		//	0 si es vacío
		//	la mayor de las alturas por la izquierda y por la derecha, las cuáles son 0 si son vacías ó 1 + la altura por la izq(o der) en caso contrario

		if (nodo == nullptr)
			return 0;
		else
		{
			int ai, ad;
			///*
			// [Opcion 1] OK:
			ai = 1 + _altura(nodo->izq);
			ad = 1 + _altura(nodo->der);
			return ai > ad ? ai : ad;
			//*/

			/*
			// [Opcion 2] OK:
			ai = _altura(nodo->izq);
			ad = _altura(nodo->der);
			return 1 + max(ai, ad);
			*/
		}
	}

	//Buscar
	bool _buscar(Nodo <T>* nodo, T e) {
		if (nodo == nullptr) {
			return false;
		}
		else if (e < nodo->elemento) {
			return _buscar(nodo->izq, e);
		}
		else if (e > nodo->elemento) {
			return _buscar(nodo->der, e);
		}
		else if (e == nodo->elemento) {
			return true;
		}
	}
	void _imprimirArbol(Nodo<T>* nodo, string ident, bool last)
	{
		if (nodo != nullptr)
		{
			cout << ident;
			if (last)
			{
				cout << "R----";
				ident += "   ";
			}
			else 
			{
				cout << "L----";
				ident += "   ";
			}
			cout << nodo->elemento << endl;
			_imprimirArbol(nodo ->izq, ident, false);
			_imprimirArbol(nodo -> der, ident, true);

			}

		}
	

};

#endif
#pragma once
