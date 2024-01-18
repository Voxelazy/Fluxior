#include "Fluxior/Graphics/Texture.hpp"

namespace flux
{
    /**
     * @brief Default constructor for the Texture class.
     */
    Texture::Texture() : texture(nullptr) {}

    /**
     * @brief Destructor for the Texture class.
     */
    Texture::~Texture()
    {
        SDL_DestroyTexture(texture);
        IMG_Quit();
    }

    /**
     * @brief Verifies the initialization of various image formats.
     * @return true if all formats are initialized successfully, false otherwise.
     * @throws std::runtime_error if an image format fails to initialize.
     */
    bool Texture::Verify()
    {
        if (!IMG_Init(IMG_INIT_PNG) && IMG_INIT_PNG)
        {
            throw std::runtime_error("ERROR: " + std::string(IMG_GetError()) + ".. Failed to Initialize PNG Image File.\n");
        }
        if (!IMG_Init(IMG_INIT_JPG) && IMG_INIT_JPG)
        {
            throw std::runtime_error("ERROR: " + std::string(IMG_GetError()) + ".. Failed to Initialize JPG Image File.\n");
        }
        if (!IMG_Init(IMG_INIT_AVIF) && IMG_INIT_AVIF)
        {
            throw std::runtime_error("ERROR: " + std::string(IMG_GetError()) + ".. Failed to Initialize AVIF Image File.\n");
        }
        if (!IMG_Init(IMG_INIT_WEBP) && IMG_INIT_WEBP)
        {
            throw std::runtime_error("ERROR: " + std::string(IMG_GetError()) + ".. Failed to Initialize WEBP Image File.\n");
        }

        return true;
    }

    /**
     * @brief Loads a texture from a file.
     * @param filePath The path to the texture file.
     * @param ren The renderer.
     * @return The loaded texture.
     */
    SDL_Texture *Texture::Load(const char *filePath, SDL_Renderer *ren)
    {
        texture = IMG_LoadTexture(ren, filePath);

        return texture;
    }
}