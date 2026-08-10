#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <string>

class Prestamo {
private:
    std::string codigoUsuario;
    std::string codigoMaterial;

public:
    Prestamo(std::string codigoUsuario, std::string codigoMaterial);

    std::string getCodigoUsuario() const;
    std::string getCodigoMaterial() const;
};

#endif
