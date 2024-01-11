#pragma once

#include <iostream>

#include <SDL2/SDL_mixer.h>

namespace Sling
{
    class Sound
    {
    public:
        Sound();
        virtual ~Sound();

        bool Load(const char *filePath);
        void Play(int channel = -1, int loops = 0);
        void Destroy();

    private:
        Mix_Chunk *soundChunk;
    };
}