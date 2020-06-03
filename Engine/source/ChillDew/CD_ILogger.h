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

#include "cd_core.h" // CD_API, cd::string_view
#include "CD_Log.h"

namespace chilldew
{

    class CD_API ILogger
    {
    public:

        constexpr ILogger()  noexcept = default;
        virtual   ~ILogger() noexcept = default;

        virtual void Enable();
        virtual void Disable();
        virtual void FilterLogType(Log::TypeFlag type) = 0;

        virtual void Log       (cd::string_view const& text) = 0;
        virtual void LogWarning(cd::string_view const& text) = 0;
        virtual void LogError  (cd::string_view const& text) = 0;
        virtual void LogAssert (cd::string_view const& text) = 0;

        virtual bool IsEnabled() const;

    protected:

        bool _is_enabled = true;
    };

}
