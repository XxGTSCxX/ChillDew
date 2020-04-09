/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Logger.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Logger for debug messages. Specifies where to stream the messages to.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Logger.h"
#include "GTE_Log.inl"
#include <type_traits> // std::forward<>

namespace GTE
{

    template <typename ... Args>
    inline void Logger::Log(GTE::string_view const& text, Args&& ... args)
    {
        Log(Log::Format::FormatText(text, std::forward<Args>(args)...));
    }

    template <typename ... Args>
    inline void Logger::LogError(GTE::string_view const& text, Args&& ... args)
    {
        LogError(Log::Format::FormatText(text, std::forward<Args>(args)...));
    }

    template <typename ... Args>
    inline void Logger::LogWarning(GTE::string_view const& text, Args&& ... args)
    {
        LogWarning(Log::Format::FormatText(text, std::forward<Args>(args)...));
    }

    template <typename ... Args>
    inline void Logger::LogAssert(GTE::string_view const& text, Args&& ... args)
    {
        LogAssert(Log::Format::FormatText(text, std::forward<Args>(args)...));
    }

}
