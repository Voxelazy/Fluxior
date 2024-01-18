#pragma once

#include "Texture.hpp"

namespace flux
{
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
         * @brief Destructor.
         */
        virtual ~Sprite();

        /**
         * @brief Constructor to create a sprite with specified parameters.
         * @param filePath The file path of the sprite.
         * @param ren The renderer.
         */
        Sprite(const char *filePath, SDL_Renderer *ren);

        /**
         * @brief Gets the sprite's axis rectangle.
         * @return The sprite's axis rectangle.
         */
        SDL_FRect GetAxisRect() const { return axisRect; }

        /**
         * @brief Gets the sprite's frame width.
         * @return The sprite's frame width.
         */
        float GetFrameWidth() const { return frameWidth; }

        /**
         * @brief Gets the sprite's frame height.
         * @return The sprite's frame height.
         */
        float GetFrameHeight() const { return frameHeight; }

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
         * @param xPos The x position of the sprite.
         * @param yPos The y position of the sprite.
         * @param width The width of the sprite.
         * @param height The height of the sprite.
         */
        void SetPosAndSize(float xPos, float yPos, float width, float height);

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
        void RenderSprite(float angle = 0.0f, FlipMode flip = FlipMode::None, SDL_FPoint *center = nullptr);

        /**
         * @brief Renders a sprite that does not follow the camera's movements.
         *
         * This function should only be used if there is a camera.
         *
         * @param x The x-coordinate of the camera's viewport.
         * @param y The y-coordinate of the camera's viewport.
         * @param angle The angle of rotation.
         * @param flip The flip mode.
         * @param center The point around which sprite will be rotated.
         */
        void RenderNonFollowSprite(int x, int y, float angle = 0.0f, FlipMode flip = FlipMode::None, SDL_FPoint *center = nullptr);

        /**
         * @brief Renders a sprite that represents the game world or background.
         *
         * This function should only be used for rendering background or game world sprites in games with a camera.
         *
         * @param cam The camera's viewport of the Camera class.
         * @param angle The angle of rotation.
         * @param flip The flip mode.
         * @param center The point around which sprite will be rotated.
         */
        void RenderWorldSprite(SDL_Rect *cam = nullptr, float angle = 0.0f, FlipMode flip = FlipMode::None, SDL_FPoint *center = nullptr);

    private:
        SDL_Texture *objTexture; ///< The SDL texture.
        SDL_Rect spriteRect;     ///< The SDL rectangle for the sprite.
        SDL_FRect axisRect;      ///< The SDL floating point rectangle for the axis.
        SDL_Renderer *renderer;  ///< The SDL renderer.

        float frameWidth, frameHeight; ///< The width and height of the frame.

        float originX, originY; ///< The origin of the sprite.
        int radius;             ///< The radius of the sprite.
    };
} // namespace flux