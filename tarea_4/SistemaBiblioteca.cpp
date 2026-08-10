#include "SistemaBiblioteca.h"
#include "Libro.h"
#include "Revista.h"
#include <iostream>
#include <fstream>
#include <sstream>

static std::vector<std::string> separarLinea(const std::string &linea, char separador) {
    std::vector<std::string> partes;
    std::stringstream flujo(linea);
    std::string parte;

    while (std::getline(flujo, parte, separador)) {
        partes.push_back(parte);
    }

    return partes;
}

SistemaBiblioteca::SistemaBiblioteca() {
    archivoMateriales = "materiales.txt";
    archivoUsuarios = "usuarios.txt";
    archivoPrestamos = "prestamos.txt";

    cargarMateriales();
    cargarUsuarios();
    cargarPrestamos();
}

bool SistemaBiblioteca::existeCodigoMaterial(const std::string &codigo) const {
    for (const std::unique_ptr<MaterialBiblioteca> &material : materiales) {
        if (material->getCodigo() == codigo) {
            return true;
        }
    }
    return false;
}

bool SistemaBiblioteca::existeCodigoUsuario(const std::string &codigo) const {
    for (const Usuario &usuario : usuarios) {
        if (usuario.getCodigo() == codigo) {
            return true;
        }
    }
    return false;
}

bool SistemaBiblioteca::existeUsuario(const std::string &codigo) const {
    return existeCodigoUsuario(codigo);
}

int SistemaBiblioteca::contarPrestamosActivos(const std::string &codigoUsuario) const {
    int contador = 0;
    for (const Prestamo &prestamo : prestamos) {
        if (prestamo.getCodigoUsuario() == codigoUsuario) {
            contador++;
        }
    }
    return contador;
}

void SistemaBiblioteca::guardarMateriales() const {
    std::ofstream archivo(archivoMateriales);

    for (const std::unique_ptr<MaterialBiblioteca> &material : materiales) {
        std::string tipo = (material->getTipo() == "Libro") ? "1" : "2";
        archivo << tipo << "|" << material->getCodigo() << "|" << material->getTitulo()
                << "|" << material->getResponsable() << "|" << material->getDisponible() << "\n";
    }
}

void SistemaBiblioteca::guardarUsuarios() const {
    std::ofstream archivo(archivoUsuarios);

    for (const Usuario &usuario : usuarios) {
        archivo << usuario.getCodigo() << "|" << usuario.getNombre() << "\n";
    }
}

void SistemaBiblioteca::guardarPrestamos() const {
    std::ofstream archivo(archivoPrestamos);

    for (const Prestamo &prestamo : prestamos) {
        archivo << prestamo.getCodigoUsuario() << "|" << prestamo.getCodigoMaterial() << "\n";
    }
}

void SistemaBiblioteca::guardarTodo() const {
    guardarMateriales();
    guardarUsuarios();
    guardarPrestamos();
}

void SistemaBiblioteca::cargarMateriales() {
    std::ifstream archivo(archivoMateriales);
    std::string linea;

    while (std::getline(archivo, linea)) {
        if (linea.empty()) {
            continue;
        }

        std::vector<std::string> partes = separarLinea(linea, '|');
        if (partes.size() < 5) {
            continue;
        }

        std::string tipo = partes[0];
        std::string codigo = partes[1];
        std::string titulo = partes[2];
        std::string responsable = partes[3];
        bool disponible = (partes[4] == "1");

        if (tipo == "1") {
            std::unique_ptr<Libro> libro(new Libro(codigo, titulo, responsable));
            libro->setDisponible(disponible);
            materiales.push_back(std::move(libro));
        } else if (tipo == "2") {
            std::unique_ptr<Revista> revista(new Revista(codigo, titulo, responsable));
            revista->setDisponible(disponible);
            materiales.push_back(std::move(revista));
        }
    }
}

void SistemaBiblioteca::cargarUsuarios() {
    std::ifstream archivo(archivoUsuarios);
    std::string linea;

    while (std::getline(archivo, linea)) {
        if (linea.empty()) {
            continue;
        }

        std::vector<std::string> partes = separarLinea(linea, '|');
        if (partes.size() < 2) {
            continue;
        }

        usuarios.push_back(Usuario(partes[0], partes[1]));
    }
}

void SistemaBiblioteca::cargarPrestamos() {
    std::ifstream archivo(archivoPrestamos);
    std::string linea;

    while (std::getline(archivo, linea)) {
        if (linea.empty()) {
            continue;
        }

        std::vector<std::string> partes = separarLinea(linea, '|');
        if (partes.size() < 2) {
            continue;
        }

        prestamos.push_back(Prestamo(partes[0], partes[1]));
    }
}

