#ifndef REVISTA_H
#define REVISTA_H

#include "MaterialBiblioteca.h"

class Revista : public MaterialBiblioteca {
public:
    Revista(std::string codigo, std::string titulo, std::string editorial);

    std::string getTipo() const override;
    std::string getEtiquetaResponsable() const override;
};

#endif
