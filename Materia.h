#ifndef MATERIA_H
#define MATERIA_H
#include <string>

class Materia {
private:
    std::string nombre;
    std::string codigo;

public:
    Materia(std::string nombre, std::string codigo);
    std::string getNombre();
    std::string getCodigo();
};

#endif
