#ifndef MATERIALBIBLIOTECA_H
#define MATERIALBIBLIOTECA_H

#include <string>

class MaterialBiblioteca {
private:
    std::string codigo;
    std::string titulo;
    std::string responsable;
    bool disponible;

public:
    MaterialBiblioteca(std::string codigo, std::string titulo, std::string responsable);
    virtual ~MaterialBiblioteca();

    std::string getCodigo() const;
    std::string getTitulo() const;
    std::string getResponsable() const;
    bool getDisponible() const;

    void setDisponible(bool valor);


    virtual std::string getTipo() const = 0;
    virtual std::string getEtiquetaResponsable() const = 0;


    virtual void mostrarInfo() const;
};

#endif
