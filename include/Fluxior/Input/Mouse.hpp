#pragma once

#include <SDL2/SDL.h>

namespace flux
{
    /**
     * @class Mouse
     * @brief A class that handles mouse input.
     */
    class Mouse
    {
    public:
        /**
         * @enum Button
         * @brief Enum class for mouse buttons.
         */
        enum class Button
        {
            Left = 1,   ///< The left mouse button.
            Middle = 2, ///< The middle mouse button.
            Right = 3,  ///< The right mouse button.
        };

        /**
         * @brief Default constructor.
         */
        Mouse();

        /**
         * @brief Destructor.
         */
        virtual ~Mouse();

        /**
         * @brief Updates the state of the mouse buttons and the mouse position.
         */
        void Update();

        /**
         * @brief Checks if a mouse button is currently pressed.
         * @param button The button to check.
         * @return true if the button is down, false otherwise.
         */
        bool IsButtonDown(Button button) const;

        /**
         * @brief Checks if a mouse button is currently not pressed.
         * @param button The button to check.
         * @return true if the button is up, false otherwise.
         */
        bool IsButtonUp(Button button) const;

        /**
         * @brief Checks if a mouse button was just pressed.
         * @param button The button to check.
         * @return true if the button was just pressed, false otherwise.
         */
        bool IsButtonPressed(Button button) const;

        /**
         * @brief Checks if a mouse button was just released.
         * @param button The button to check.
         * @return true if the button was just released, false otherwise.
         */
        bool IsButtonReleased(Button button) const;

        /**
         * @brief Gets the current x-coordinate of the mouse cursor.
         * @return The x-coordinate of the mouse cursor.
         */
        int GetX() const;

        /**
         * @brief Gets the current y-coordinate of the mouse cursor.
         * @return The y-coordinate of the mouse cursor.
         */
        int GetY() const;

    private:
        Uint8 prevMouseState[3]; ///< The previous state of the mouse buttons.
        Uint8 currMouseState[3]; ///< The current state of the mouse buttons.

        int x; ///< The x-coordinate of the mouse cursor.
        int y; ///< The y-coordinate of the mouse cursor.
    };
}