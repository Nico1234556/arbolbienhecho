#ifndef __HASHENTIDAD_HPP__
#define __HASHENTIDAD_HPP__
using namespace std;

#include "Arbolb.h"
#include <string>

class HashEntidad {
private:
    string key;
    Arbol value;

public:
    HashEntidad(const string& key, const Arbol& value) : key(key), value(value) {}

    const string& getKey() const { return key; }
    const Arbol& getValue() const { return value; }
};

#endif // !__HASHENTIDAD_HPP__
