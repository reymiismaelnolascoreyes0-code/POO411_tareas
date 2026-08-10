#include "Motocicleta.h"

Motocicleta::Motocicleta(std::string matricula, std::string marca, std::string modelo, int anio, double tarifaDiaria, int cilindrada) : Vehiculo(matricula, marca, modelo, anio, tarifaDiaria), cilindrada(cilindrada) {
}

std::string Motocicleta::obtenerTipo() const {
    return "Motocicleta";
}

double Motocicleta::calcularTarifaDiaria() const {
    if (cilindrada > 250) {
        return getTarifaBase() + 150;
    }
    return getTarifaBase();
}

int Motocicleta::obtenerDatoExtra() const {
    return cilindrada;
}
