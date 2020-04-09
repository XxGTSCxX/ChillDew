/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Logger.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Logger for debug messages. Specifies where to stream the messages to.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "GTE_pch.h"
#include "GTE_Logger.inl"
#include "GTE_Log.inl"

namespace GTE
{

    Logger::Logger( GTE::string_view const& logger_name
                  , GTE::string_view const& default_colour
                  , GTE::string_view const& error_colour
                  , GTE::string_view const& warning_colour
                  , GTE::string_view const& assert_colour)
    : _name          { logger_name    }
    , _default_format{ default_colour }
    , _error_format  { error_colour   }
    , _warning_format{ warning_colour }
    , _assert_format { assert_colour  }
    {}

    void Logger::FilterLogType([[maybe_unused]] Log::TypeFlag type)
    {}

    void Logger::Log(GTE::string_view const& text)
    {
        if (_is_enabled)
        {
            GTE::stringstream stream;
            stream << _default_format      << text;
            stream << Log::Colour::DEFAULT << std::endl;
            _log_handler.Log(stream.str());
        }
    }

    void Logger::LogWarning(GTE::string_view const& text)
    {
        if (_is_enabled)
        {
            GTE::stringstream stream;
            stream << _warning_format      << text;
            stream << Log::Colour::DEFAULT << std::endl;
            _log_handler.Log(stream.str());
        }
    }

    void Logger::LogError(GTE::string_view const& text)
    {
        if (_is_enabled)
        {
            GTE::stringstream stream;
            stream << _error_format        << text;
            stream << Log::Colour::DEFAULT << std::endl;
            _log_handler.Log(stream.str());
        }
    }

    void Logger::LogAssert(GTE::string_view const& text)
    {
        if (_is_enabled)
        {
            GTE::stringstream stream;
            stream << _assert_format       << text;
            stream << Log::Colour::DEFAULT << std::endl;
            _log_handler.Log(stream.str());
        }
    }

    GTE::string const& Logger::GetName() const
    {
        return _name;
    }

}
