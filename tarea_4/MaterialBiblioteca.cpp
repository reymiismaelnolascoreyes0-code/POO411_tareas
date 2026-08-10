#include "MaterialBiblioteca.h"
#include <iostream>

MaterialBiblioteca::MaterialBiblioteca(std::string codigo, std::string titulo, std::string responsable) {
    this->codigo = codigo;
    this->titulo = titulo;
    this->responsable = responsable;
    this->disponible = true;
}

MaterialBiblioteca::~MaterialBiblioteca() {
}

std::string MaterialBiblioteca::getCodigo() const {
    return codigo;
}

std::string MaterialBiblioteca::getTitulo() const {
    return titulo;
}

std::string MaterialBiblioteca::getResponsable() const {
    return responsable;
}

bool MaterialBiblioteca::getDisponible() const {
    return disponible;
}

void MaterialBiblioteca::setDisponible(bool valor) {
    disponible = valor;
}

void MaterialBiblioteca::mostrarInfo() const {
    std::cout << getTipo() << ": " << codigo << " - " << titulo << " - "
              << responsable << " - " << (disponible ? "Disponible" : "Prestado") << std::endl;
}
