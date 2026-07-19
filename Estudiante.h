#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "Calificacion.h"

class Estudiante {
private:
    std::string nombreCompleto;
    std::string carnet;
    std::vector<std::unique_ptr<Calificacion>> listaNotas;

public:
    Estudiante(std::string nombreCompleto, std::string carnet);
    Estudiante(const Estudiante& copia);
    void agregarCalificacion(std::unique_ptr<Calificacion> calificacion);
    void mostrarInformacion();
    double calcularPromedio();
    std::string obtenerNombre();
    std::string obtenerCarnet();

    friend std::ostream& operator<<(std::ostream& salida, Estudiante& estudiante);
    friend std::istream& operator>>(std::istream& entrada, Estudiante& estudiante);
};

#endif
