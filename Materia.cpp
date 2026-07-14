#include "Materia.h"

Materia::Materia(std::string nombre, std::string codigo) {
    this->nombre = nombre;
    this->codigo = codigo;
}

std::string Materia::getNombre() {
    return nombre;
}

std::string Materia::getCodigo() {
    return codigo;
}
