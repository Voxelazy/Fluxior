#include "Fluxior/Physics/AABB.hpp"

namespace flux
{
    AABB::AABB(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}

    AABB::~AABB() {}

    void AABB::Update(float newX, float newY)
    {
        x = newX;
        y = newY;
    }

    // Check if this AABB intersects with another
    bool AABB::Intersects(const AABB &other) const
    {
        if (x < other.x + other.w && x + w > other.x &&
            y < other.y + other.h && y + h > other.y)
        {
            return true;
        }
        
        return false;
    }
} // namespace flux