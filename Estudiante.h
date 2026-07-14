#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante
{
private:
    int matricula;
    std::string nombre;

public:
    Estudiante(int matricula, std::string nombre);

    int getMatricula() const;
    std::string getNombre() const;
};

#endif
