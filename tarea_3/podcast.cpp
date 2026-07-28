#include "Podcast.h"

Podcast::Podcast(std::string t, std::string a)
    : Audio(t, a)
{
}

void Podcast::mostrar() const
{
    std::cout << "Podcast: " << titulo
              << " - Presentador: " << autor << std::endl;
}
