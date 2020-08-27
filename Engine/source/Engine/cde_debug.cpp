/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    cde_debug.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Mimics Unity's Debug class as best as we can within the constraints of C++.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "cd_pch.h"
#include "cde_debug.h"

namespace chilldew::engine
{

    namespace detail
    {
        inline cd::string get_session_id() noexcept
        {
            cd::stringstream      s_stream;
            cdu::time::local_time curr_time = cdu::time::now();

            s_stream << '[' << (curr_time.tm_year + 1900);
            if (curr_time.tm_mon < 9) s_stream << 0;
            s_stream << (curr_time.tm_mon + 1);
            if (curr_time.tm_mday < 10) s_stream << 0;
            s_stream << curr_time.tm_mday << '-';
            if (curr_time.tm_hour < 10) s_stream << 0;
            s_stream << curr_time.tm_hour;
            if (curr_time.tm_min < 10) s_stream << 0;
            s_stream << curr_time.tm_min;
            if ((curr_time.tm_sec % 60) < 10) s_stream << 0;
            s_stream << (curr_time.tm_sec % 60) << ']';

            return s_stream.str();
        }
    }

    debug::debug()
    : _logger{ detail::get_session_id() + CD_L(" Debug Logger") }
    {
        if (is_debug_build())
        {
            enable_developer_console();
        }
    }

    debug::~debug()
    {
        if (is_developer_console_visible())
        {
            disable_developer_console();
        }
    }

    bool debug::is_debug_build() const noexcept
    {
#ifdef _DEBUG
        return true;
#else
        return false;
#endif
    }

    bool debug::is_developer_console_visible() const noexcept
    {
        return _developer_console_is_visible;
    }

    // References used:
    // - https://github.com/agauniyal/rang/blob/master/include/rang.hpp
    // - https://gist.github.com/kingseva/a918ec66079a9475f19642ec31276a21
    void debug::enable_developer_console()
    {
        if (!_developer_console_is_visible)
        {
            FILE* cin_buffer  = nullptr;
            FILE* cerr_buffer = nullptr;
            FILE* cout_buffer = nullptr;
            DWORD flags;

            ::AllocConsole();
            ::SetConsoleTitle(_logger.get_name().data());

            // Redirect the CRT standard input, output, and error handles to the console
            freopen_s(&cin_buffer , "CONIN$" , "r", stdin );
            freopen_s(&cerr_buffer, "CONOUT$", "w", stderr);
            freopen_s(&cout_buffer, "CONOUT$", "w", stdout);

            // Note that there is no CONERR$ file
            HANDLE hStdout = CreateFile(CD_L("CONOUT$"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            HANDLE hStdin  = CreateFile(CD_L("CONIN$" ), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

            SetStdHandle(STD_OUTPUT_HANDLE, hStdout);
            SetStdHandle(STD_ERROR_HANDLE , hStdout);
            SetStdHandle(STD_INPUT_HANDLE , hStdin );

            ::GetConsoleMode(hStdin, &flags);
            ::SetConsoleMode(hStdin, flags | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

            ::GetConsoleMode(hStdout, &flags);
            ::SetConsoleMode(hStdout, flags | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

            //Clear the error state for each of the C++ standard stream objects. 
            std::wclog.clear();
            std::clog .clear();
            std::wcout.clear();
            std::cout .clear();
            std::wcerr.clear();
            std::cerr .clear();
            std::wcin .clear();
            std::cin  .clear();

            _developer_console_is_visible = true;
        }
    }

    void debug::disable_developer_console()
    {
        // TODO: Implement saving current log to a file.
        if (_developer_console_is_visible)
        {
            ::FreeConsole();
            _developer_console_is_visible = false;
        }
    }

    ilogger& debug::get_logger()
    {
        return _logger;
    }

    ilogger const& debug::get_logger() const
    {
        return _logger;
    }

    void debug::breakpoint() const
    {
        __debugbreak();
    }

    void debug::clear_developer_console()
    {
        // TODO: clear log contents
    }

}
