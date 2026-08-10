#include "Prestamo.h"

Prestamo::Prestamo(std::string codigoUsuario, std::string codigoMaterial) {
    this->codigoUsuario = codigoUsuario;
    this->codigoMaterial = codigoMaterial;
}

std::string Prestamo::getCodigoUsuario() const {
    return codigoUsuario;
}

std::string Prestamo::getCodigoMaterial() const {
    return codigoMaterial;
}
