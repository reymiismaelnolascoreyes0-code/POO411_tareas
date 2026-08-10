#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <string>

class Prestamo {
private:
    std::string CodigoUsuario;
    std::string codigomaterial;

public:
    Prestamo();
    Prestamo(std::string nombreUsuario,  std::string CodigoMaterial );

    std::string getCodigoUsuario() const;
    std::string getCodigoMaterial() const;


    void mostrar() const;
};

#endif
