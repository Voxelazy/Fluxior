#pragma once

#include <iostream>

#include <SDL2/SDL_image.h>

namespace Sling
{
    class Texture
    {
    public:
        Texture();
        virtual ~Texture();

        SDL_Texture *texture;

        bool Verify();
        SDL_Texture *Load(const char *filePath, SDL_Renderer *ren);
    };
}