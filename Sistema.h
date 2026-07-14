#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <memory>
#include "Estudiante.h"
#include "Profesor.h"

class Sistema {
private:
    std::vector<std::unique_ptr<Estudiante>> estudiantes;
    std::vector<std::unique_ptr<Profesor>> profesores;

public:
    void agregarEstudiante(std::unique_ptr<Estudiante> estudiante);
    void agregarProfesor(std::unique_ptr<Profesor> profesor);
    void mostrarTodo();
};

#endif
