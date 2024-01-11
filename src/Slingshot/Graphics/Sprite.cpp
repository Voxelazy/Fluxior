#include "Slingshot/Graphics/Sprite.hpp"

namespace Sling
{
    Sprite::Sprite() {}
    
    Sprite::Sprite(const char *filePath, SDL_Renderer *ren)
    {
        SDL_QueryTexture(texture, NULL, NULL, &spriteRect.w, &spriteRect.h);

        frameWidth = axisRect.w = spriteRect.w;
        frameHeight = axisRect.h = spriteRect.h;

        originX = frameWidth / 2;
        originY = frameHeight / 2;

        Create(filePath, ren);
    }

    void Sprite::Create(const char *filePath, SDL_Renderer *ren)
    {
        renderer = ren;

        Verify();
        objTexture = Load(filePath, ren);
    }

    void Sprite::SetPosAndSize(float xpos, float ypos, float width, float height)
    {
        axisRect = {
            xpos, ypos, width, height};
    }

    void Sprite::CropFrame(int x, int y, int w, int h)
    {
        spriteRect = {
            x, y, w, h};
    }

    void Sprite::RenderSprite(float angle, Flipped flip, SDL_FPoint *center)
    {
        SDL_RenderCopyExF(renderer, objTexture, &spriteRect, &axisRect, angle, center, static_cast<SDL_RendererFlip>(flip));
    }

    void Sprite::RenderSpriteCamOBJ(int x, int y)
    {
        if (renderer)
        {
            axisRect.x -= x;
            axisRect.y -= y;
            SDL_RenderCopyF(renderer, objTexture, &spriteRect, &axisRect);
        }
    }

    void Sprite::RenderSpriteCamBG(SDL_Rect *clip)
    {
        if (clip != NULL)
        {
            axisRect.w = clip->w;
            axisRect.h = clip->h;
        }

        SDL_RenderCopyExF(renderer, objTexture, clip, &axisRect, 0.0, NULL, SDL_FLIP_NONE);
    }

    Sprite::~Sprite()
    {
        SDL_DestroyTexture(objTexture);
        IMG_Quit();
    }
}