#include "Libro.h"

Libro::Libro(std::string codigo, std::string titulo, std::string autor)
    : MaterialBiblioteca(codigo, titulo, autor) {
}

std::string Libro::getTipo() const {
    return "Libro";
}

std::string Libro::getEtiquetaResponsable() const {
    return "Autor";
}
