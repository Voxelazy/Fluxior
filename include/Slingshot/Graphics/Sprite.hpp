#pragma once

#include "Texture.hpp"
#include "../Enum/FlipModes.hpp"

namespace Sling
{
    class Sprite : public Texture
    {
    public:
        // Default Constructor
        Sprite();

        Sprite(const char *filePath, SDL_Renderer *ren);
        virtual ~Sprite();

        void Create(const char *filePath, SDL_Renderer *ren);
        void SetPosAndSize(float xpos, float ypos, float width, float height);
        void CropFrame(int x, int y, int w, int h);
        void RenderSprite(float angle = 0.0f, Flipped flip = Flipped::None, SDL_FPoint *center = NULL);
        void RenderSpriteCamOBJ(int x, int y);
        void RenderSpriteCamBG(SDL_Rect *clip = nullptr);

    private:
        SDL_Texture *objTexture;
        SDL_Rect spriteRect;
        SDL_FRect axisRect;
        SDL_Renderer *renderer;

        float frameWidth, frameHeight;

        float originX, originY;
        int radius;
    };
}