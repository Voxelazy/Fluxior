#include "Fluxior/Graphics/Camera.hpp"

namespace flux
{
    /**
     * @brief Default constructor.
     */
    Camera::Camera() {}

    /**
     * @brief Constructor with the specified parameters.
     * @param CameraXPos The x position of the camera.
     * @param CameraYPos The y position of the camera.
     * @param CameraWidth The width of the camera.
     * @param CameraHeight The height of the camera.
     */
    Camera::Camera(int CameraXPos, int CameraYPos, int CameraWidth, int CameraHeight)
    {
        cam = new SDL_Rect{CameraXPos, CameraYPos, CameraWidth, CameraHeight};
    }

    /**
     * @brief Centers the camera on the target.
     * @param x The x position of the target.
     * @param y The y position of the target.
     * @param width The width of the target.
     * @param height The height of the target.
     * @param WindowWidth The width of the window.
     * @param WindowHeight The height of the window.
     */
    void Camera::Center(int x, int y, int width, int height, int WindowWidth, int WindowHeight)
    {
        cam->x = (x + width / 2) - WindowWidth / 2;
        cam->y = (y + height / 2) - WindowHeight / 2;
    }

    /**
     * @brief Keeps the camera from clipping out of the game world.
     * @param WorldWidth The width of the game world.
     * @param WorldHeight The height of the game world.
     */
    void Camera::KeepInBounds(int WorldWidth, int WorldHeight)
    {
        // Keep the camera in bounds
        if (cam->x < 0)
        {
            cam->x = 0;
        }
        if (cam->y < 0)
        {
            cam->y = 0;
        }
        if (cam->x > WorldWidth - cam->w)
        {
            cam->x = WorldWidth - cam->w;
        }
        if (cam->y > WorldHeight - cam->h)
        {
            cam->y = WorldHeight - cam->h;
        }
    }

    /**
     * @brief Destructor.
     */
    Camera::~Camera() {}
} // namespace flux