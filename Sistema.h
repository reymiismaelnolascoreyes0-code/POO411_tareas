#ifndef SISTEMA_H
#define SISTEMA_H

#include <memory>
#include <vector>

#include "Calificacion.h"
#include "Estudiante.h"
#include "Materia.h"
#include "Profesor.h"

class Sistema
{
private:
    std::vector<std::shared_ptr<Estudiante>> estudiantes;
    std::vector<std::shared_ptr<Materia>> materias;
    std::vector<std::shared_ptr<Profesor>> profesores;
    std::vector<std::shared_ptr<Calificacion>> calificaciones;

public:
    void agregarEstudiante();
    void agregarMateria();
    void agregarProfesor();
    void agregarCalificacion();
    void mostrarCalificaciones();
};

#endif
