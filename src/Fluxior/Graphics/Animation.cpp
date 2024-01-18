#include "Fluxior/Graphics/Animation.hpp"

namespace flux
{
    /**
     * @brief Constructor.
     */
    Animation::Animation() : frameDuration(0.1f), frameTimer(0.0f), currentFrame(0), currentRow(-1) {}

    /**
     * @brief Destructor.
     */
    Animation::~Animation() {}

    /**
     * @brief Adds a frame to the animation.
     * @param x The x-coordinate of the frame.
     * @param y The y-coordinate of the frame.
     * @param width The width of the frame.
     * @param height The height of the frame.
     */
    void Animation::AddFrame(int x, int y, int width, int height)
    {
        SDL_Rect frame = {x, y, width, height};
        frames.push_back(frame);
    }

    /**
     * @brief Adds frames from a spritesheet to the animation.
     * @param SpriteSheetWidth The width of the spritesheet.
     * @param SpriteSheetHeight The height of the spritesheet.
     * @param FrameWidth The width of a frame.
     * @param FrameHeight The height of a frame.
     */
    void Animation::AddFramesFromSpriteSheet(int spriteSheetWidth, int spriteSheetHeight, int frameWidth, int frameHeight)
    {
        for (int y = 0; y < spriteSheetHeight; y += frameHeight)
        {
            for (int x = 0; x < spriteSheetWidth; x += frameWidth)
            {
                AddFrame(x, y, frameWidth, frameHeight);
            }
        }
    }

    /**
     * @brief Sets the duration of each frame.
     * @param duration The duration of each frame.
     */
    void Animation::SetFrameDuration(float duration)
    {
        frameDuration = duration;
    }

    /**
     * @brief Sets the current frame row.
     * @param row The row number.
     * @param frameWidth The width of a frame.
     * @param spriteSheetWidth The width of the spritesheet.
     */
    void Animation::SetCurrentFrameRow(int row, int frameWidth, int spriteSheetWidth)
    {
        if (row != currentRow)
        {
            currentRow = row;
            currentFrame = row * (spriteSheetWidth / frameWidth);
        }
    }

    /**
     * @brief Updates the animation based on the elapsed time.
     * @param deltaTime The elapsed time since the last update.
     * @param sprite The sprite to apply the animation to.
     */
    void Animation::Update(float deltaTime, Sprite sprite)
    {
        frameTimer += deltaTime;
        if (frameTimer >= frameDuration)
        {
            frameTimer -= frameDuration;
            currentFrame = (currentFrame + 1) % frames.size();
        }

        sprite.CropFrame(GetCurrentFrame().x, GetCurrentFrame().y, GetCurrentFrame().w, GetCurrentFrame().h);
    }

    /**
     * @brief Updates the animation within a specific row and applies it to a sprite.
     * @param deltaTime The elapsed time since the last update.
     * @param row The row number.
     * @param frameWidth The width of a frame.
     * @param spriteSheetWidth The width of the spritesheet.
     * @param sprite The sprite to apply the animation to.
     */
    void Animation::UpdateRow(float deltaTime, int row, int frameWidth, int spriteSheetWidth, Sprite &sprite)
    {
        frameTimer += deltaTime;
        if (frameTimer >= frameDuration)
        {
            frameTimer -= frameDuration;
            int framesPerRow = spriteSheetWidth / frameWidth;
            int startFrame = row * framesPerRow;
            currentFrame = startFrame + ((currentFrame + 1) % framesPerRow);
        }
        sprite.CropFrame(GetCurrentFrame().x, GetCurrentFrame().y, GetCurrentFrame().w, GetCurrentFrame().h);
    }

    /**
     * @brief Gets the current frame of the animation.
     * @return The current frame of the animation.
     */
    SDL_Rect Animation::GetCurrentFrame()
    {
        return frames[currentFrame];
    }
} // namespace flux