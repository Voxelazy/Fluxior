#pragma once

#include <chrono>
#include <optional>

namespace flux
{
    class Timer
    {
    public:
        // The Timer class's Constructor, initializes the variables.
        Timer();
        virtual ~Timer();

        // The various clock actions.
        void Start();
        void Stop();
        void Pause();
        void Unpause();

        // Gets the timer's time.
        std::optional<std::chrono::milliseconds> GetTicks();

        // Checks the status of the timer.
        bool IsStarted(), IsPaused();

    private:
        // The clock time when the timer started.
        std::chrono::steady_clock::time_point StartTicks;

        // The ticks stored when the timer was paused.
        std::chrono::milliseconds PausedTicks;

        // The timer status.
        bool Paused, Started;
    };
}