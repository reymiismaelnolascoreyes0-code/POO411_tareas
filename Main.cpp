#include <iostream>
#include <memory>
#include "Sistema.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Materia.h"
#include "Calificacion.h"

int main() {
    Sistema sistema;

    sistema.agregarProfesor(std::make_unique<Profesor>("Miguel Santana", "Redes"));

    std::unique_ptr<Estudiante> estudiante = std::make_unique<Estudiante>("Josue", "25-EISN-2-062");

    std::unique_ptr<Materia> materia1 = std::make_unique<Materia>("Fisica I", "FIS101");
    std::unique_ptr<Calificacion> calificacion1 = std::make_unique<Calificacion>(std::move(materia1), 85);
    estudiante->agregarCalificacion(std::move(calificacion1));

    std::unique_ptr<Materia> materia2 = std::make_unique<Materia>("Programacion", "POO101");
    std::unique_ptr<Calificacion> calificacion2 = std::make_unique<Calificacion>(std::move(materia2), 90);
    estudiante->agregarCalificacion(std::move(calificacion2));

    sistema.agregarEstudiante(std::move(estudiante));

    sistema.mostrarTodo();

    return 0;
}