void SistemaBiblioteca::registrarLibro() {
    std::string codigo;
    std::string titulo;
    std::string autor;

    std::cout << "Codigo del libro: ";
    std::getline(std::cin, codigo);

    if (existeCodigoMaterial(codigo)) {
        std::cout << "Ya existe un material con ese codigo.\n";
        return;
    }

    std::cout << "Titulo: ";
    std::getline(std::cin, titulo);
    std::cout << "Autor: ";
    std::getline(std::cin, autor);

    materiales.push_back(std::unique_ptr<Libro>(new Libro(codigo, titulo, autor)));
    guardarMateriales();
    std::cout << "Libro registrado.\n";
}

void SistemaBiblioteca::registrarRevista() {
    std::string codigo;
    std::string titulo;
    std::string editorial;

    std::cout << "Codigo de la revista: ";
    std::getline(std::cin, codigo);

    if (existeCodigoMaterial(codigo)) {
        std::cout << "Ya existe un material con ese codigo.\n";
        return;
    }

    std::cout << "Titulo: ";
    std::getline(std::cin, titulo);
    std::cout << "Editorial: ";
    std::getline(std::cin, editorial);

    materiales.push_back(std::unique_ptr<Revista>(new Revista(codigo, titulo, editorial)));
    guardarMateriales();
    std::cout << "Revista registrada.\n";
}

void SistemaBiblioteca::registrarUsuario() {
    std::string codigo;
    std::string nombre;

    std::cout << "Codigo del usuario: ";
    std::getline(std::cin, codigo);

    if (existeCodigoUsuario(codigo)) {
        std::cout << "Ya existe un usuario con ese codigo.\n";
        return;
    }

    std::cout << "Nombre completo: ";
    std::getline(std::cin, nombre);

    usuarios.push_back(Usuario(codigo, nombre));
    guardarUsuarios();
    std::cout << "Usuario registrado.\n";
}

void SistemaBiblioteca::mostrarMateriales() {
    if (materiales.empty()) {
        std::cout << "No hay materiales registrados.\n";
        return;
    }

    std::cout << "\n--- Materiales ---\n";
    for (const std::unique_ptr<MaterialBiblioteca> &material : materiales) {
        material->mostrarInfo();
    }
}

void SistemaBiblioteca::prestarMaterial() {
    std::string codigoUsuario;
    std::string codigoMaterial;

    std::cout << "Codigo del usuario: ";
    std::getline(std::cin, codigoUsuario);

    if (!existeUsuario(codigoUsuario)) {
        std::cout << "Usuario no encontrado.\n";
        return;
    }

    if (contarPrestamosActivos(codigoUsuario) >= MAX_PRESTAMOS_POR_USUARIO) {
        std::cout << "El usuario ya tiene el maximo de " << MAX_PRESTAMOS_POR_USUARIO
                  << " prestamos activos.\n";
        return;
    }

    std::cout << "Codigo del material: ";
    std::getline(std::cin, codigoMaterial);

    for (std::unique_ptr<MaterialBiblioteca> &material : materiales) {
        if (material->getCodigo() == codigoMaterial) {
            if (!material->getDisponible()) {
                std::cout << "El material no esta disponible.\n";
                return;
            }

            material->setDisponible(false);
            prestamos.push_back(Prestamo(codigoUsuario, codigoMaterial));
            guardarMateriales();
            guardarPrestamos();
            std::cout << "Prestamo registrado.\n";
            return;
        }
    }

    std::cout << "Material no encontrado.\n";
}

void SistemaBiblioteca::devolverMaterial() {
    std::string codigoMaterial;
    std::cout << "Codigo del material: ";
    std::getline(std::cin, codigoMaterial);

    for (std::size_t i = 0; i < prestamos.size(); ++i) {
        if (prestamos[i].getCodigoMaterial() == codigoMaterial) {
            for (std::unique_ptr<MaterialBiblioteca> &material : materiales) {
                if (material->getCodigo() == codigoMaterial) {
                    material->setDisponible(true);
                    prestamos.erase(prestamos.begin() + static_cast<long>(i));
                    guardarMateriales();
                    guardarPrestamos();
                    std::cout << "Material devuelto.\n";
                    return;
                }
            }
        }
    }

    std::cout << "No existe un prestamo activo para ese material.\n";
}

void SistemaBiblioteca::ejecutarMenu() {
    int opcion = -1;

    while (opcion != 0) {
        std::cout << "\n=== Biblioteca ===\n";
        std::cout << "1. Registrar libro\n";
        std::cout << "2. Registrar revista\n";
        std::cout << "3. Registrar usuario\n";
        std::cout << "4. Prestar material\n";
        std::cout << "5. Devolver material\n";
        std::cout << "6. Mostrar materiales\n";
        std::cout << "0. Salir\n";
        std::cout << "Opcion: ";

        std::cin >> opcion;
        std::cin.ignore();

        if (opcion == 1) {
            registrarLibro();
        } else if (opcion == 2) {
            registrarRevista();
        } else if (opcion == 3) {
            registrarUsuario();
        } else if (opcion == 4) {
            prestarMaterial();
        } else if (opcion == 5) {
            devolverMaterial();
        } else if (opcion == 6) {
            mostrarMateriales();
        } else if (opcion != 0) {
            std::cout << "Opcion no valida.\n";
        }
    }
}
