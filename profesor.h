#ifndef PROFESOR_H
#define PROFESOR_H
#include <string>

class Profesor {
private:
    std::string nombreCompleto;
    std::string asignaturaImpartida;

public:
    Profesor(std::string nombreCompleto, std::string asignaturaImpartida);
    Profesor(const Profesor& copia);
    void mostrarInformacion();
};

#endif
