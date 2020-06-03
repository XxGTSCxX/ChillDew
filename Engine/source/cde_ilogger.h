/******************************************************************************/
/*!
  \project GTE
  \file    CD_ILogger.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Interface for all Logger classes.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cd_core.h" // CD_API, cd::string_view
#include "cde_log.h"

namespace chilldew::engine
{

    class CD_API ilogger
    {
    public:

        constexpr ilogger()  noexcept = default;
        virtual   ~ilogger() noexcept = default;

        virtual void enable();
        virtual void disable();
        virtual void filter_log(log::flag type) = 0;

        virtual void log        (cd::string_view const& text) = 0;
        virtual void log_warning(cd::string_view const& text) = 0;
        virtual void log_error  (cd::string_view const& text) = 0;
        virtual void log_assert (cd::string_view const& text) = 0;

        virtual bool is_enabled() const;

    protected:

        bool _is_enabled = true;
    };

}
