#include "Profesor.h"
#include <iostream>

Profesor::Profesor(std::string nombreCompleto, std::string asignaturaImpartida) : nombreCompleto(nombreCompleto), asignaturaImpartida(asignaturaImpartida) {
}

Profesor::Profesor(const Profesor& copia) : nombreCompleto(copia.nombreCompleto), asignaturaImpartida(copia.asignaturaImpartida) {
}

void Profesor::mostrarInformacion() {
    std::cout << "Profesor: " << nombreCompleto << " - Imparte: " << asignaturaImpartida << std::endl;
}
