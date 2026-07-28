#ifndef AUDIO_H
#define AUDIO_H

#include <iostream>
#include <string>

class Audio {
protected:
    std::string titulo;
    std::string autor;

public:
    Audio(std::string t, std::string a);
    virtual ~Audio();

    virtual void mostrar() const = 0;
};

#endif
