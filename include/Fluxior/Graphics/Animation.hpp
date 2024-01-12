#pragma once

#include <vector>

#include <SDL2/SDL.h>

namespace flux
{
    class Animation
    {
    public:
        Animation();
        virtual ~Animation();

        void AddFrame(int x, int y, int width, int height);
        void SetFrameDuration(float duration);
        void Update(float deltaTime);
        SDL_Rect GetCurrentFrame();

    private:
        std::vector<SDL_Rect> frames;
        float frameDuration;
        float frameTimer;
        int currentFrame;
    };
}