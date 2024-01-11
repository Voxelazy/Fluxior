#pragma once

#include <SDL2/SDL.h>

namespace Sling
{
    enum Flipped
    {
        Horizontally = SDL_FLIP_HORIZONTAL,
        None = SDL_FLIP_NONE,
        Vertically = SDL_FLIP_VERTICAL,
    };
} // namespace Sling
