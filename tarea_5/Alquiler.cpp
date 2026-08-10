#include "Alquiler.h"

Alquiler::Alquiler(std::string codigo, std::string cedulaCliente, std::string matriculaVehiculo, std::string fechaInicio, int dias, double tarifaDiaria) : codigo(codigo), cedulaCliente(cedulaCliente), matriculaVehiculo(matriculaVehiculo), fechaInicio(fechaInicio), dias(dias), tarifaDiaria(tarifaDiaria), activo(true) {
}

std::string Alquiler::getCodigo() const {
    return codigo;
}

std::string Alquiler::getCedulaCliente() const {
    return cedulaCliente;
}

std::string Alquiler::getMatriculaVehiculo() const {
    return matriculaVehiculo;
}

std::string Alquiler::getFechaInicio() const {
    return fechaInicio;
}

int Alquiler::getDias() const {
    return dias;
}

double Alquiler::getTarifaDiaria() const {
    return tarifaDiaria;
}

bool Alquiler::getActivo() const {
    return activo;
}

void Alquiler::finalizar() {
    activo = false;
}

double Alquiler::calcularCostoTotal() const {
    return tarifaDiaria * dias;
}
