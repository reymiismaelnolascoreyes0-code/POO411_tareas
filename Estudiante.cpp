#include "Estudiante.h"

Estudiante::Estudiante(std::string nombreCompleto, std::string carnet) : nombreCompleto(nombreCompleto), carnet(carnet) {
}

Estudiante::Estudiante(const Estudiante& copia) : nombreCompleto(copia.nombreCompleto), carnet(copia.carnet) {
    for (int i = 0; i < copia.listaNotas.size(); i++) {
        listaNotas.push_back(std::make_unique<Calificacion>(*copia.listaNotas[i]));
    }
}

void Estudiante::agregarCalificacion(std::unique_ptr<Calificacion> calificacion) {
    listaNotas.push_back(std::move(calificacion));
}

void Estudiante::mostrarInformacion() {
    std::cout << "Estudiante: " << nombreCompleto << " (" << carnet << ")" << std::endl;
    for (int i = 0; i < listaNotas.size(); i++) {
        std::cout << "  " << listaNotas[i]->obtenerTituloMateria() << " - Nota: " << listaNotas[i]->obtenerPuntuacion() << std::endl;
    }
    std::cout << "  Promedio: " << calcularPromedio() << std::endl;
}

double Estudiante::calcularPromedio() {
    double total = 0;
    for (int i = 0; i < listaNotas.size(); i++) {
        total = total + listaNotas[i]->obtenerPuntuacion();
    }
    if (listaNotas.size() == 0) {
        return 0;
    }
    return total / listaNotas.size();
}

std::string Estudiante::obtenerNombre() {
    return nombreCompleto;
}

std::string Estudiante::obtenerCarnet() {
    return carnet;
}

std::ostream& operator<<(std::ostream& salida, Estudiante& estudiante) {
    salida << "Nombre: " << estudiante.nombreCompleto << " - Carnet: " << estudiante.carnet << " - Promedio: " << estudiante.calcularPromedio();
    return salida;
}

std::istream& operator>>(std::istream& entrada, Estudiante& estudiante) {
    std::cout << "Nombre del estudiante: ";
    entrada >> estudiante.nombreCompleto;
    std::cout << "Carnet del estudiante: ";
    entrada >> estudiante.carnet;
    return entrada;
}
