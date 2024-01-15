#pragma once

#include <iostream>

#include <SDL2/SDL_image.h>

namespace flux
{
    /**
     * @class Texture
     * @brief Class for handling textures.
     */
    class Texture
    {
    public:
        /**
         * @enum FlipMode
         * @brief Enum class for different flip modes.
         */
        enum class FlipMode
        {
            None = 0,       ///< No flip.
            Horizontal = 1, ///< Flip horizontally.
            Vertical = 2,   ///< Flip vertically.
        };

        /**
         * @enum ScaleMode
         * @brief Enum class for different scale modes.
         */
        enum class ScaleMode
        {
            Nearest = 0, ///< Nearest pixel sampling.
            Linear = 1,  ///< Linear filtering (supported by OpenGL and Direct3D).
            Best = 2,    ///< Anisotropic filtering (supported by Direct3D).
        };
        
        /**
         * @brief Default constructor.
         */
        Texture();

        /**
         * @brief Destructor.
         */
        virtual ~Texture();

        /**
         * @brief Verifies the texture.
         * @return True if the texture is verified, false otherwise.
         */
        bool Verify();

        /**
         * @brief Loads a texture from a file.
         * @param filePath The file path of the texture.
         * @param ren The renderer.
         * @return The loaded texture.
         */
        SDL_Texture *Load(const char *filePath, SDL_Renderer *ren);

    protected:
        SDL_Texture *texture; ///< The SDL texture.
    };
} // namespace flux