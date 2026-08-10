#include "Vehiculo.h"

Vehiculo::Vehiculo(std::string matricula, std::string marca, std::string modelo, int anio, double tarifaDiaria) : matricula(matricula), marca(marca), modelo(modelo), anio(anio), tarifaDiaria(tarifaDiaria), disponible(true) {
}

std::string Vehiculo::getMatricula() const {
    return matricula;
}

std::string Vehiculo::getMarca() const {
    return marca;
}

std::string Vehiculo::getModelo() const {
    return modelo;
}

int Vehiculo::getAnio() const {
    return anio;
}

double Vehiculo::getTarifaBase() const {
    return tarifaDiaria;
}

bool Vehiculo::getDisponible() const {
    return disponible;
}

void Vehiculo::setDisponible(bool valor) {
    disponible = valor;
}

int Vehiculo::obtenerDatoExtra() const {
    return 0;
}
