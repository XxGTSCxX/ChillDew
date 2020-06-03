/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    cde_logger.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Logger for debug messages. Specifies where to stream the messages to.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cde_core.h"
#include "cde_log.h"
#include "cde_ilogger.h"
#include "cde_loghandler.h"
#include <ostream> // std::ostream

namespace chilldew::engine
{

    class CD_API logger : public ilogger
    {
    public:

        explicit logger( cd::string_view const& logger_name    = CD_STRING("Default Logger")
                       , cd::string_view const& default_colour = log::colour::reset
                       , cd::string_view const& warning_colour = log::colour::bright_yellow
                       , cd::string_view const& error_colour   = log::colour::bright_magenta
                       , cd::string_view const& assert_colour  = log::colour::bright_red    );

        void filter_log(log::flag type) override;

        void log        (cd::string_view const& text) override;
        void log_warning(cd::string_view const& text) override;
        void log_error  (cd::string_view const& text) override;
        void log_assert (cd::string_view const& text) override;

        template <typename ... Args> void log        (cd::string_view const& text, Args&& ... args);
        template <typename ... Args> void log_warning(cd::string_view const& text, Args&& ... args);
        template <typename ... Args> void log_error  (cd::string_view const& text, Args&& ... args);
        template <typename ... Args> void log_assert (cd::string_view const& text, Args&& ... args);

        cd::string const& get_name() const;

    private:

        cd::string _name;
        cd::string _default_format;
        cd::string _warning_format;
        cd::string _error_format;
        cd::string _assert_format;
        loghandler _log_handler;
    };

}
