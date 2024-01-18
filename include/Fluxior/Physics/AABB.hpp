#pragma once

#include <SDL2/SDL.h>

namespace flux
{
    class AABB
    {
    public:
        // Constructor
        AABB(float x, float y, float w, float h);
        virtual ~AABB();

        // Update the position of the AABB
        void Update(float newX, float newY);

        // Check if this AABB intersects with another
        bool Intersects(const AABB& other) const;

    private:
        float x, y; ///< The top-left corner of the AABB
        float w, h; ///< The width and height of the AABB
    };
}