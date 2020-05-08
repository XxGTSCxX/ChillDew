/******************************************************************************/
/*!
  \project ChillDew-Engine
  \file    CD_Debug.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Mimics Unity's Debug class as best as we can within the constraints of C++.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "CD_pch.h"
#include "CD_Debug.h"

namespace CD
{

    Debug::Debug()
    {
        if (IsDebugBuild())
        {
            EnableDeveloperConsole();
        }
    }

    Debug::~Debug()
    {
        if (IsDeveloperConsoleVisible())
        {
            DisableDeveloperConsole();
        }
    }

    bool Debug::IsDebugBuild() const noexcept
    {
#ifdef _DEBUG
        return true;
#else
        return false;
#endif
    }

    bool Debug::IsDeveloperConsoleVisible() const noexcept
    {
        return _developer_console_is_visible;
    }

    // References used:
    // - https://github.com/agauniyal/rang/blob/master/include/rang.hpp
    // - https://gist.github.com/kingseva/a918ec66079a9475f19642ec31276a21
    void Debug::EnableDeveloperConsole()
    {
        if (!_developer_console_is_visible)
        {
            FILE* cin_buffer  = nullptr;
            FILE* cerr_buffer = nullptr;
            FILE* cout_buffer = nullptr;
            DWORD flags;

            ::AllocConsole();
            ::SetConsoleTitle(_logger.GetName().data());

            // Redirect the CRT standard input, output, and error handles to the console
            freopen_s(&cin_buffer , "CONIN$" , "r", stdin );
            freopen_s(&cerr_buffer, "CONOUT$", "w", stderr);
            freopen_s(&cout_buffer, "CONOUT$", "w", stdout);

            // Note that there is no CONERR$ file
            HANDLE hStdout = CreateFile(CD_STRING("CONOUT$"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            HANDLE hStdin  = CreateFile(CD_STRING("CONIN$" ), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

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

    void Debug::DisableDeveloperConsole()
    {
        // TODO: Implement saving current log to a file and closing of the
        //       console window.
        if (_developer_console_is_visible)
        {
            ::FreeConsole();
            _developer_console_is_visible = false;
        }
    }

    ILogger& Debug::GetLogger()
    {
        return _logger;
    }

    ILogger const& Debug::GetLogger() const
    {
        return _logger;
    }

    void Debug::Break() const
    {
        __debugbreak();
    }

    void Debug::ClearDeveloperConsole()
    {
        // TODO: clear log contents
    }

}
