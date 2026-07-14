#include "Profesor.h"

Profesor::Profesor(std::string nombre)
{
    this->nombre = nombre;
}

std::string Profesor::getNombre() const
{
    return nombre;
}
