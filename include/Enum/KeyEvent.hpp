#pragma once

#include <SDL2/SDL.h>

namespace Sling
{
    enum KeyEvent
    {
        Ev_N1 = SDLK_1,
        Ev_N2 = SDLK_2,
        Ev_N3 = SDLK_3,
        Ev_N4 = SDLK_4,
        Ev_N5 = SDLK_5,
        Ev_N6 = SDLK_6,
        Ev_N7 = SDLK_7,
        Ev_N8 = SDLK_8,
        Ev_N9 = SDLK_9,
        Ev_N0 = SDLK_0,

        Ev_A = SDLK_a,
        Ev_B = SDLK_b,
        Ev_C = SDLK_c,
        Ev_D = SDLK_d,
        Ev_E = SDLK_e,
        Ev_F = SDLK_f,
        Ev_G = SDLK_g,
        Ev_H = SDLK_h,
        Ev_I = SDLK_i,
        Ev_J = SDLK_j,
        Ev_K = SDLK_k,
        Ev_L = SDLK_l,
        Ev_M = SDLK_m,
        Ev_N = SDLK_n,
        Ev_O = SDLK_o,
        Ev_P = SDLK_p,
        Ev_Q = SDLK_q,
        Ev_R = SDLK_r,
        Ev_S = SDLK_s,
        Ev_T = SDLK_t,
        Ev_U = SDLK_u,
        Ev_V = SDLK_v,
        Ev_W = SDLK_w,
        Ev_X = SDLK_x,
        Ev_Y = SDLK_y,
        Ev_Z = SDLK_z,

        Ev_Up = SDLK_UP,
        Ev_Down = SDLK_DOWN,
        Ev_Left = SDLK_LEFT,
        Ev_Right = SDLK_RIGHT,
        
        Ev_LAlt = SDLK_LALT,
        Ev_RAlt = SDLK_RALT,
        Ev_Alt = SDLK_LALT | SDLK_RALT,
        Ev_Backspace = SDLK_BACKSPACE,
        Ev_LCtrl = SDLK_LCTRL,
        Ev_RCtrl = SDLK_RCTRL,
        Ev_Ctrl = SDLK_LCTRL | SDLK_RCTRL,
        Ev_Enter = SDLK_KP_ENTER,
        Ev_Return = SDLK_RETURN,
        Ev_LShift = SDLK_LSHIFT,
        Ev_RShift = SDLK_RSHIFT,
        Ev_Shift = SDLK_LSHIFT | SDLK_RSHIFT,
        Ev_Space = SDLK_SPACE,
        Ev_Tab = SDLK_TAB,
    };
} // namespace Sling
