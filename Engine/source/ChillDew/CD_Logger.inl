/******************************************************************************/
/*!
  \project ChillDew-Engine
  \file    CD_Logger.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Logger for debug messages. Specifies where to stream the messages to.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Logger.h"
#include "CD_Log.inl"
#include <type_traits> // std::forward<>

namespace CD
{

    template <typename ... Args>
    inline void Logger::Log(CD::string_view const& text, Args&& ... args)
    {
        Log(Log::Format::FormatText(text, std::forward<Args>(args)...));
    }

    template <typename ... Args>
    inline void Logger::LogError(CD::string_view const& text, Args&& ... args)
    {
        LogError(Log::Format::FormatText(text, std::forward<Args>(args)...));
    }

    template <typename ... Args>
    inline void Logger::LogWarning(CD::string_view const& text, Args&& ... args)
    {
        LogWarning(Log::Format::FormatText(text, std::forward<Args>(args)...));
    }

    template <typename ... Args>
    inline void Logger::LogAssert(CD::string_view const& text, Args&& ... args)
    {
        LogAssert(Log::Format::FormatText(text, std::forward<Args>(args)...));
    }

}
