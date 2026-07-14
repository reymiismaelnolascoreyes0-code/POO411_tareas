#include "Estudiante.h"

Estudiante::Estudiante(int matricula, std::string nombre)
{
    this->matricula = matricula;
    this->nombre = nombre;
}

int Estudiante::getMatricula() const
{
    return matricula;
}

std::string Estudiante::getNombre() const
{
    return nombre;
}
