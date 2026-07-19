#ifndef CALIFICACION_H
#define CALIFICACION_H
#include <string>
#include <memory>
#include "Materia.h"

class Calificacion {
private:
    std::unique_ptr<Materia> asignatura;
    double puntuacion;

public:
    Calificacion(std::unique_ptr<Materia> asignatura, double puntuacion);
    Calificacion(const Calificacion& copia);
    std::string obtenerTituloMateria();
    double obtenerPuntuacion();
};

#endif
