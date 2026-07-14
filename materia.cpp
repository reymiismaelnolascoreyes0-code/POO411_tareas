#include "Materia.h"

Materia::Materia(std::string nombre)
{
    this->nombre = nombre;
}

std::string Materia::getNombre() const
{
    return nombre;
}
