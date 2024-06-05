#include "ArbolB.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
 
void imprimir(int e) {
	cout << " " << e;
}

int main() {
	//srand(time(0));
	ArbolB<int>* arbol = new ArbolB<int>(imprimir);
	/*
	for (int i = 0; i < 30; ++i) {
		arbol->insertar(rand() % 100);
	}*/


	// Arbol Binario de PPT
	arbol->insertar(15);
	arbol->insertar(9);
	arbol->insertar(20);
	arbol->insertar(6);
	arbol->insertar(14);
	arbol->insertar(17);
	arbol->insertar(64);
	arbol->insertar(13);
	arbol->insertar(26);
	arbol->insertar(72);

	cout << "EnOrden";
	arbol->enOrden();
	cout << endl;

	cout << "PreOrden";
	arbol->preOrden();
	cout << endl;

	cout << "PostOrden";
	arbol->postOrden();
	cout << endl;

	cout << "Altura: " << arbol->altura() << endl;
	cout << "Cantidad: " << arbol->cantidad() << endl;

	int e=8;
	if (arbol->buscar(e) == true) cout << "\nEl elemento SI se encuentra en el arbol.\n\n";
	else if (arbol->buscar(e) == false) cout << "\nEl elemento NO se encuentra en el arbol.\n\n";

	arbol->imprimirarbol();

	// =============================================================== //
	//EJERCICIOS Planteados:

	/*
	- Implemente una funci�n que determine cuantos nodos hay al lado izquierdo y cuantos hay al lado derecho de la ra�z.
	- Implemente  una  funci�n  que  devuelva  la  suma  de  todos  los  n�meros  de  un  �rbol  binario de enteros.
	- Implemente una funci�n que permita convertir un �rbol binario en su espejo.
	- Implementar b�squeda de un elemento en un �rbol Binario.
	*/


	//cin.get();
	_getch();
	return 0;
}