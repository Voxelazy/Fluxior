#include "Slingshot/Graphics/Window.hpp"

namespace Sling
{
    Window::Window() : window(nullptr), Renderer(nullptr) {}

    Window::Window(const char *Title, int WindowWidth, int WindowHeight, WindowMode winMode, RendererMode renMode, const float FPS)
        : window(nullptr), Renderer(nullptr)
    {
        Create(Title, WindowWidth, WindowHeight, winMode, renMode, FPS);
    }

    bool Window::Create(const char *Title, int WindowWidth, int WindowHeight, WindowMode winMode, RendererMode renMode, const float FPS)
    {
        frameDelay = std::chrono::duration<float, std::milli>(1000.0f / FPS);

        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            throw std::runtime_error("Slingshot Could Not Initialize: " + std::string(SDL_GetError()));
        }
        else
        {
            window = SDL_CreateWindow(Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, static_cast<Uint32>(winMode));
            if (!window)
            {
                SDL_Quit();
                throw std::runtime_error("Slingshot Failed to Create Window: " + std::string(SDL_GetError()));
            }

            Renderer = SDL_CreateRenderer(window, -1, static_cast<Uint32>(renMode));
            if (!Renderer)
            {
                SDL_DestroyWindow(window);
                SDL_Quit();
                throw std::runtime_error("Slingshot Failed to Create Renderer: " + std::string(SDL_GetError()));
            }
        }
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");
        SDL_RenderSetLogicalSize(Renderer, WindowWidth, WindowHeight);

        isRunning = true;

        return true;
    }

    bool Window::EventHandler()
    {
        frameStart = std::chrono::high_resolution_clock::now();

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = false;
            }
        }

        auto sleepDuration = frameDelay - std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now() - frameStart);
        if (sleepDuration.count() > 0)
        {
            std::this_thread::sleep_for(sleepDuration);
        }

        auto currentFrameTime = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration<float, std::milli>(currentFrameTime - frameStart).count() / 1000.0f;

        if (deltaTime > 0.05f)
        {
            deltaTime = 0.05f;
        }

        frameStart = currentFrameTime;

        return true;
    }

    void Window::Render(int r, int g, int b, int a)
    {
        if (Renderer)
        {
            SDL_SetRenderDrawColor(Renderer, r, g, b, a);
            SDL_RenderClear(Renderer);
        }
    }

    void Window::Close()
    {
        if (Renderer)
        {
            SDL_DestroyRenderer(Renderer);
            Renderer = nullptr;
        }

        if (window)
        {
            SDL_DestroyWindow(window);
            window = nullptr;
        }

        SDL_Quit();
    }

    bool Window::IsOpen()
    {
        EventHandler();
        SDL_RenderPresent(Renderer);

        return isRunning;
    }

    Window::~Window()
    {
        Close();

        window = nullptr;
        Renderer = nullptr;
    }
} // namespace Sling