/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Debug.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Mimics Unity's Debug class as best as we can within the constraints of C++.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Core.h"
#include "GTE_Singleton.inl"
#include "GTE_ILogger.h"
#include "GTE_Logger.h"

namespace GTE
{

    class GTE_API Debug final : public Singleton<Debug>
    {
    public:

        Debug();
        ~Debug();

        bool IsDebugBuild()              const noexcept;
        bool IsDeveloperConsoleVisible() const noexcept;

        void EnableDeveloperConsole();
        void DisableDeveloperConsole();

        ILogger&       GetLogger();
        ILogger const& GetLogger() const;

        void Break() const;           // Does a breakpoint at the line this is called
        void ClearDeveloperConsole(); // Clears errors from the developer console.

        template <typename ... Args> void Assert    (bool condition, std::string_view const& text = "", Args&& ... args); // Assert a condition and logs an error message to the GTE console on failure.
        template <typename ... Args> void Log       (                std::string_view const& text     , Args&& ... args);
        template <typename ... Args> void LogError  (                std::string_view const& text     , Args&& ... args);
        template <typename ... Args> void LogWarning(                std::string_view const& text     , Args&& ... args);

    private:

        Logger _logger;
        bool   _developer_console_is_visible = false; // only opened on any log calls
    };

}
