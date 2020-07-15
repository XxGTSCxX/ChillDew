/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    cde_logger.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Logger for debug messages. Specifies where to stream the messages to.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "cd_pch.h"
#include "cde_logger.inl"
#include "cde_log.inl"

namespace chilldew::engine
{

    logger::logger( cd::string_view const& logger_name
                  , cd::string_view const& default_colour
                  , cd::string_view const& warning_colour
                  , cd::string_view const& error_colour
                  , cd::string_view const& assert_colour)
    : _default_format{ default_colour     }
    , _warning_format{ warning_colour     }
    , _error_format  { error_colour       }
    , _assert_format { assert_colour      }
    , _log_handler   { logger_name.data() }
    {}

    void logger::filter_log([[maybe_unused]] log::flag type)
    {}

    void logger::log(cd::string_view const& text)
    {
        if (_is_enabled)
        {
            cd::stringstream stream;
            stream << _default_format    << text;
            stream << log::colour::reset << std::endl;
            _log_handler.log(stream.str());
        }
    }

    void logger::log_warning(cd::string_view const& text)
    {
        if (_is_enabled)
        {
            cd::stringstream stream;
            stream << _warning_format    << text;
            stream << log::colour::reset << std::endl;
            _log_handler.log(stream.str());
        }
    }

    void logger::log_error(cd::string_view const& text)
    {
        if (_is_enabled)
        {
            cd::stringstream stream;
            stream << _error_format      << text;
            stream << log::colour::reset << std::endl;
            _log_handler.log(stream.str());
        }
    }

    void logger::log_assert(cd::string_view const& text)
    {
        if (_is_enabled)
        {
            cd::stringstream stream;
            stream << _assert_format     << text;
            stream << log::colour::reset << std::endl;
            _log_handler.log(stream.str());
        }
    }

    iloghandler const& logger::get_handler() const
    {
        return _log_handler;
    }

    iloghandler& logger::get_handler()
    {
        return _log_handler;
    }

    cd::string const& logger::get_name() const
    {
        return _log_handler.get_name();
    }

    void logger::set_name(cd::string_view const& name)
    {
        return _log_handler.set_name(name);
    }

}
