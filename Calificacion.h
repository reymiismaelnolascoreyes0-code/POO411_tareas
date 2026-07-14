#ifndef CALIFICACION_H
#define CALIFICACION_H
#include <string>
#include <memory>
#include "Materia.h"

class Calificacion {
private:
    std::unique_ptr<Materia> materia;
    double nota;

public:
    Calificacion(std::unique_ptr<Materia> materia, double nota);
    std::string getNombreMateria();
    double getNota();
};

#endif
