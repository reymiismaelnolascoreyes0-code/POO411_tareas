#include <iostream>

#include "Sistema.h"


#include <memory>



void Sistema::agregarEstudiante()
{
    int matricula;
    std::string nombre;

   std:: cout << "Matricula: ";
    std::cin >> matricula;

    std::cin.ignore();

    std::cout << "Nombre: ";
    getline(std::cin, nombre);

    estudiantes.push_back(
        std::make_shared<Estudiante>(matricula, nombre)
    );
}

void Sistema::agregarMateria()
{
    std::string nombre;

    std::cin.ignore();

    std::cout << "Materia: ";
    getline(std::cin, nombre);

    materias.push_back(
        std::make_shared<Materia>(nombre)
    );
}

void Sistema::agregarProfesor()
{
   std::string nombre;

    std::cin.ignore();

    std::cout << "Profesor: ";
    getline(std::cin, nombre);

    profesores.push_back(
        std::make_shared<Profesor>(nombre)
    );
}

void Sistema::agregarCalificacion()
{
    double nota;

    std::cout << "Nota: ";
    std::cin >> nota;

    calificaciones.push_back(
        std::make_shared<Calificacion>(nota)
    );
}

void Sistema::mostrarCalificaciones()
{
    std::cout << "\n--- CALIFICACIONES ---\n";

    for (const auto& c : calificaciones)
    {
        std::cout << c->getNota() << std::endl;
    }
}
