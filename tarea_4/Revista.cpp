#include "Revista.h"

Revista::Revista(std::string codigo, std::string titulo, std::string editorial)
    : MaterialBiblioteca(codigo, titulo, editorial) {
}

std::string Revista::getTipo() const {
    return "Revista";
}

std::string Revista::getEtiquetaResponsable() const {
    return "Editorial";
}
