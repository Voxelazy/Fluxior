#pragma once

#include <SDL2/SDL.h>

namespace Sling
{
    enum WindowMode
    {   
        Fullscreen = SDL_WINDOW_FULLSCREEN,
        HighDPI = SDL_WINDOW_ALLOW_HIGHDPI,
        Maximized = SDL_WINDOW_MAXIMIZED,
        Minimized = SDL_WINDOW_MINIMIZED,
        Resizable = SDL_WINDOW_RESIZABLE,
        Shown = SDL_WINDOW_SHOWN,
    };
} // namespace Sling