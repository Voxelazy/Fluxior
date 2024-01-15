#pragma once

#include <iostream>

#include <SDL2/SDL.h>

namespace flux
{
    /**
     * @class Camera
     * @brief A class that represents a camera in a 2D game world.
     */
    class Camera
    {
    public:
        /**
         * @brief Default constructor.
         */
        Camera();

        /**
         * @brief Constructor with the specified parameters.
         * @param CameraXPos The x position of the camera.
         * @param CameraYPos The y position of the camera.
         * @param CameraWidth The width of the camera.
         * @param CameraHeight The height of the camera.
         */
        Camera(int CameraXPos, int CameraYPos, int CameraWidth, int CameraHeight);

        /**
         * @brief Destructor.
         */
        virtual ~Camera();

        /**
         * @brief Getter method for the camera's viewport.
         */
        SDL_Rect *GetCam() { return cam; }

        /**
         * @brief Centers the camera on the target.
         * @param x The x position of the target.
         * @param y The y position of the target.
         * @param width The width of the target.
         * @param height The height of the target.
         * @param WindowWidth The width of the window.
         * @param WindowHeight The height of the window.
         */
        void Center(int x, int y, int width, int height, int WindowWidth, int WindowHeight);

        /**
         * @brief Keeps the camera from clipping out of the game world.
         * @param WorldWidth The width of the game world.
         * @param WorldHeight The height of the game world.
         */
        void KeepInBounds(int WorldWidth, int WorldHeight);

    private:
        /**
         * @brief An SDL_Rect structure that represents the camera's viewport.
         */
        SDL_Rect *cam;
    };
} // namespace flux