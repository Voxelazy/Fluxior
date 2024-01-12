#pragma once

#include "Texture.hpp"

namespace flux
{
    /**
     * @enum FlipMode
     * @brief Enum class for different flip modes.
     */
    enum class FlipMode
    {
        None = 0,         ///< No flip.
        Horizontally = 1, ///< Flip horizontally.
        Vertically = 2,   ///< Flip vertically.
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
     * @class Sprite
     * @brief Class for creating and managing a sprite.
     */
    class Sprite : public Texture
    {
    public:
        /**
         * @brief Default constructor.
         */
        Sprite();

        /**
         * @brief Constructor to create a sprite with specified parameters.
         * @param filePath The file path of the sprite.
         * @param ren The renderer.
         */
        Sprite(const char *filePath, SDL_Renderer *ren);

        /**
         * @brief Destructor.
         */
        virtual ~Sprite();

        /**
         * @brief Creates a sprite with the specified parameters.
         * @param filePath The file path of the sprite.
         * @param ren The renderer.
         */
        void Create(const char *filePath, SDL_Renderer *ren);

        /**
         * @brief Crops a frame from the sprite.
         * @param x The x position of the frame.
         * @param y The y position of the frame.
         * @param w The width of the frame.
         * @param h The height of the frame.
         */
        void CropFrame(int x, int y, int w, int h);

        /**
         * @brief Sets the position and size of the sprite.
         * @param xpos The x position of the sprite.
         * @param ypos The y position of the sprite.
         * @param width The width of the sprite.
         * @param height The height of the sprite.
         */
        void SetPosAndSize(float xpos, float ypos, float width, float height);

        /**
         * @brief Sets the texture scale mode of the sprite.
         * @param scaleMode The scale mode.
         */
        void SetTextureScaleMode(ScaleMode scaleMode);

        /**
         * @brief Renders the sprite.
         * @param angle The angle of rotation.
         * @param flip The flip mode.
         * @param center The point around which sprite will be rotated.
         */
        void RenderSprite(float angle = 0.0f, FlipMode flip = FlipMode::None, SDL_FPoint *center = NULL);

        void RenderSpriteCamOBJ(int x, int y);
        void RenderSpriteCamBG(SDL_Rect *clip = nullptr);

    private:
        SDL_Texture *objTexture; ///< The SDL texture.
        SDL_Rect spriteRect;     ///< The SDL rectangle for the sprite.
        SDL_FRect axisRect;      ///< The SDL floating point rectangle for the axis.
        SDL_Renderer *renderer;  ///< The SDL renderer.

        float frameWidth, frameHeight; ///< The width and height of the frame.

        float originX, originY; ///< The origin of the sprite.
        int radius;             ///< The radius of the sprite.
    };
} // namespace Sling