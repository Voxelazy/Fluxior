#pragma once

#include <SDL2/SDL.h>

#include "Key.hpp"
#include "KeyCode.hpp"

namespace flux
{
    /**
     * @class Keyboard
     * @brief Class for handling keyboard inputs.
     */
    class Keyboard
    {
    public:
        /**
         * @brief Default constructor.
         */
        Keyboard();

        /**
         * @brief Destructor.
         */
        virtual ~Keyboard();

        /**
         * @brief Checks if a key is currently being pressed down.
         * @param KeyDown The key to check.
         * @return True if the key is down, false otherwise.
         */
        bool IsDown(Key KeyDown);

        /**
         * @brief Checks if a key has just been pressed.
         * @param KeyPressed The key to check.
         * @return True if the key has just been pressed, false otherwise.
         */
        bool IsPressed(Key KeyPressed);

        /**
         * @brief Checks if a key has just been released.
         * @param KeyReleased The key to check.
         * @return True if the key has just been released, false otherwise.
         */
        bool IsReleased(Key KeyReleased);

    private:
        const Uint8 *KeyboardState; ///< The current state of the keyboard.
    };
} // namespace flux