#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>
#include <vector>
#include <memory>
#include "Calificacion.h"

class Estudiante {
private:
    std::string nombre;
    std::string matricula;
    std::vector<std::unique_ptr<Calificacion>> calificaciones;

public:
    Estudiante(std::string nombre, std::string matricula);
    void agregarCalificacion(std::unique_ptr<Calificacion> calificacion);
    void mostrarInformacion();
    double calcularPromedio();
    std::string getNombre();
};

#endif
