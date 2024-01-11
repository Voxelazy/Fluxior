#pragma once

#include <iostream>

#include <SDL2/SDL_mixer.h>

namespace Sling
{
    class Music
    {
    public:
        Music();
        virtual ~Music();

        bool Load(const char *filePath);
        void Play(int loops = -1);
        void Pause();
        void Resume();
        void Stop();

    private:
        Mix_Music *music;
    };
}