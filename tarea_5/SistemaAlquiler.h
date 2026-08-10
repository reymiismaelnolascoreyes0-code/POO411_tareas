#ifndef SISTEMAALQUILER_H
#define SISTEMAALQUILER_H
#include <string>
#include <vector>
#include <memory>
#include "Cliente.h"
#include "Vehiculo.h"
#include "Alquiler.h"

class SistemaAlquiler {
private:
    std::vector<Cliente> clientes;
    std::vector<std::unique_ptr<Vehiculo>> vehiculos;
    std::vector<Alquiler> alquileres;

    std::string leerTexto(const std::string& mensaje) const;
    int leerEntero(const std::string& mensaje) const;
    double leerDouble(const std::string& mensaje) const;
    std::vector<std::string> dividirLinea(const std::string& linea, char separador) const;

    bool existeCliente(const std::string& cedula) const;
    bool existeVehiculo(const std::string& matricula) const;
    int contarAlquileresActivos(const std::string& cedula) const;
    Vehiculo* buscarVehiculo(const std::string& matricula);

    void cargarClientes();
    void cargarVehiculos();
    void cargarAlquileres();
    void guardarClientes() const;
    void guardarVehiculos() const;
    void guardarAlquileres() const;

    void registrarCliente();
    void registrarAutomovil();
    void registrarMotocicleta();
    void verClientes() const;
    void verVehiculos() const;
    void registrarAlquiler();
    void registrarDevolucion();
    void verAlquileresActivos() const;
    void verHistorialAlquileres() const;

public:
    SistemaAlquiler();
    void ejecutar();
};

#endif
