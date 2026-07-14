#include "Calificacion.h"

Calificacion::Calificacion(double nota)
{
    this->nota = nota;
}

void Calificacion::setNota(double nota)
{
    this->nota = nota;
}

double Calificacion::getNota() const
{
    return nota;
}
