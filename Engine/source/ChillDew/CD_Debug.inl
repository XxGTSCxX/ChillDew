/******************************************************************************/
/*!
  \project ChillDew-Engine
  \file    CD_Debug.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Mimics Unity's Debug class as best as we can within the constraints of C++.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Debug.h"
#include "CD_Logger.inl"

namespace CD
{

    template <typename ... Args>
    inline void Debug::Assert([[maybe_unused]] bool condition, [[maybe_unused]] std::string_view const& text, [[maybe_unused]] Args&& ... args)
    {
#ifdef CD_ENABLE_ASSERT
        CD::string err_message = CD::CStrToStr(Log::FormatText(text, std::forward<Args>(args)...));
        assert(condition);
#endif
    }

    template <typename ... Args>
    inline void Debug::Log(std::string_view const& text, Args&& ... args)
    {
        _logger.Log(CD::CStrToStr(text), std::forward<Args>(args)...);
    }

    template <typename ... Args>
    inline void Debug::LogError(std::string_view const& text, Args&& ... args)
    {
        _logger.LogError(CD::CStrToStr(text), std::forward<Args>(args)...);
    }

    template <typename ... Args>
    inline void Debug::LogWarning(std::string_view const& text, Args&& ... args)
    {
        _logger.LogWarning(CD::CStrToStr(text), std::forward<Args>(args)...);
    }

}
