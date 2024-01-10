#pragma once

#include <SDL2/SDL.h>

namespace Sling
{
    enum Key
    {
        N1 = SDL_SCANCODE_1,
        N2 = SDL_SCANCODE_2,
        N3 = SDL_SCANCODE_3,
        N4 = SDL_SCANCODE_4,
        N5 = SDL_SCANCODE_5,
        N6 = SDL_SCANCODE_6,
        N7 = SDL_SCANCODE_7,
        N8 = SDL_SCANCODE_8,
        N9 = SDL_SCANCODE_9,
        N0 = SDL_SCANCODE_0,

        A = SDL_SCANCODE_A,
        B = SDL_SCANCODE_B,
        C = SDL_SCANCODE_C,
        D = SDL_SCANCODE_D,
        E = SDL_SCANCODE_E,
        F = SDL_SCANCODE_F,
        G = SDL_SCANCODE_G,
        H = SDL_SCANCODE_H,
        I = SDL_SCANCODE_I,
        J = SDL_SCANCODE_J,
        K = SDL_SCANCODE_K,
        L = SDL_SCANCODE_L,
        M = SDL_SCANCODE_M,
        N = SDL_SCANCODE_N,
        O = SDL_SCANCODE_O,
        P = SDL_SCANCODE_P,
        Q = SDL_SCANCODE_Q,
        R = SDL_SCANCODE_R,
        S = SDL_SCANCODE_S,
        T = SDL_SCANCODE_T,
        U = SDL_SCANCODE_U,
        V = SDL_SCANCODE_V,
        W = SDL_SCANCODE_W,
        X = SDL_SCANCODE_X,
        Y = SDL_SCANCODE_Y,
        Z = SDL_SCANCODE_Z,

        Up = SDL_SCANCODE_UP,
        Down = SDL_SCANCODE_DOWN,
        Left = SDL_SCANCODE_LEFT,
        Right = SDL_SCANCODE_RIGHT,
        
        LAlt = SDL_SCANCODE_LALT,
        RAlt = SDL_SCANCODE_RALT,
        Alt = SDL_SCANCODE_LALT | SDL_SCANCODE_RALT,
        Backspace = SDL_SCANCODE_BACKSPACE,
        LCtrl = SDL_SCANCODE_LCTRL,
        RCtrl = SDL_SCANCODE_RCTRL,
        Ctrl = SDL_SCANCODE_LCTRL | SDL_SCANCODE_RCTRL,
        Enter = SDL_SCANCODE_KP_ENTER,
        Return = SDL_SCANCODE_RETURN,
        LShift = SDL_SCANCODE_LSHIFT,
        RShift = SDL_SCANCODE_RSHIFT,
        Shift = SDL_SCANCODE_LSHIFT | SDL_SCANCODE_RSHIFT,
        Space = SDL_SCANCODE_SPACE,
        Tab = SDL_SCANCODE_TAB,
    };
} // namespace Sling
