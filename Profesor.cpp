#include "Profesor.h"
#include <iostream>

Profesor::Profesor(std::string nombre, std::string materiaQueImparte) {
    this->nombre = nombre;
    this->materiaQueImparte = materiaQueImparte;
}

void Profesor::mostrarInformacion() {
    std::cout << "Profesor: " << nombre << " - Imparte: " << materiaQueImparte << std::endl;
}
