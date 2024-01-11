#include "../../include/Physics/Physics.hpp"

namespace GR
{
    Physics::Physics() : physicsWorld(nullptr) {}

    Physics::~Physics()
    {
        if (physicsWorld)
        {
            delete physicsWorld;
            physicsWorld = nullptr;
        }
    }

    void Physics::Initialize()
    {
        b2Vec2 gravity(0.0f, -9.81f);
        physicsWorld = new b2World(gravity);
    }

    float Physics::GetPixelToMeter() const
    {
        return pixelToMeter;
    }

    void Physics::Step(float timeStep, int32 velocityIterations, int32 positionIterations)
    {
        if (physicsWorld)
        {
            physicsWorld->Step(timeStep, velocityIterations, positionIterations);
        }
    }

    b2Body *Physics::CreatePhysicsBody(float x, float y, float width, float height)
    {
        if (physicsWorld)
        {
            b2BodyDef bodyDef;
            bodyDef.type = b2_dynamicBody;
            bodyDef.position.Set(x, y);
            b2Body *physicsBody = physicsWorld->CreateBody(&bodyDef);

            b2PolygonShape dynamicBox;
            dynamicBox.SetAsBox(width / 2.0f, height / 2.0f);

            b2FixtureDef fixtureDef;
            fixtureDef.shape = &dynamicBox;
            fixtureDef.density = 1.0f;
            fixtureDef.friction = 0.3f;

            physicsBody->CreateFixture(&fixtureDef);
            return physicsBody;
        }

        return nullptr;
    }
}