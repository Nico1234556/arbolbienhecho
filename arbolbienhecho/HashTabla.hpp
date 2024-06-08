#ifndef __HASHTABLA_HPP__
#define __HASHTABLA_HPP__
#include <iostream>
#include "HashEntidad.hpp"
#include <vector>
using namespace std;

class HashTabla {
private:
    vector<HashEntidad*> tabla;
    int numElementos;
    int TABLE_SIZE;

    int hashFunction(const string& key) const {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % TABLE_SIZE;
        }
        return hash;
    }

public:
    HashTabla(int TABLE_SIZE = 128) : TABLE_SIZE(TABLE_SIZE), numElementos(0) {
        tabla.resize(TABLE_SIZE, nullptr);
    }

    ~HashTabla() {
        for (auto& entry : tabla) {
            if (entry != nullptr) {
                delete entry;
            }
        }
    }

    void insertar(const string& key, const Arbol& value) {
        if (numElementos == TABLE_SIZE) return;

        int index = hashFunction(key);
        while (tabla[index] != nullptr) {
            index = (index + 1) % TABLE_SIZE;
        }

        tabla[index] = new HashEntidad(key, value);
        numElementos++;
    }

    int size() const {
        return TABLE_SIZE;
    }

    int sizeActual() const {
        return numElementos;
    }

    const Arbol* buscar(const std::string& key) const {
        int index = hashFunction(key);
        int startIndex = index;
        while (tabla[index] != nullptr) {
            if (tabla[index]->getKey() == key) {
                return &tabla[index]->getValue();
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex) break;
        }
        return nullptr;
    }
};

#endif // !__HASHTABLA_HPP__
