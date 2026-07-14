#ifndef CALIFICACION_H
#define CALIFICACION_H

class Calificacion
{
private:
    double nota;

public:
    Calificacion(double nota = 0);

    void setNota(double nota);
    double getNota() const;
};

#endif
