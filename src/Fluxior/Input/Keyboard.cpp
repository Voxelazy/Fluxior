#include "Fluxior/Input/Keyboard.hpp"

namespace flux
{
    Keyboard::Keyboard() {}

    Keyboard::~Keyboard() {}

    bool Keyboard::IsDown(Key KeyDown)
    {
        KeyboardState = SDL_GetKeyboardState(nullptr);
        return (KeyboardState[static_cast<int>(KeyDown)] != 0);
    }

    bool Keyboard::IsPressed(Key KeyPressed)
    {
        static Uint8 prevKeyboardState[SDL_NUM_SCANCODES] = {0};
        KeyboardState = SDL_GetKeyboardState(nullptr);
        return (KeyboardState[static_cast<int>(KeyPressed)] != 0) && (prevKeyboardState[static_cast<int>(KeyPressed)] == 0);
    }

    bool Keyboard::IsReleased(Key KeyReleased)
    {
        static Uint8 prevKeyboardState[SDL_NUM_SCANCODES] = {0};
        KeyboardState = SDL_GetKeyboardState(nullptr);
        return (KeyboardState[static_cast<int>(KeyReleased)] == 0) && (prevKeyboardState[static_cast<int>(KeyReleased)] != 0);
    }
} // namespace flux