#include "Slingshot/Input/Keyboard.hpp"

namespace Sling
{
    Keyboard::Keyboard() {}

    bool Keyboard::IsDown(Key KeyDown)
    {
        KeyboardState = SDL_GetKeyboardState(nullptr);
        return (KeyboardState[KeyDown] != 0);
    }

    bool Keyboard::IsPressed(Key KeyPressed)
    {
        static Uint8 prevKeyboardState[SDL_NUM_SCANCODES] = {0};
        KeyboardState = SDL_GetKeyboardState(nullptr);
        return (KeyboardState[KeyPressed] != 0) && (prevKeyboardState[KeyPressed] == 0);
    }

    bool Keyboard::IsReleased(Key KeyReleased)
    {
        static Uint8 prevKeyboardState[SDL_NUM_SCANCODES] = {0};
        KeyboardState = SDL_GetKeyboardState(nullptr);
        return (KeyboardState[KeyReleased] == 0) && (prevKeyboardState[KeyReleased] != 0);
    }

    Keyboard::~Keyboard() {}
}
