#include "cdu_time.h"
#include <datetimeapi.h>

namespace chilldew::utility
{

    time::local_time time::now() noexcept
    {
        time_t     raw_time = clock::to_time_t(clock::now());
        local_time result;
        ::localtime_s(&result, &raw_time);
        return result;
    }

    cd::string time::format_date(local_time time, format_flag formatting) noexcept
    {
        cd::stringstream s_stream;
        bool             preceeding = false;

        if (formatting.is_on(format::year))
        {
            s_stream << (time.tm_year + 1900);
            preceeding = true;
        }

        if (formatting.is_on(format::month))
        {
            if (preceeding     ) s_stream << '/';
            if (time.tm_mon < 9) s_stream << 0;
            s_stream << (time.tm_mon + 1);
            preceeding = true;
        }

        if (formatting.is_on(format::day))
        {
            if (preceeding       ) s_stream << '/';
            if (time.tm_mday < 10) s_stream << 0;
            s_stream << time.tm_mday;
            preceeding = true;
        }

        return s_stream.str();
    }

    cd::string time::format_time(local_time time, format_flag formatting) noexcept
    {
        cd::stringstream s_stream;
        bool             preceeding = false;

        if (formatting.is_on(format::hour))
        {
            if (time.tm_hour < 10) s_stream << 0;
            s_stream << time.tm_hour;
            preceeding = true;
        }

        if (formatting.is_on(format::minutes))
        {
            if (preceeding      ) s_stream << ':';
            if (time.tm_min < 10) s_stream << 0;
            s_stream << time.tm_min;
            preceeding = true;
        }

        if (formatting.is_on(format::seconds))
        {
            if (preceeding             ) s_stream << ':';
            if ((time.tm_sec % 60) < 10) s_stream << 0;
            s_stream << (time.tm_sec % 60);
        }

        return s_stream.str();
    }

}
