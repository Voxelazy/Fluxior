#include "Slingshot/Graphics/Camera.hpp"

namespace Sling
{
    Camera::Camera() {}
    
    Camera::Camera(int cameraXPos, int cameraYPos, int cameraWidth, int cameraHeight)
        : shakeIntensity(0.0f), shakeDuration(0.0f), shakeTimer(0.0f), zoomFactor(1.0f), targetZoom(1.0f), zoomDuration(0.0f), zoomTimer(0.0f)
    {
        position = {0, 0};
        originalPosition = {0, 0};
        targetPosition = {0, 0};

        cam = new SDL_Rect{cameraXPos, cameraYPos, cameraWidth, cameraHeight};
    }

    void Camera::Center(int x, int y, int width, int height, int windowWidth, int windowHeight)
    {
        cam->x = (x + width / 2) - windowWidth / 2;
        cam->y = (y + height / 2) - windowHeight / 2;
    }

    void Camera::KeepInBounds(int worldWidth, int worldHeight)
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
        if (cam->x > worldWidth - cam->w)
        {
            cam->x = worldWidth - cam->w;
        }
        if (cam->y > worldHeight - cam->h)
        {
            cam->y = worldHeight - cam->h;
        }
    }

    void Camera::UpdateShake(float deltaTime)
    {
        // Update camera shake effect
        if (shakeTimer > 0.0f)
        {
            float offsetX = (rand() % 200 - 100) * shakeIntensity;
            float offsetY = (rand() % 200 - 100) * shakeIntensity;
            position.x = originalPosition.x + offsetX;
            position.y = originalPosition.y + offsetY;
            shakeTimer -= deltaTime;
            if (shakeTimer <= 0.0f)
            {
                position = originalPosition; // Reset position
            }
        }
    }

    void Camera::UpdateZoom(float deltaTime)
    {
        // Update camera zoom effect
        if (zoomTimer > 0.0f)
        {
            float lerpFactor = 1.0f - (zoomTimer / zoomDuration);
            zoomFactor = originalZoom + (targetZoom - originalZoom) * lerpFactor;
            zoomTimer -= deltaTime;
            if (zoomTimer <= 0.0f)
            {
                zoomFactor = targetZoom; // Reset zoom factor
            }
        }
    }

    void Camera::Shake(float intensity, float duration)
    {
        shakeIntensity = intensity;
        shakeDuration = duration;
        shakeTimer = duration;
        originalPosition = position;
    }

    void Camera::Zoom(float factor, float duration)
    {
        targetZoom = factor;
        originalZoom = zoomFactor;
        zoomDuration = duration;
        zoomTimer = duration;
    }

    SDL_Rect Camera::ApplyTransform(const SDL_Rect &rect) const
    {
        SDL_Rect transformedRect;
        transformedRect.x = static_cast<int>(rect.x * zoomFactor) - position.x;
        transformedRect.y = static_cast<int>(rect.y * zoomFactor) - position.y;
        transformedRect.w = static_cast<int>(rect.w * zoomFactor);
        transformedRect.h = static_cast<int>(rect.h * zoomFactor);

        return transformedRect;
    }

    Camera::~Camera() {}
}