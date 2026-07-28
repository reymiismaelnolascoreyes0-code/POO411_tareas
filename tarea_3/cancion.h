#ifndef CANCION_H
#define CANCION_H

#include "Audio.h"

class Cancion : public Audio {
public:
    Cancion(std::string t, std::string a);

    void mostrar() const override;
};

#endif
