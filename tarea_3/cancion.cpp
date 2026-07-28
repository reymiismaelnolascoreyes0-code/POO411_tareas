#include "Cancion.h"

Cancion::Cancion(std::string t, std::string a)
    : Audio(t, a)
{
}

void Cancion::mostrar() const
{
    std::cout << "Cancion: " << titulo
              << " - Artista: " << autor << std::endl;
}
