/******************************************************************************/
/*!
  \project GTE
  \file    GTE_ILogger.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Interface for all Logger classes.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Core.h" // GTE_API, GTE::string_view
#include "GTE_Log.h"

namespace GTE
{

    class GTE_API ILogger
    {
    public:

        constexpr ILogger()  noexcept = default;
        virtual   ~ILogger() noexcept = default;

        virtual void Enable();
        virtual void Disable();
        virtual void FilterLogType(Log::TypeFlag type) = 0;

        virtual void Log       (GTE::string_view const& text) = 0;
        virtual void LogWarning(GTE::string_view const& text) = 0;
        virtual void LogError  (GTE::string_view const& text) = 0;
        virtual void LogAssert (GTE::string_view const& text) = 0;

        virtual bool IsEnabled() const;

    protected:

        bool _is_enabled = true;
    };

}
