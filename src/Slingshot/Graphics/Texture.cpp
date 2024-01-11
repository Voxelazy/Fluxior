#include "Slingshot/Graphics/Texture.hpp"

namespace Sling
{
    Texture::Texture() : texture(nullptr) {}

    bool Texture::Verify()
    {
        if (!IMG_Init(IMG_INIT_PNG) && IMG_INIT_PNG)
        {
            std::cerr << "ERROR: " << IMG_GetError << ".. Failed to Initialize PNG Image File.\n";
            return false;
        }
        if (!IMG_Init(IMG_INIT_JPG) && IMG_INIT_JPG)
        {
            std::cerr << "ERROR: " << IMG_GetError << ".. Failed to Initialize JPG Image File.\n";
            return false;
        }
        if (!IMG_Init(IMG_INIT_AVIF) && IMG_INIT_AVIF)
        {
            std::cerr << "ERROR: " << IMG_GetError << ".. Failed to Initialize AVIF Image File.\n";
            return false;
        }
        if (!IMG_Init(IMG_INIT_WEBP) && IMG_INIT_WEBP)
        {
            std::cerr << "ERROR: " << IMG_GetError << ".. Failed to Initialize WEBP Image File.\n";
            return false;
        }

        return true;
    }

    SDL_Texture *Texture::Load(const char *filePath, SDL_Renderer *ren)
    {
        texture = IMG_LoadTexture(ren, filePath);

        return texture;
    }

    Texture::~Texture()
    {
        SDL_DestroyTexture(texture);
        IMG_Quit();
    }
}