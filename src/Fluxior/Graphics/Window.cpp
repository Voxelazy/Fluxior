#include "Fluxior/Graphics/Window.hpp"

namespace flux
{
    /**
     * @brief Default constructor.
     */
    Window::Window() : window(nullptr), Renderer(nullptr)
    {
        // Initialize window and Renderer to nullptr
    }

    /**
     * @brief Constructor to create a window with specified parameters.
     * @param Title The title of the window.
     * @param WindowWidth The width of the window.
     * @param WindowHeight The height of the window.
     * @param winMode The window mode.
     * @param renMode The renderer mode.
     * @param FPS The frames per second.
     */
    Window::Window(const char *Title, uint WindowWidth, uint WindowHeight, WindowMode winMode, RendererMode renMode, const float FPS)
        : window(nullptr), Renderer(nullptr)
    {
        // Call Create method to create the window
        Create(Title, WindowWidth, WindowHeight, winMode, renMode, FPS);
    }

    /**
     * @brief Creates a window with the specified parameters.
     * @param Title The title of the window.
     * @param WindowWidth The width of the window.
     * @param WindowHeight The height of the window.
     * @param winMode The window mode.
     * @param renMode The renderer mode.
     * @param FPS The frames per second.
     * @return True if the window was successfully created, false otherwise.
     */
    bool Window::Create(const char *Title, uint WindowWidth, uint WindowHeight, WindowMode winMode, RendererMode renMode, const float FPS)
    {
        // Set frame delay based on FPS
        frameDelay = std::chrono::duration<float, std::milli>(1000.0f / FPS);

        // Initialize SDL
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            // Throw error if SDL initialization fails
            throw std::runtime_error("Slingshot Could Not Initialize: " + std::string(SDL_GetError()));
        }
        else
        {
            // Create SDL window
            window = SDL_CreateWindow(Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, static_cast<Uint32>(winMode));
            if (!window)
            {
                // Quit SDL and throw error if window creation fails
                SDL_Quit();
                throw std::runtime_error("Slingshot Failed to Create Window: " + std::string(SDL_GetError()));
            }

            // Create SDL renderer
            Renderer = SDL_CreateRenderer(window, -1, static_cast<Uint32>(renMode));
            if (!Renderer)
            {
                // Destroy window, quit SDL and throw error if renderer creation fails
                SDL_DestroyWindow(window);
                SDL_Quit();
                throw std::runtime_error("Slingshot Failed to Create Renderer: " + std::string(SDL_GetError()));
            }

            // Set render scale quality and renderer size
            SetRenderScaleQuality("nearest");
            SetRendererSize(WindowWidth, WindowHeight);
        }

        // Set running flag to true
        isRunning = true;

        return true;
    }

    /**
     * @brief Sets the render scale quality.
     * @param QualityMode The quality mode.
     */
    void Window::SetRenderScaleQuality(const char *QualityMode)
    {
        // Set render scale quality
        if (SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, QualityMode) == SDL_FALSE)
        {
            // Throw error if setting render scale quality fails
            throw std::runtime_error("Slingshot Failed to Set Render Scale Quality: " + std::string(SDL_GetError()));
        }
    }

    /**
     * @brief Sets the renderer size.
     * @param RendererWidth The width of the renderer.
     * @param RendererHeight The height of the renderer.
     */
    void Window::SetRendererSize(uint RendererWidth, uint RendererHeight)
    {
        // Set renderer size
        if (SDL_RenderSetLogicalSize(Renderer, RendererWidth, RendererHeight) != 0)
        {
            // Throw error if setting renderer size fails
            throw std::runtime_error("Slingshot Failed to Set Renderer Size: " + std::string(SDL_GetError()));
        }
    }

    /**
     * @brief Handles the framerate.
     * @return True if successful, false otherwise.
     */
    bool Window::HandleFramerate()
    {
        // Get start time of current frame
        frameStart = std::chrono::high_resolution_clock::now();

        // Poll SDL events
        while (SDL_PollEvent(&Event))
        {
            // Set running flag to false if quit event is detected
            if (Event.type == SDL_QUIT)
            {
                isRunning = false;
            }
        }

        // Calculate sleep duration to maintain constant framerate
        auto sleepDuration = frameDelay - std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now() - frameStart);
        if (sleepDuration.count() > 0)
        {
            // Sleep for the calculated duration
            std::this_thread::sleep_for(sleepDuration);
        }

        // Calculate delta time
        auto currentFrameTime = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration<float, std::milli>(currentFrameTime - frameStart).count() / 1000.0f;

        // Cap delta time to 0.05 seconds
        if (deltaTime > 0.05f)
        {
            deltaTime = 0.05f;
        }

        // Update frame start time
        frameStart = currentFrameTime;

        return true;
    }

    /**
     * @brief Renders the window.
     * @param r The red component.
     * @param g The green component.
     * @param b The blue component.
     * @param a The alpha component.
     */
    void Window::Render(int r, int g, int b, int a)
    {
        // Check if renderer exists
        if (Renderer)
        {
            // Set render draw color and clear the renderer
            SDL_SetRenderDrawColor(Renderer, r, g, b, a);
            SDL_RenderClear(Renderer);
        }
    }

    /**
     * @brief Closes the window.
     */
    void Window::Close()
    {
        // Destroy renderer if it exists
        if (Renderer)
        {
            SDL_DestroyRenderer(Renderer);
            Renderer = nullptr;
        }

        // Destroy window if it exists
        if (window)
        {
            SDL_DestroyWindow(window);
            window = nullptr;
        }

        // Quit SDL
        SDL_Quit();
    }

    /**
     * @brief Checks if the window is open.
     * @return True if the window is open, false otherwise.
     */
    bool Window::IsOpen()
    {
        // Handle framerate and present the renderer
        HandleFramerate();
        SDL_RenderPresent(Renderer);

        // Return running flag
        return isRunning;
    }

    /**
     * @brief Destructor.
     */
    Window::~Window()
    {
        // Close the window
        Close();

        // Set window and Renderer to nullptr
        window = nullptr;
        Renderer = nullptr;
    }
} // namespace Sling