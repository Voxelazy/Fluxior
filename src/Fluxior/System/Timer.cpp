#include "Fluxior/System/Timer.hpp"

namespace flux
{
    Timer::Timer()
    {
        PausedTicks = std::chrono::milliseconds(0);

        Paused = false;
        Started = false;
    }

    void Timer::Start()
    {
        if (!Started)
        {
            Started = true;
            Paused = false;

            StartTicks = std::chrono::steady_clock::now();
            PausedTicks = std::chrono::milliseconds(0);
        }
    }

    void Timer::Stop()
    {
        if (Started)
        {
            Started = false;
            Paused = false;

            StartTicks = std::chrono::steady_clock::time_point();
            PausedTicks = std::chrono::milliseconds(0);
        }
    }

    void Timer::Pause()
    {
        if (Started && !Paused)
        {
            Paused = true;
            PausedTicks = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - StartTicks);
            StartTicks = std::chrono::steady_clock::time_point();
        }
    }

    void Timer::Unpause()
    {
        if (Started && Paused)
        {
            Paused = false;
            StartTicks = std::chrono::steady_clock::now() - PausedTicks;
            PausedTicks = std::chrono::milliseconds(0);
        }
    }

    std::optional<std::chrono::milliseconds> Timer::GetTicks()
    {
        if (Started)
        {
            if (Paused)
            {
                return PausedTicks;
            }
            else
            {
                return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - StartTicks);
            }
        }

        return std::nullopt;
    }

    bool Timer::IsStarted()
    {
        return Started;
    }

    bool Timer::IsPaused()
    {
        return Paused && Started;
    }

    Timer::~Timer() {}
}