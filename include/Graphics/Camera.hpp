#pragma once

#include <iostream>

#include <SDL2/SDL.h>

namespace Sling
{
    class Camera
    {
    public:
        Camera(int cameraXPos, int cameraYPos, int cameraWidth, int cameraHeight);
        virtual ~Camera();

        // The Camera..
        SDL_Rect *cam;

        // Center the Camera on the target
        void Center(int x, int y, int width, int height, int windowWidth, int windowHeight);

        // Keeps the Camera from clipping out of the game world
        void KeepInBounds(int worldWidth, int worldHeight);

        // Updates the Camera shake effect
        void UpdateShake(float deltaTime);

        // Updates the Camera zoom effect
        void UpdateZoom(float deltaTime);

        void Shake(float intensity, float duration);
        void Zoom(float factor, float duration);

        SDL_Rect ApplyTransform(const SDL_Rect &rect) const;

    private:
        float shakeIntensity;
        float shakeDuration;
        float shakeTimer;

        float zoomFactor;
        float targetZoom;
        float zoomDuration;
        float zoomTimer;
        float originalZoom;

        SDL_Point position;
        SDL_Point originalPosition;
        SDL_Point targetPosition;
    };
}