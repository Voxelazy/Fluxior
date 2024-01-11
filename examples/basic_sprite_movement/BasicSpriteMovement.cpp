// Include the necessary libraries from the Slingshot framework
#include "Slingshot/Graphics/Window.hpp" // For creating and managing a window
#include "Slingshot/Graphics/Sprite.hpp" // For creating and managing sprites (2D images)
#include "Slingshot/Input/Keyboard.hpp"  // For handling keyboard input

// Initialize player position and speed
int player_x = 375.0f;           // Player's initial x-coordinate
int player_y = 275.0f;           // Player's initial y-coordinate
const float player_speed = 3.0f; // Speed at which the player moves

// Set the frames per second
const float FPS = 60.0f;

int main()
{
    // Create a window with specified title, dimensions, window mode, renderer mode, and FPS
    Sling::Window window("Hello, Slingshot Framework!", 800, 600, Sling::WindowMode::Shown, Sling::RendererMode::AcceleratedVSync, FPS);

    // Create a sprite with the specified texture and renderer
    Sling::Sprite image("Textures/ball.png", window.GetRenderer());
    // Crop the sprite to the desired frame
    image.CropFrame(0, 0, 128, 128);

    // Create a keyboard object for handling keyboard input
    Sling::Keyboard keyboard;

    // Game loop
    while (window.IsOpen())
    {
        // Set the position and size of the sprite
        image.SetPosAndSize(player_x, player_y, 50, 50);

        // Move the player based on keyboard input
        if (keyboard.IsDown(Sling::Key::W)) // Move up
        {
            player_y -= player_speed;
        }
        if (keyboard.IsDown(Sling::Key::A)) // Move left
        {
            player_x -= player_speed;
        }
        if (keyboard.IsDown(Sling::Key::S)) // Move down
        {
            player_y += player_speed;
        }
        if (keyboard.IsDown(Sling::Key::D)) // Move right
        {
            player_x += player_speed;
        }

        // Render the window
        window.Render();

        // Render the sprite
        image.RenderSprite();
    }
}