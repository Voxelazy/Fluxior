#include "Fluxior/Audio/Music.hpp"

namespace flux
{
    Music::Music()
        : music(nullptr)
    {
        if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
        {
            std::cerr << "Grike Engine could not initialize Mixer! SDL_Mixer Error: " << Mix_GetError() << std::endl;
        }
    }

    bool Music::Load(const char *filePath)
    {
        music = Mix_LoadMUS(filePath);
        if (!music)
        {
            std::cerr << "Error loading music: " << Mix_GetError() << std::endl;
            return false;
        }
        return true;
    }

    void Music::Play(int loops)
    {
        if (music)
        {
            if (Mix_PlayMusic(music, loops) == -1)
            {
                std::cerr << "Error playing music: " << Mix_GetError() << std::endl;
            }
        }
    }

    void Music::Pause()
    {
        if (Mix_PlayingMusic())
        {
            Mix_PauseMusic();
        }
    }

    void Music::Resume()
    {
        if (Mix_PausedMusic())
        {
            Mix_ResumeMusic();
        }
    }

    void Music::Stop()
    {
        Mix_HaltMusic();
    }

    Music::~Music()
    {
        if (music)
        {
            Mix_FreeMusic(music);
            music = nullptr;
        }
    }
}