#include "Automovil.h"

Automovil::Automovil(std::string matricula, std::string marca, std::string modelo, int anio, double tarifaDiaria, int puertas) : Vehiculo(matricula, marca, modelo, anio, tarifaDiaria), puertas(puertas) {
}

std::string Automovil::obtenerTipo() const {
    return "Automovil";
}

double Automovil::calcularTarifaDiaria() const {
    if (puertas > 4) {
        return getTarifaBase() + 200;
    }
    return getTarifaBase();
}

int Automovil::obtenerDatoExtra() const {
    return puertas;
}
