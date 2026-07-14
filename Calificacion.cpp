#include "Calificacion.h"

Calificacion::Calificacion(std::unique_ptr<Materia> materia, double nota) {
    this->materia = std::move(materia);
    this->nota = nota;
}

std::string Calificacion::getNombreMateria() {
    return materia->getNombre();
}

double Calificacion::getNota() {
    return nota;
}
