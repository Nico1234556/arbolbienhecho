#ifndef ARBOL_H
#define ARBOL_H

#include <string>

class Arbol {
public:
    int Id;
    std::string Especie;
    float Altura;
    float Diametro;
    int Edad;
    int Salud;

    // Constructor
    Arbol(int id, const std::string& especie, float altura, float diametro, int edad, int salud)
        : Id(id), Especie(especie), Altura(altura), Diametro(diametro), Edad(edad), Salud(salud) {}

    bool operator<(const Arbol& other) const {
        return this->Edad < other.Edad;
    }

    bool operator==(const Arbol& other) const {
        return this->Edad == other.Edad;
    }
};

#endif // ARBOL_H
