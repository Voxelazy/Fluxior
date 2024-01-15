#include "Fluxior/Input/Mouse.hpp"

namespace flux
{
    /**
     * @brief Default constructor.
     * Initializes the mouse position to (0, 0) and the mouse button states to 0.
     */
    Mouse::Mouse() : x(0), y(0)
    {
        for (int i = 0; i < 3; ++i)
        {
            prevMouseState[i] = 0;
            currMouseState[i] = 0;
        }
    }

    /**
     * @brief Updates the state of the mouse buttons and the mouse position.
     */
    void Mouse::Update()
    {
        for (int i = 0; i < 3; ++i)
        {
            prevMouseState[i] = currMouseState[i];
            currMouseState[i] = SDL_GetMouseState(&x, &y);
        }
    }

    /**
     * @brief Checks if a mouse button is currently pressed.
     * @param button The button to check.
     * @return true if the button is down, false otherwise.
     */
    bool Mouse::IsButtonDown(Button button) const
    {
        return (currMouseState[static_cast<int>(button) - 1] & SDL_BUTTON(static_cast<int>(button))) != 0;
    }

    /**
     * @brief Checks if a mouse button is currently not pressed.
     * @param button The button to check.
     * @return true if the button is up, false otherwise.
     */
    bool Mouse::IsButtonUp(Button button) const
    {
        return !IsButtonDown(button);
    }

    /**
     * @brief Checks if a mouse button was just pressed.
     * @param button The button to check.
     * @return true if the button was just pressed, false otherwise.
     */
    bool Mouse::IsButtonPressed(Button button) const
    {
        return IsButtonDown(button) && (prevMouseState[static_cast<int>(button) - 1] & SDL_BUTTON(static_cast<int>(button))) == 0;
    }

    /**
     * @brief Checks if a mouse button was just released.
     * @param button The button to check.
     * @return true if the button was just released, false otherwise.
     */
    bool Mouse::IsButtonReleased(Button button) const
    {
        return IsButtonUp(button) && (prevMouseState[static_cast<int>(button) - 1] & SDL_BUTTON(static_cast<int>(button))) != 0;
    }

    /**
     * @brief Gets the current x-coordinate of the mouse cursor.
     * @return The x-coordinate of the mouse cursor.
     */
    int Mouse::GetX() const
    {
        return x;
    }

    /**
     * @brief Gets the current y-coordinate of the mouse cursor.
     * @return The y-coordinate of the mouse cursor.
     */
    int Mouse::GetY() const
    {
        return y;
    }

    /**
     * @brief Destructor.
     */
    Mouse::~Mouse() {}
}