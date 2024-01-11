#include "Slingshot/Input/Mouse.hpp"

namespace Sling
{
    Mouse::Mouse() : x(0), y(0)
    {
        for (int i = 0; i < 3; ++i)
        {
            prevMouseState[i] = 0;
            currMouseState[i] = 0;
        }
    }

    void Mouse::Update()
    {
        for (int i = 0; i < 3; ++i)
        {
            prevMouseState[i] = currMouseState[i];
            currMouseState[i] = SDL_GetMouseState(&x, &y);
        }
    }

    bool Mouse::IsButtonDown(int button) const
    {
        return (currMouseState[button - 1] & SDL_BUTTON(button)) != 0;
    }

    bool Mouse::IsButtonUp(int button) const
    {
        return !IsButtonDown(button);
    }

    bool Mouse::IsButtonPressed(int button) const
    {
        return IsButtonDown(button) && (prevMouseState[button - 1] & SDL_BUTTON(button)) == 0;
    }

    bool Mouse::IsButtonReleased(int button) const
    {
        return IsButtonUp(button) && (prevMouseState[button - 1] & SDL_BUTTON(button)) != 0;
    }

    int Mouse::GetX() const
    {
        return x;
    }

    int Mouse::GetY() const
    {
        return y;
    }

    Mouse::~Mouse() {}
}
