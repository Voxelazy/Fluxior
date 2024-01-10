#pragma once

#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

#include <SDL2/SDL.h>

#include "../Enum/WindowModes.hpp"
#include "../Enum/RendererModes.hpp"

namespace Sling
{
    class Window
    {
    public:
        // Default constructor
        Window();

        // Simplified constructor
        Window(const char *Title, int WindowWidth, int WindowHeight, const float FPS = 60.0f);
        // Complete constructor with every parameter that the Create function has.
        Window(const char *Title, int WindowWidth, int WindowHeight, int WorldWidth, int WorldHeight, WindowMode winMode = Shown, RendererMode renMode = AcceleratedVSync, const float FPS = 60.0f);

        // Destructor
        virtual ~Window();

        // Declaring SDL_Renderer To Display Things On Screen
        SDL_Renderer *Renderer;

        // Creates The Game Window
        bool Create(const char *Title, int WindowWidth, int WindowHeight, int WorldWidth, int WorldHeight, WindowMode winMode, RendererMode renMode, const float FPS);

        // Renders Everything Displayed Inside The Window
        void Render(int r = 0, int g = 0, int b = 0, int a = 0);

        // Exits and closes the window and all running functions.
        void Close();

        // Where The Main Game Loop Happens
        bool IsOpen();

        // Getter method for the deltaTime.
        float GetDeltaTime() const { return deltaTime; }

    private:
        // Variables for Handling FPS & Performance
        std::chrono::high_resolution_clock::time_point frameStart;
        std::chrono::duration<float, std::milli> frameDelay;
        float deltaTime;

        // Window modes
        WindowMode windowMode;

        // Renderer modes
        RendererMode rendererMode;

        // Game Window
        SDL_Window *window;

        // Game Event
        static inline SDL_Event Event;

        // Boolean Variable To Check Whether The Game Is Running Or Not
        static inline bool isRunning;

        // Used for handling events for closing & resizing the window.
        bool EventHandler();
    };
} // Sling