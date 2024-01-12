#pragma once

#include <SDL2/SDL.h>

namespace flux
{
    class Mouse
    {
    public:
        Mouse();
        virtual ~Mouse();

        void Update();
        bool IsButtonDown(int button) const;
        bool IsButtonUp(int button) const;
        bool IsButtonPressed(int button) const;
        bool IsButtonReleased(int button) const;

        int GetX() const;
        int GetY() const;

    private:
        Uint8 prevMouseState[3];
        Uint8 currMouseState[3];

        int x;
        int y;
    };
}
