#include "Sistema.h"
#include <iostream>
#include <fstream>
#include <cstring>

Sistema::Sistema() {
}

Sistema::Sistema(const Sistema& copia) {
    for (int i = 0; i < copia.listaEstudiantes.size(); i++) {
        listaEstudiantes.push_back(std::make_unique<Estudiante>(*copia.listaEstudiantes[i]));
    }
    for (int i = 0; i < copia.listaProfesores.size(); i++) {
        listaProfesores.push_back(std::make_unique<Profesor>(*copia.listaProfesores[i]));
    }
}

void Sistema::agregar(std::unique_ptr<Estudiante> estudiante) {
    listaEstudiantes.push_back(std::move(estudiante));
}

void Sistema::agregar(std::unique_ptr<Profesor> profesor) {
    listaProfesores.push_back(std::move(profesor));
}

void Sistema::mostrarTodo() {
    std::cout << "=== PROFESORES ===" << std::endl;
    for (int i = 0; i < listaProfesores.size(); i++) {
        listaProfesores[i]->mostrarInformacion();
    }
    std::cout << "=== ESTUDIANTES ===" << std::endl;
    for (int i = 0; i < listaEstudiantes.size(); i++) {
        listaEstudiantes[i]->mostrarInformacion();
    }
}

void Sistema::guardarBinario(std::string nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::binary);

    int cantidad = listaEstudiantes.size();
    archivo.write((char*) &cantidad, sizeof(cantidad));

    for (int i = 0; i < listaEstudiantes.size(); i++) {
        RegistroAlumno registro;
        strcpy(registro.nombre, listaEstudiantes[i]->obtenerNombre().c_str());
        strcpy(registro.carnet, listaEstudiantes[i]->obtenerCarnet().c_str());
        registro.promedio = listaEstudiantes[i]->calcularPromedio();
        archivo.write((char*) &registro, sizeof(registro));
    }

    archivo.close();
    std::cout << "Datos guardados en " << nombreArchivo << std::endl;
}

void Sistema::cargarBinario(std::string nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::binary);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return;
    }

    int cantidad;
    archivo.read((char*) &cantidad, sizeof(cantidad));

    std::cout << "=== DATOS LEIDOS DEL ARCHIVO BINARIO ===" << std::endl;
    for (int i = 0; i < cantidad; i++) {
        RegistroAlumno registro;
        archivo.read((char*) &registro, sizeof(registro));
        std::cout << registro.nombre << " - " << registro.carnet << " - Promedio: " << registro.promedio << std::endl;
    }

    archivo.close();
}
