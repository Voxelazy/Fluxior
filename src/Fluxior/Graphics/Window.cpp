#include "Fluxior/Graphics/Window.hpp"

namespace flux
{
    /**
     * @brief Default constructor.
     */
    Window::Window() : window(nullptr, SDL_DestroyWindow), renderer(nullptr, SDL_DestroyRenderer)
    {
        // Initialize window and renderer to nullptr
    }

    /**
     * @brief Destructor.
     */
    Window::~Window()
    {
        // Close the window
        Close();
    }

    /**
     * @brief Constructor to create a window with specified parameters.
     * @param Title The title of the window.
     * @param WindowWidth The width of the window.
     * @param WindowHeight The height of the window.
     * @param WinMode The window mode.
     * @param RenMode The renderer mode.
     * @param FPS The frames per second.
     */
    Window::Window(const char *Title, uint WindowWidth, uint WindowHeight, WindowMode WinMode, RendererMode RenMode, const float FPS)
        : window(nullptr, SDL_DestroyWindow), renderer(nullptr, SDL_DestroyRenderer)
    {
        // Call Create method to create the window
        Create(Title, WindowWidth, WindowHeight, WinMode, RenMode, FPS);
    }

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
    bool Window::Create(const char *Title, uint WindowWidth, uint WindowHeight, WindowMode WinMode, RendererMode RenMode, const float FPS)
    {
        // Set frame delay based on FPS
        frameDelay = std::chrono::duration<float, std::milli>(1000.0f / FPS);

        // Initialize SDL
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            // Throw error if SDL initialization fails
            throw std::runtime_error("Fluxior could not Initialize: " + std::string(SDL_GetError()));
        }
        else
        {
            // Create SDL window
            window.reset(SDL_CreateWindow(Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, static_cast<uint>(WinMode)));
            if (!window)
            {
                // Quit SDL and throw error if window creation fails
                SDL_Quit();
                throw std::runtime_error("Fluxior failed to create Window: " + std::string(SDL_GetError()));
            }

            // Create SDL renderer
            renderer.reset(SDL_CreateRenderer(window.get(), -1, static_cast<uint>(RenMode)));
            if (!renderer)
            {
                // Destroy window, quit SDL and throw error if renderer creation fails
                SDL_Quit();
                throw std::runtime_error("Fluxior failed to create Renderer: " + std::string(SDL_GetError()));
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
     * @brief Sets the window's icon.
     * @param IconPath The file path of the icon image.
     */
    void Window::SetIcon(const std::string &IconPath)
    {
        if (!window)
        {
            throw std::runtime_error("Fluxior failed to set Window Icon: Window has not been created yet.");
        }

        SDL_Surface *iconSurface = IMG_Load(IconPath.c_str());
        if (!iconSurface)
        {
            throw std::runtime_error("Fluxior failed to load Window Icon: " + std::string(IMG_GetError()));
        }

        SDL_SetWindowIcon(window.get(), iconSurface);
        SDL_FreeSurface(iconSurface);
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
            throw std::runtime_error("Fluxior failed to set Render Scale Quality: " + std::string(SDL_GetError()));
        }
    }

    /**
     * @brief Sets the renderer size.
     * @param RendererWidth The width of the renderer.
     * @param RendererHeight The height of the renderer.
     */
    void Window::SetRendererSize(uint RendererWidth, uint RendererHeight)
    {   
        // Set renderer size.
        if (SDL_RenderSetLogicalSize(renderer.get(), RendererWidth, RendererHeight) != 0)
        {
            // Throw error if setting renderer size fails
            throw std::runtime_error("Fluxior failed to Set Renderer Size: " + std::string(SDL_GetError()));
        }
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
        if (renderer)
        {
            // Set render draw color and clear the renderer
            SDL_SetRenderDrawColor(renderer.get(), r, g, b, a);
            SDL_RenderClear(renderer.get());
        }
    }

    /**
     * @brief Updates the current event.
     *
     * This function polls for a Fluxior event and updates the "event" and "key" members of the Window class accordingly.
     * If a key down or key up event occurs, it sets "event" to "KeyDown" or "KeyUp" and sets key to the Fluxior "KeyCode" of the "key."
     * If a quit event occurs, it sets "event" to "Quit".
     * If no event occurs, it sets "event" to "None" and "key" to 0.
     */
    void Window::UpdateEvent()
    {
        SDL_Event sdlEvent;
        if (SDL_PollEvent(&sdlEvent))
        {
            switch (sdlEvent.type)
            {
            case SDL_QUIT:
                Event = EventType::Quit;
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                Event = EventType::KeyDown;
                Keycode = static_cast<KeyCode>(sdlEvent.key.keysym.sym);
                break;
            case SDL_KEYUP:
                Event = EventType::KeyUp;
                Keycode = static_cast<KeyCode>(sdlEvent.key.keysym.sym);
                break;
            default:
                Event = EventType::None;
                Keycode = static_cast<KeyCode>(0);
                break;
            }
        }
        else
        {
            Event = EventType::None;
            Keycode = static_cast<KeyCode>(0);
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

        // Poll events
        UpdateEvent();

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
     * @brief Checks if the window is open.
     * @return True if the window is open, false otherwise.
     */
    bool Window::IsOpen()
    {
        // Handle framerate and present the renderer
        HandleFramerate();
        SDL_RenderPresent(renderer.get());

        // Return running flag
        return isRunning;
    }

    /**
     * @brief Closes the window and stops all running instances.
     */
    void Window::Close()
    {
        isRunning = false;

        renderer.reset(); // Smart pointer will automatically destroy the renderer
        window.reset();   // Smart pointer will automatically destroy the window

        // Quit SDL & SDL2_image
        IMG_Quit();
        SDL_Quit();
    }
} // namespace flux