#include "Prestamo.h"

Prestamo::Prestamo(std::string codigoUsuario, std::string codigoMaterial) {
    this->CodigoUsuario = codigoUsuario;
    this->codigomaterial = codigoMaterial;
}

std::string Prestamo::getCodigoUsuario() const {
    return CodigoUsuario;
}

std::string Prestamo::getCodigoMaterial() const {
    return codigomaterial;
}
