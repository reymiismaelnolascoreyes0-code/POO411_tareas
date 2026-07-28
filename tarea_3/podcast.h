#ifndef PODCAST_H
#define PODCAST_H

#include "Audio.h"

class Podcast : public Audio {
public:
    Podcast(std::string t, std::string a);

    void mostrar() const override;
};

#endif
