#include "Fluxior/Graphics/Sprite.hpp"

namespace flux
{
    /**
     * @brief Default constructor.
     */
    Sprite::Sprite() {}

    /**
     * @brief Destructor.
     */
    Sprite::~Sprite()
    {
        // Destroy the texture
        SDL_DestroyTexture(objTexture);

        // Quit IMG
        IMG_Quit();
    }

    /**
     * @brief Constructor to create a sprite with specified parameters.
     * @param filePath The file path of the sprite.
     * @param ren The renderer.
     */
    Sprite::Sprite(const char *filePath, SDL_Renderer *ren)
    {
        // Query the texture to get its width and height
        SDL_QueryTexture(texture, NULL, NULL, &spriteRect.w, &spriteRect.h);

        // Set the frame width and height
        frameWidth = axisRect.w = spriteRect.w;
        frameHeight = axisRect.h = spriteRect.h;

        // Set the origin of the sprite
        originX = frameWidth / 2;
        originY = frameHeight / 2;

        // Create the sprite
        Create(filePath, ren);
    }

    /**
     * @brief Creates a sprite with the specified parameters.
     * @param filePath The file path of the sprite.
     * @param ren The renderer.
     */
    void Sprite::Create(const char *filePath, SDL_Renderer *ren)
    {
        // Set the renderer
        renderer = ren;

        // Verify the sprite
        Verify();

        // Load the sprite
        objTexture = Load(filePath, ren);
    }

    /**
     * @brief Crops a frame from the sprite.
     * @param x The x position of the frame.
     * @param y The y position of the frame.
     * @param w The width of the frame.
     * @param h The height of the frame.
     */
    void Sprite::CropFrame(int x, int y, int w, int h)
    {
        // Set the sprite rectangle
        spriteRect = {
            x, y, w, h};
    }

    /**
     * @brief Sets the texture scale mode of the sprite.
     * @param scaleMode The scale mode.
     */
    void Sprite::SetTextureScaleMode(ScaleMode scaleMode)
    {
        // Set the texture scale mode
        SDL_SetTextureScaleMode(objTexture, static_cast<SDL_ScaleMode>(scaleMode));
    }

    /**
     * @brief Sets the position and size of the sprite.
     * @param xPos The x position of the sprite.
     * @param yPos The y position of the sprite.
     * @param width The width of the sprite.
     * @param height The height of the sprite.
     */
    void Sprite::SetPosAndSize(float xPos, float yPos, float width, float height)
    {
        // Set the axis rectangle
        axisRect = {
            xPos, yPos, width, height};
    }

    /**
     * @brief Renders the sprite.
     * @param angle The angle of rotation.
     * @param flip The flip mode.
     * @param center The point around which sprite will be rotated.
     */
    void Sprite::RenderSprite(float angle, FlipMode flip, SDL_FPoint *center)
    {
        // Render the sprite
        SDL_RenderCopyExF(renderer, objTexture, &spriteRect, &axisRect, angle, center, static_cast<SDL_RendererFlip>(flip));
    }

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
    void Sprite::RenderNonFollowSprite(int x, int y, float angle, FlipMode flip, SDL_FPoint *center)
    {
        // Check if renderer exists
        if (renderer)
        {
            // Adjust the axis rectangle based on the camera position
            axisRect.x -= x;
            axisRect.y -= y;

            // Render the sprite
            SDL_RenderCopyExF(renderer, objTexture, &spriteRect, &axisRect, angle, center, static_cast<SDL_RendererFlip>(flip));
        }
    }

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
    void Sprite::RenderWorldSprite(SDL_Rect *cam, float angle, FlipMode flip, SDL_FPoint *center)
    {
        // Check if cam exists
        if (cam != nullptr)
        {
            // Set the axis rectangle width and height
            axisRect.w = cam->w;
            axisRect.h = cam->h;
        }

        // Render the sprite
        SDL_RenderCopyExF(renderer, objTexture, cam, &axisRect, angle, center, static_cast<SDL_RendererFlip>(flip));
    }
} // namespace flux