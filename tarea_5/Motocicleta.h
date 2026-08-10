#ifndef MOTOCICLETA_H
#define MOTOCICLETA_H
#include <string>
#include "Vehiculo.h"

class Motocicleta : public Vehiculo {
private:
    int cilindrada;

public:
    Motocicleta(std::string matricula, std::string marca, std::string modelo, int anio, double tarifaDiaria, int cilindrada);

    std::string obtenerTipo() const override;
    double calcularTarifaDiaria() const override;
    int obtenerDatoExtra() const override;
};

#endif
