#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
private:
    std::string codigo;
    std::string nombre;

public:
    Usuario(std::string codigo, std::string nombre);

    std::string getCodigo() const;
    std::string getNombre() const;
};

#endif
