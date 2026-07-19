#ifndef MATERIA_H
#define MATERIA_H
#include <string>

class Materia {
private:
    std::string titulo;
    std::string clave;

public:
    Materia(std::string titulo, std::string clave);
    Materia(const Materia& copia);
    std::string obtenerTitulo();
    std::string obtenerClave();
};

#endif
