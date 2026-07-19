#include "Calificacion.h"

Calificacion::Calificacion(std::unique_ptr<Materia> asignatura, double puntuacion) : asignatura(std::move(asignatura)), puntuacion(puntuacion) {
}

Calificacion::Calificacion(const Calificacion& copia) : asignatura(std::make_unique<Materia>(*copia.asignatura)), puntuacion(copia.puntuacion) {
}

std::string Calificacion::obtenerTituloMateria() {
    return asignatura->obtenerTitulo();
}

double Calificacion::obtenerPuntuacion() {
    return puntuacion;
}
