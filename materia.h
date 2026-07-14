#ifndef MATERIA_H
#define MATERIA_H

#include <string>

class Materia
{
private:
    std::string nombre;

public:
    Materia(std::string nombre);

    std::string getNombre() const;
};

#endif
