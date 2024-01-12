#pragma once

#include <iostream>

#include <SDL2/SDL_image.h>

namespace flux
{
    class Texture
    {
    public:
        Texture();
        virtual ~Texture();

        bool Verify();
        SDL_Texture *Load(const char *filePath, SDL_Renderer *ren);

    protected:
        SDL_Texture *texture;
    };
}