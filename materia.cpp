#include "Materia.h"

Materia::Materia(std::string titulo, std::string clave) : titulo(titulo), clave(clave) {
}

Materia::Materia(const Materia& copia) : titulo(copia.titulo), clave(copia.clave) {
}

std::string Materia::obtenerTitulo() {
    return titulo;
}

std::string Materia::obtenerClave() {
    return clave;
}
