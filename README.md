# Fluxior
an easy-to-use C++ framework for creating 2D games.

# Example usage
```
#include "Fluxior/Graphics/Window.hpp"

int main()
{
    flux::Window window("Hello, Fluxior Framework!", 800, 600);

    while (window.IsOpen())
    {
        window.Render();
    }
}
```
