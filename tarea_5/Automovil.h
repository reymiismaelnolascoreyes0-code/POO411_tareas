#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H
#include <string>
#include "Vehiculo.h"

class Automovil : public Vehiculo {
private:
    int puertas;

public:
    Automovil(std::string matricula, std::string marca, std::string modelo, int anio, double tarifaDiaria, int puertas);

    std::string obtenerTipo() const override;
    double calcularTarifaDiaria() const override;
    int obtenerDatoExtra() const override;
};

#endif
