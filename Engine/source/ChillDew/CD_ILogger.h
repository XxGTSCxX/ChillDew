/******************************************************************************/
/*!
  \project GTE
  \file    CD_ILogger.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Interface for all Logger classes.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Core.h" // CD_API, CD::string_view
#include "CD_Log.h"

namespace CD
{

    class CD_API ILogger
    {
    public:

        constexpr ILogger()  noexcept = default;
        virtual   ~ILogger() noexcept = default;

        virtual void Enable();
        virtual void Disable();
        virtual void FilterLogType(Log::TypeFlag type) = 0;

        virtual void Log       (CD::string_view const& text) = 0;
        virtual void LogWarning(CD::string_view const& text) = 0;
        virtual void LogError  (CD::string_view const& text) = 0;
        virtual void LogAssert (CD::string_view const& text) = 0;

        virtual bool IsEnabled() const;

    protected:

        bool _is_enabled = true;
    };

}
