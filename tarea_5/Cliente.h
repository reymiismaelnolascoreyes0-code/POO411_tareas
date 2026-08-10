#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>

class Cliente {
private:
    std::string cedula;
    std::string nombre;
    std::string telefono;

public:
    Cliente(std::string cedula, std::string nombre, std::string telefono);
    std::string getCedula() const;
    std::string getNombre() const;
    std::string getTelefono() const;
};

#endif
