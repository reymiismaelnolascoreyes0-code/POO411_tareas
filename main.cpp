#include <iostream>
#include <memory>
#include "Sistema.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Materia.h"
#include "Calificacion.h"

int main() {
    Sistema sistemaCalificaciones;

    sistemaCalificaciones.agregar(std::make_unique<Profesor>("Carla Ramirez", "Base de Datos"));

    Estudiante alumno1("Reymi Ismael Nolasco Reyes", "25-EISN-2-008");

    std::unique_ptr<Materia> asignatura1 = std::make_unique<Materia>("Base de Datos", "BDD202");
    std::unique_ptr<Calificacion> nota1 = std::make_unique<Calificacion>(std::move(asignatura1), 92);
    alumno1.agregarCalificacion(std::move(nota1));

    std::unique_ptr<Materia> asignatura2 = std::make_unique<Materia>("Estructura de Datos", "EDD303");
    std::unique_ptr<Calificacion> nota2 = std::make_unique<Calificacion>(std::move(asignatura2), 88);
    alumno1.agregarCalificacion(std::move(nota2));

    Estudiante alumno2(alumno1);

    std::cout << alumno1 << std::endl;
    std::cout << alumno2 << std::endl;

    sistemaCalificaciones.agregar(std::make_unique<Estudiante>(alumno1));
    sistemaCalificaciones.agregar(std::make_unique<Estudiante>(alumno2));

    sistemaCalificaciones.mostrarTodo();

    sistemaCalificaciones.guardarBinario("notas_reymi.dat");
    sistemaCalificaciones.cargarBinario("notas_reymi.dat");

    return 0;
}
