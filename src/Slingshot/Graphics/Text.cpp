#include "Slingshot/Graphics/Text.hpp"

namespace Sling
{
    Text::Text() {}

    bool Text::Verify()
    {
        if (!TTF_Init())
        {
            std::cerr << "ERROR: " << TTF_GetError << ".. Failed To Initialize Font Texture." << std::endl;
            return false;
        }

        return true;
    }

    void Text::LoadFont(const char *filePath, int size)
    {
        font = TTF_OpenFont(filePath, size);
    }

    void Text::CreateText(const char *input, SDL_Renderer *Ren)
    {
        renderer = Ren;

        surface = TTF_RenderText_Solid(font, input, color);
        texture = SDL_CreateTextureFromSurface(Ren, surface);
    }

    void Text::SetPos(int xpos, int ypos)
    {
        axisRect = {
            xpos, ypos, 0, 0};
    }

    void Text::SetColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
    {
        color = {red, green, blue, alpha};
    }

    void Text::Render()
    {
        SDL_RenderCopy(renderer, texture, NULL, &axisRect);
    }

    void Text::Destroy()
    {
        SDL_DestroyTexture(texture);
    }

    Text::~Text() {}
}