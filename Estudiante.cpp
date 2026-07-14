#include "Estudiante.h"
#include <iostream>

Estudiante::Estudiante(std::string nombre, std::string matricula) {
    this->nombre = nombre;
    this->matricula = matricula;
}

void Estudiante::agregarCalificacion(std::unique_ptr<Calificacion> calificacion) {
    calificaciones.push_back(std::move(calificacion));
}

void Estudiante::mostrarInformacion() {
    std::cout << "Estudiante: " << nombre << " (" << matricula << ")" << std::endl;
    for (int i = 0; i < calificaciones.size(); i++) {
        std::cout << "  " << calificaciones[i]->getNombreMateria() << " - Nota: " << calificaciones[i]->getNota() << std::endl;
    }
    std::cout << "  Promedio: " << calcularPromedio() << std::endl;
}

double Estudiante::calcularPromedio() {
    double suma = 0;
    for (int i = 0; i < calificaciones.size(); i++) {
        suma = suma + calificaciones[i]->getNota();
    }
    if (calificaciones.size() == 0) {
        return 0;
    }
    return suma / calificaciones.size();
}

std::string Estudiante::getNombre() {
    return nombre;
}
