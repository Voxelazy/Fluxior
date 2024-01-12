#pragma once

#include <SDL2/SDL.h>

#include "Key.hpp"
#include "KeyCode.hpp"

namespace flux
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