#include "Fluxior/Audio/Sound.hpp"

namespace flux
{
    Sound::Sound()
        : soundChunk(nullptr)
    {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        {
            std::cerr << "Grike Engine could not initialize Mixer! SDL_Mixer Error: " << Mix_GetError() << std::endl;
        }
    }

    bool Sound::Load(const char *filePath)
    {
        soundChunk = Mix_LoadWAV(filePath);
        if (!soundChunk)
        {
            std::cerr << "Failed to load sound: " << filePath << ". SDL_Mixer Error: " << Mix_GetError() << std::endl;
            return false;
        }
        return true;
    }

    void Sound::Play(int channel, int loops)
    {
        if (soundChunk)
        {
            Mix_PlayChannel(channel, soundChunk, loops);
        }
    }

    void Sound::Destroy()
    {
        if (soundChunk)
        {
            Mix_FreeChunk(soundChunk);
            soundChunk = nullptr;
        }
        Mix_CloseAudio();
    }

    Sound::~Sound()
    {
        Destroy();
    }
}