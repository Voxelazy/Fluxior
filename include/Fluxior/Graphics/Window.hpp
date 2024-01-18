#pragma once

#include <chrono>
#include <iostream>
#include <thread>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Fluxior/Input/Keyboard.hpp"

namespace flux
{
    /**
     * @enum WindowMode
     * @brief Enum class for different window modes.
     */
    enum class WindowMode
    {
        Fullscreen = 0x00000001,                       ///< Fullscreen mode.
        Shown = 0x00000004,                            ///< Window is visible.
        Hidden = 0x00000008,                           ///< Window is not visible.
        Borderless = 0x00000010,                       ///< No window decoration.
        Resizable = 0x00000020,                        ///< Window can be resized.
        Minimized = 0x00000040,                        ///< Window is minimized.
        Maximized = 0x00000080,                        ///< Window is maximized.
        MouseGrabbed = 0x00000100,                     ///< Window has grabbed mouse input.
        InputFocus = 0x00000200,                       ///< Window has input focus.
        MouseFocus = 0x00000400,                       ///< Window has mouse focus.
        FullscreenDesktop = (Fullscreen | 0x00001000), ///< Window is a fullscreen desktop.
        Foreign = 0x00000800,                          ///< Window not created by Fluxior.
        HighDPI = 0x00002000,                          ///< Window should be created in high-DPI mode if supported.
        MouseCapture = 0x00004000,                     ///< Window has mouse captured.
        AlwaysOnTop = 0x00008000,                      ///< Window should always be above others.
        SkipTaskbar = 0x00010000,                      ///< Window should not be added to the taskbar.
        Utility = 0x00020000,                          ///< Window should be treated as a utility window.
        Tooltip = 0x00040000,                          ///< Window should be treated as a tooltip.
        PopupMenu = 0x00080000,                        ///< Window should be treated as a popup menu.
        KeyboardGrabbed = 0x00100000,                  ///< Window has grabbed keyboard input.
        InputGrabbed = MouseGrabbed,                   ///< Equivalent to MouseGrabbed.
    };

    /**
     * @enum RendererMode
     * @brief Enum class for different renderer modes.
     */
    enum class RendererMode
    {
        Software = 0x00000001,                  ///< The renderer is a software fallback.
        Accelerated = 0x00000002,               ///< The renderer uses hardware acceleration.
        VSync = 0x00000004,                     ///< Present is synchronized with the refresh rate.
        TargetTexture = 0x00000008,             ///< The renderer supports rendering to texture.
        AcceleratedVSync = Accelerated | VSync, ///< The renderer uses hardware acceleration and VSync.
    };

    /**
     * @enum EventType
     * @brief Enum class for different window event types.
     */
    enum class EventType
    {
        None,    ///< No event.
        Quit,    ///< Window close event.
        KeyDown, ///< Key press event.
        KeyUp,   ///< Key release event.
    };

    /**
     * @class Window
     * @brief Class for creating and managing a window.
     */
    class Window
    {
    public:
        /**
         * @brief Default constructor.
         */
        Window();

        /**
         * @brief Destructor.
         */
        virtual ~Window();

        /**
         * @brief Constructor to create a window with specified parameters.
         * @param Title The title of the window.
         * @param WindowWidth The width of the window.
         * @param WindowHeight The height of the window.
         * @param WinMode The window mode.
         * @param RenMode The renderer mode.
         * @param FPS The frames per second.
         */
        Window(const char *Title, uint WindowWidth, uint WindowHeight, WindowMode WinMode = WindowMode::Shown, RendererMode RenMode = RendererMode::AcceleratedVSync, const float FPS = 60.0f);

        /**
         * @brief The type of the current event.
         *
         * This member represents the type of the event that is currently being processed.
         * It is updated by the UpdateEvent function each time it is called.
         */
        EventType Event;

        /**
         * @brief The key code of the current event.
         *
         * This member represents the key code of the key that was pressed or released
         * during a key down or key up event. It is updated by the UpdateEvent function
         * each time it is called.
         */
        KeyCode Keycode;

        /**
         * @brief Gets the delta time variable.
         * @return The delta time.
         */
        float GetDeltaTime() const { return deltaTime; }

        /**
         * @brief Gets the renderer.
         * @return The renderer.
         */
        SDL_Renderer *GetRenderer() const { return renderer.get(); }

        /**
         * @brief Creates a window with the specified parameters.
         * @param Title The title of the window.
         * @param WindowWidth The width of the window.
         * @param WindowHeight The height of the window.
         * @param WinMode The window mode.
         * @param RenMode The renderer mode.
         * @param FPS The frames per second.
         * @return True if the window was successfully created, false otherwise.
         */
        bool Create(const char *Title, uint WindowWidth, uint WindowHeight, WindowMode WinMode, RendererMode RenMode, const float FPS);

        /**
         * @brief Sets the window's icon.
         * @param IconPath The file path of the icon image.
         *
         * This function loads an image from the specified file path using IMG_Load,
         * sets it as the window icon with SDL_SetWindowIcon, and then frees the surface
         * with SDL_FreeSurface. If the image fails to load, it prints an error message
         * and returns.
         */
        void SetIcon(const std::string &IconPath);

        /**
         * @brief Sets the render scale quality.
         * @param QualityMode The quality mode.
         */
        void SetRenderScaleQuality(const char *QualityMode = "nearest");

        /**
         * @brief Sets the renderer size.
         * @param RendererWidth The width of the renderer.
         * @param RendererHeight The height of the renderer.
         */
        void SetRendererSize(uint RendererWidth, uint RendererHeight);

        /**
         * @brief Renders the window.
         * @param r The red component.
         * @param g The green component.
         * @param b The blue component.
         * @param a The alpha component.
         */
        void Render(int r = 0, int g = 0, int b = 0, int a = 0);

        /**
         * @brief Checks if the window is open.
         * @return True if the window is open, false otherwise.
         */
        bool IsOpen();

        /**
         * @brief Closes the window and stops all running instances.
         */
        void Close();

    private:
        std::chrono::high_resolution_clock::time_point frameStart; ///< The start time of the current frame.
        std::chrono::duration<float, std::milli> frameDelay;       ///< The delay between frames.
        float deltaTime;                                           ///< The time since the last frame.

        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window; ///< The window.

        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer; ///< The renderer.

        static inline bool isRunning; ///< Whether the window is running.

        /**
         * @brief Updates the current event.
         *
         * This function polls for a Fluxior event and updates the "event" and "key" members of the Window class accordingly.
         * If a key down or key up event occurs, it sets "event" to "KeyDown" or "KeyUp" and sets key to the Fluxior "KeyCode" of the "key."
         * If a quit event occurs, it sets "event" to "Quit".
         * If no event occurs, it sets "event" to "None" and "key" to 0.
         */
        void UpdateEvent();

        /**
         * @brief Handles the framerate of the window.
         * @return True if successful, false otherwise.
         */
        bool HandleFramerate();
    };
} // namespace flux