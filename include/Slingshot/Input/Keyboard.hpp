#pragma once

#include <SDL2/SDL.h>

#include "../Enum/Key.hpp"
#include "../Enum/KeyCode.hpp"

namespace Sling
{
    class Keyboard
    {
    public:
        Keyboard();
        virtual ~Keyboard();

        bool IsDown(Key KeyDown);
        bool IsPressed(Key KeyPressed);
        bool IsReleased(Key KeyReleased);

    private:
        const Uint8 *KeyboardState;
    };
}