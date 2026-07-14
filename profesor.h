#ifndef PROFESOR_H
#define PROFESOR_H

#include <string>

class Profesor
{
private:
    std::string nombre;

public:
    Profesor(std::string nombre);

    std::string getNombre() const;
};

#endif
