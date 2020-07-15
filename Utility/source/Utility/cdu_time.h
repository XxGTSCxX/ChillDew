#pragma once

#include "cdu_core.h"
#include "cdu_singleton.inl"
#include "cdu_flag.inl"
#include <chrono> // std::chrono

namespace chilldew::utility
{

    struct time : public cdu::singleton<time>
    {
        using duration = std::chrono::duration<double, std::ratio<1, 1>>;

        using clock = std::chrono::system_clock;                                // Computer's clock
        using timer = std::chrono::steady_clock;                                // Stopwatch

        using clock_time = std::chrono::time_point<clock>;                      // Time on the computer's clock
        using timer_time = std::chrono::time_point<timer>;                      // Time on the stopwatch
        using local_time = tm;

        enum class format : std::uint8_t
        {
              year    = 0b000001
            , month   = 0b000010
            , day     = 0b000100
            , hour    = 0b001000
            , minutes = 0b010000
            , seconds = 0b100000

            , all = year | month | day | hour | minutes | seconds
        };

        using format_flag = cdu::flag<format>;

        static constexpr format_flag date_format{ format::year, format::month  , format::day     };
        static constexpr format_flag time_format{ format::hour, format::minutes, format::seconds };

        static local_time now()                                                noexcept;
        static cd::string format_date(local_time time, format_flag formatting) noexcept;
        static cd::string format_time(local_time time, format_flag formatting) noexcept;


        duration delta_time()          const;
        duration unscaled_delta_time() const;
    };

}
