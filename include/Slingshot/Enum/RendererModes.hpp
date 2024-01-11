#pragma once

#include <SDL2/SDL.h>

namespace Sling
{
    enum RendererMode
    {
        Accelerated = SDL_RENDERER_ACCELERATED,
        Software = SDL_RENDERER_SOFTWARE,
        VSync = SDL_RENDERER_PRESENTVSYNC,
        AcceleratedVSync = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC,
    };
} // namespace Sling
