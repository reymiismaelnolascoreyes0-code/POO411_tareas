#include "Sistema.h"
#include <iostream>

void Sistema::agregarEstudiante(std::unique_ptr<Estudiante> estudiante) {
    estudiantes.push_back(std::move(estudiante));
}

void Sistema::agregarProfesor(std::unique_ptr<Profesor> profesor) {
    profesores.push_back(std::move(profesor));
}

void Sistema::mostrarTodo() {
    std::cout << "=== PROFESORES ===" << std::endl;
    for (int i = 0; i < profesores.size(); i++) {
        profesores[i]->mostrarInformacion();
    }
    std::cout << "=== ESTUDIANTES ===" << std::endl;
    for (int i = 0; i < estudiantes.size(); i++) {
        estudiantes[i]->mostrarInformacion();
    }
}
