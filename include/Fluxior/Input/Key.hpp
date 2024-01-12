#pragma once

namespace flux
{
    enum class Key
    {
        N1 = 30,
        N2 = 31,
        N3 = 32,
        N4 = 33,
        N5 = 34,
        N6 = 35,
        N7 = 36,
        N8 = 37,
        N9 = 38,
        N0 = 39,

        A = 4,
        B = 5,
        C = 6,
        D = 7,
        E = 8,
        F = 9,
        G = 10,
        H = 11,
        I = 12,
        J = 13,
        K = 14,
        L = 15,
        M = 16,
        N = 17,
        O = 18,
        P = 19,
        Q = 20,
        R = 21,
        S = 22,
        T = 23,
        U = 24,
        V = 25,
        W = 26,
        X = 27,
        Y = 28,
        Z = 29,

        Right = 79,
        Left = 80,
        Down = 81,
        Up = 82,

        LAlt = 226,
        RAlt = 230,
        Alt = 226 | 230,
        Backspace = 42,
        LCtrl = 224,
        RCtrl = 228,
        Ctrl = 224 | 228,
        End = 77,
        Enter = 88,
        Escape = 41,
        LGUI = 227,
        RGUI = 231,
        Return = 40,
        LShift = 225,
        RShift = 229,
        Shift = 225 | 229,
        Space = 44,
        Tab = 43,

        Minus = 45,
        Equals = 46,
        LeftBracket = 47,
        RightBracket = 48,
        Backslash = 49,
        NonUSHash = 50,
        SemiColon = 51,
        Apostrophe = 52,
        Grave = 53,
        Comma = 54,
        Period = 55,
        Slash = 56,

        CapsLock = 57,

        F1 = 58,
        F2 = 59,
        F3 = 60,
        F4 = 61,
        F5 = 62,
        F6 = 63,
        F7 = 64,
        F8 = 65,
        F9 = 66,
        F10 = 67,
        F11 = 68,
        F12 = 69,

        PrintScreen = 70,
        ScrollLock = 71,
        Pause = 72,
        Insert = 73,
        Home = 74,
        PageUp = 75,
        PageDelete = 76,
        PageEnd = 77,
        PageDown = 78,

        NumLockClear = 83,
        PadDivide = 84,
        PadMultiply = 85,
        PadMinus = 86,
        PadPlus = 87,
        PadEnter = 88,
        Pad1 = 89,
        Pad2 = 90,
        Pad3 = 91,
        Pad4 = 92,
        Pad5 = 93,
        Pad6 = 94,
        Pad7 = 95,
        Pad8 = 96,
        Pad9 = 97,
        Pad0 = 98,
        PadPeriod = 99,

        NonUSBackslash = 100,
        Application = 101, /**< windows contextual menu, compose */
        Power = 102,
        PadEquals = 103,
        F13 = 104,
        F14 = 105,
        F15 = 106,
        F16 = 107,
        F17 = 108,
        F18 = 109,
        F19 = 110,
        F20 = 111,
        F21 = 112,
        F22 = 113,
        F23 = 114,
        F24 = 115,
        Execute = 116,
        Help = 117,
        Menu = 118,
        Select = 119,
        Stop = 120,
        Again = 121,
        Undo = 122,
        Cut = 123,
        Copy = 124,
        Paste = 125,
        Find = 126,
        Mute = 127,
        VolumeUp = 128,
        VolumeDown = 129,
        PadComma = 133,
        PadEqualsAs400 = 134,
        Interational1 = 135,
        Interational2 = 136,
        Interational3 = 137,
        Interational4 = 138,
        Interational5 = 139,
        Interational6 = 140,
        Interational7 = 141,
        Interational8 = 142,
        Interational9 = 143,
        Lang1 = 144,
        Lang2 = 145,
        Lang3 = 146,
        Lang4 = 147,
        Lang5 = 148,
        Lang6 = 149,
        Lang7 = 150,
        Lang8 = 151,
        Lang9 = 152,
        AltErase = 153,
        SysReq = 154,
        Cancel = 155,
        Clear = 156,
        Prior = 157,
        Return2 = 158,
        Separator = 159,
        Out = 160,
        Oper = 161,
        ClearAgain = 162,
        CrSel = 163,
        ExSel = 164,

        Pad00 = 176,
        Pad000 = 177,
        PadThousandsSeparator = 178,
        PadDecimalSeparator = 179,
        PadCurrencyUnit = 180,
        PadCurrencySubUnit = 181,
        PadLeftParenthesis = 182,
        PadRightParenthesis = 183,
        PadLeftBrace = 184,
        PadRightBrace = 185,
        PadTab = 186,
        PadBackspace = 187,
        PadA = 188,
        PadB = 189,
        PadC = 190,
        PadD = 191,
        PadE = 192,
        PadF = 193,
        PadXOR = 194,
        PadPower = 195,
        PadPercent = 196,
        PadLess = 197,
        PadGreater = 198,
        PadAmpersand = 199,
        PadDoubleAmpersand = 200,
        PadVerticalBar = 201,
        PadDoubleVerticalBar = 202,
        PadColon = 203,
        PadHash = 204,
        PadSpace = 205,
        PadAt = 206,
        PadExclamation = 207,
        PadMemStore = 208,
        PadMemRecall = 209,
        PadMemClear = 210,
        PadMemAdd = 211,
        PadMemSubtract = 212,
        PadMemMultiply = 213,
        PadMemDivide = 214,
        PadPlusMinus = 215,
        PadClear = 216,
        PadClearEntry = 217,
        PadBinary = 218,
        PadOctal = 219,
        PadDecimal = 220,
        PadHexadecimal = 221,

        Mode = 257,
        AudioNext = 258,
        AudioPrev = 259,
        AudioStop = 260,
        AudioPlay = 261,
        AudioMute = 262,
        MediaSelect = 263,
        WWW = 264,
        Mail = 265,
        Calculator = 266,
        Computer = 267,
        ACSearch = 268,
        ACHome = 269,
        ACBack = 270,
        ACForward = 271,
        ACStop = 272,
        ACRefresh = 273,
        ACBookmarks = 274,
        BrightnessDown = 275,
        BrightnessUp = 276,
        DisplaySwitch = 277,
        kbdIllumToggle = 278,
        kbdIllumDown = 279,
        kbdIllumUp = 280,
        Eject = 281,
        Sleep = 282,
        App1 = 283,
        App2 = 284,
        AudioRewind = 285,
        AudioFastForward = 286,
        SoftLeft = 287,
        SoftRight = 288,
        Call = 289,
        EndCall = 290,
    };
} // namespace Sling