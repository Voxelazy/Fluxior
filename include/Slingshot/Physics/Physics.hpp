#pragma once

#include <iostream>

#include <box2d/box2d.h>

namespace GR
{
    class Physics
    {
    public:
        Physics();
        ~Physics();

        void Initialize();
        void Step(float timeStep, int32 velocityIterations, int32 positionIterations);
        b2Body *CreatePhysicsBody(float x, float y, float width, float height);

        float GetPixelToMeter() const; // Function to get the pixel-to-meter conversion factor

    private:
        b2World *physicsWorld;
        float pixelToMeter;
    };
}