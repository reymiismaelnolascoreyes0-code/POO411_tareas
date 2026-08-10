#include "Usuario.h"

Usuario::Usuario(std::string codigo, std::string nombre) {
    this->codigo = codigo;
    this->nombre = nombre;
}

std::string Usuario::getCodigo() const {
    return codigo;
}

std::string Usuario::getNombre() const {
    return nombre;
}
