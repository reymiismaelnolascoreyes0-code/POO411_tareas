#ifndef LIBRO_H
#define LIBRO_H

#include "MaterialBiblioteca.h"

class Libro : public MaterialBiblioteca {
public:
    Libro(std::string codigo, std::string titulo, std::string autor);

    std::string getTipo() const override;
    std::string getEtiquetaResponsable() const override;
};

#endif
