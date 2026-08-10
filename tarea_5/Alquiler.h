#ifndef ALQUILER_H
#define ALQUILER_H
#include <string>

class Alquiler {
private:
    std::string codigo;
    std::string cedulaCliente;
    std::string matriculaVehiculo;
    std::string fechaInicio;
    int dias;
    double tarifaDiaria;
    bool activo;

public:
    Alquiler(std::string codigo, std::string cedulaCliente, std::string matriculaVehiculo, std::string fechaInicio, int dias, double tarifaDiaria);

    std::string getCodigo() const;
    std::string getCedulaCliente() const;
    std::string getMatriculaVehiculo() const;
    std::string getFechaInicio() const;
    int getDias() const;
    double getTarifaDiaria() const;
    bool getActivo() const;
    void finalizar();
    double calcularCostoTotal() const;
};

#endif
