#pragma once

namespace Sling
{
    enum class RendererMode
    {
        Accelerated = 2,
        Software = 1,
        VSync = 4,
        AcceleratedVSync = 2 | 4,
    };
} // namespace Sling
