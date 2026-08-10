#ifndef VEHICULO_H
#define VEHICULO_H
#include <string>

class Vehiculo {
private:
    std::string matricula;
    std::string marca;
    std::string modelo;
    int anio;
    double tarifaDiaria;
    bool disponible;

public:
    Vehiculo(std::string matricula, std::string marca, std::string modelo, int anio, double tarifaDiaria);
    virtual ~Vehiculo() = default;

    std::string getMatricula() const;
    std::string getMarca() const;
    std::string getModelo() const;
    int getAnio() const;
    double getTarifaBase() const;
    bool getDisponible() const;
    void setDisponible(bool valor);

    virtual std::string obtenerTipo() const = 0;
    virtual double calcularTarifaDiaria() const = 0;
    virtual int obtenerDatoExtra() const;
};

#endif
