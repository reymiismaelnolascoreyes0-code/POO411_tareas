#ifndef PROFESOR_H
#define PROFESOR_H
#include <string>

class Profesor {
private:
    std::string nombre;
    std::string materiaQueImparte;

public:
    Profesor(std::string nombre, std::string materiaQueImparte);
    void mostrarInformacion();
};

#endif
