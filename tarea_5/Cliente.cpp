#include "Cliente.h"

Cliente::Cliente(std::string cedula, std::string nombre, std::string telefono) : cedula(cedula), nombre(nombre), telefono(telefono) {
}

std::string Cliente::getCedula() const {
    return cedula;
}

std::string Cliente::getNombre() const {
    return nombre;
}

std::string Cliente::getTelefono() const {
    return telefono;
}
