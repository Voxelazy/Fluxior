#pragma once

#include <vector>

#include <SDL2/SDL.h>

#include "Sprite.hpp"

namespace flux
{
    /**
     * @class Animation
     * @brief Class for handling  sprite animations.
     */
    class Animation
    {
    public:
        /**
         * @brief Constructor.
         */
        Animation();

        /**
         * @brief Destructor.
         */
        virtual ~Animation();

        /**
         * @brief Adds a frame to the animation.
         * @param x The x-coordinate of the frame.
         * @param y The y-coordinate of the frame.
         * @param width The width of the frame.
         * @param height The height of the frame.
         */
        void AddFrame(int x, int y, int width, int height);

        /**
         * @brief Adds frames from a spritesheet to the animation.
         * @param SpriteSheetWidth The width of the spritesheet.
         * @param SpriteSheetHeight The height of the spritesheet.
         * @param FrameWidth The width of a frame.
         * @param FrameHeight The height of a frame.
         */
        void AddFramesFromSpriteSheet(int SpriteSheetWidth, int SpriteSheetHeight, int FrameWidth, int FrameHeight);

        /**
         * @brief Sets the duration of each frame.
         * @param duration The duration of each frame.
         */
        void SetFrameDuration(float duration);

        /**
         * @brief Sets the current frame row.
         * @param row The row number.
         * @param frameWidth The width of a frame.
         * @param spriteSheetWidth The width of the spritesheet.
         */
        void SetCurrentFrameRow(int row, int frameWidth, int spriteSheetWidth);

        /**
         * @brief Updates the animation based on the elapsed time.
         * @param deltaTime The elapsed time since the last update.
         * @param sprite The sprite to apply the animation to.
         */
        void Update(float deltaTime, Sprite sprite);

        /**
         * @brief Updates the animation within a specific row and applies it to a sprite.
         * @param deltaTime The elapsed time since the last update.
         * @param row The row number.
         * @param frameWidth The width of a frame.
         * @param spriteSheetWidth The width of the spritesheet.
         * @param sprite The sprite to apply the animation to.
         */
        void UpdateRow(float deltaTime, int row, int frameWidth, int spriteSheetWidth, Sprite &sprite);

        /**
         * @brief Gets the current frame of the animation.
         * @return The current frame of the animation.
         */
        SDL_Rect GetCurrentFrame();

    private:
        std::vector<SDL_Rect> frames; ///< The frames of the animation.
        float frameDuration;          ///< The duration of each frame.
        float frameTimer;             ///< The timer for the current frame.
        int currentFrame;             ///< The current frame of the animation.
        int currentRow;               ///< The current row of the animation.
    };
} // namespace flux