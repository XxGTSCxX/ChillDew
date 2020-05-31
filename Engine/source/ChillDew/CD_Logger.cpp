/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    CD_Logger.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Logger for debug messages. Specifies where to stream the messages to.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "CD_pch.h"
#include "CD_Logger.inl"
#include "CD_Log.inl"

namespace chilldew
{

    Logger::Logger( CD::string_view const& logger_name
                  , CD::string_view const& default_colour
                  , CD::string_view const& error_colour
                  , CD::string_view const& warning_colour
                  , CD::string_view const& assert_colour)
    : _name          { logger_name    }
    , _default_format{ default_colour }
    , _error_format  { error_colour   }
    , _warning_format{ warning_colour }
    , _assert_format { assert_colour  }
    {}

    void Logger::FilterLogType([[maybe_unused]] Log::TypeFlag type)
    {}

    void Logger::Log(CD::string_view const& text)
    {
        if (_is_enabled)
        {
            CD::stringstream stream;
            stream << _default_format      << text;
            stream << Log::Colour::DEFAULT << std::endl;
            _log_handler.Log(stream.str());
        }
    }

    void Logger::LogWarning(CD::string_view const& text)
    {
        if (_is_enabled)
        {
            CD::stringstream stream;
            stream << _warning_format      << text;
            stream << Log::Colour::DEFAULT << std::endl;
            _log_handler.Log(stream.str());
        }
    }

    void Logger::LogError(CD::string_view const& text)
    {
        if (_is_enabled)
        {
            CD::stringstream stream;
            stream << _error_format        << text;
            stream << Log::Colour::DEFAULT << std::endl;
            _log_handler.Log(stream.str());
        }
    }

    void Logger::LogAssert(CD::string_view const& text)
    {
        if (_is_enabled)
        {
            CD::stringstream stream;
            stream << _assert_format       << text;
            stream << Log::Colour::DEFAULT << std::endl;
            _log_handler.Log(stream.str());
        }
    }

    CD::string const& Logger::GetName() const
    {
        return _name;
    }

}
