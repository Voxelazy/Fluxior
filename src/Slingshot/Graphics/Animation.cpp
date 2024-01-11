#include "../../include/Graphics/Animation.hpp"

namespace Sling
{
    Animation::Animation()
        : frameDuration(0.1f), frameTimer(0.0f), currentFrame(0) {}

    void Animation::AddFrame(int x, int y, int width, int height)
    {
        SDL_Rect frame = {x, y, width, height};
        frames.push_back(frame);
    }

    void Animation::SetFrameDuration(float duration)
    {
        frameDuration = duration;
    }

    void Animation::Update(float deltaTime)
    {
        frameTimer += deltaTime;
        if (frameTimer >= frameDuration)
        {
            frameTimer -= frameDuration;
            currentFrame = (currentFrame + 1) % frames.size();
        }
    }

    SDL_Rect Animation::GetCurrentFrame()
    {
        return frames[currentFrame];
    }

    Animation::~Animation() {}
}