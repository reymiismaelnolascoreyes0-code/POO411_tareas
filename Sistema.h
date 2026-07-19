#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <memory>
#include <string>
#include "Estudiante.h"
#include "Profesor.h"

struct RegistroAlumno {
    char nombre[50];
    char carnet[20];
    double promedio;
};

class Sistema {
private:
    std::vector<std::unique_ptr<Estudiante>> listaEstudiantes;
    std::vector<std::unique_ptr<Profesor>> listaProfesores;

public:
    Sistema();
    Sistema(const Sistema& copia);
    void agregar(std::unique_ptr<Estudiante> estudiante);
    void agregar(std::unique_ptr<Profesor> profesor);
    void mostrarTodo();
    void guardarBinario(std::string nombreArchivo);
    void cargarBinario(std::string nombreArchivo);
};

#endif
