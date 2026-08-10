#ifndef SISTEMABIBLIOTECA_H
#define SISTEMABIBLIOTECA_H

#include <vector>
#include <memory>
#include <string>
#include "MaterialBiblioteca.h"
#include "Usuario.h"
#include "Prestamo.h"

class SistemaBiblioteca {
private:
    std::vector<std::unique_ptr<MaterialBiblioteca>> materiales;
    std::vector<Usuario> usuarios;
    std::vector<Prestamo> prestamos;

    static const int MAX_PRESTAMOS_POR_USUARIO = 3;

    std::string archivoMateriales;
    std::string archivoUsuarios;
    std::string archivoPrestamos;

    // Validaciones
    bool existeCodigoMaterial(const std::string &codigo) const;
    bool existeCodigoUsuario(const std::string &codigo) const;
    bool existeUsuario(const std::string &codigo) const;
    int contarPrestamosActivos(const std::string &codigoUsuario) const;

    // Persistencia (guardado)
    void guardarMateriales() const;
    void guardarUsuarios() const;
    void guardarPrestamos() const;
    void guardarTodo() const;

    // Persistencia (carga)
    void cargarMateriales();
    void cargarUsuarios();
    void cargarPrestamos();

public:
    SistemaBiblioteca();

    void registrarLibro();
    void registrarRevista();
    void registrarUsuario();
    void prestarMaterial();
    void devolverMaterial();
    void mostrarMateriales();

    void ejecutarMenu();
};

#endif
