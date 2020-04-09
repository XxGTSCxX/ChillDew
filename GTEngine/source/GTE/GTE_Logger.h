/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Logger.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Logger for debug messages. Specifies where to stream the messages to.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Core.h"
#include "GTE_ILogger.h"
#include "GTE_LogHandler.h"
#include "GTE_Log.h"
#include <ostream> // std::ostream
#include <cstdint> // std::ostream

namespace GTE
{

	class GTE_API Logger : public ILogger
	{
	public:

		Logger()  = default;
		~Logger() = default;

		explicit Logger(GTE::string_view const& logger_name, GTE::string_view const& default_colour, GTE::string_view const& error_colour, GTE::string_view const& warning_colour, GTE::string_view const& assert_colour);

		void FilterLogType(Log::TypeFlag type) override;

		void Log       (GTE::string_view const& text) override;
		void LogWarning(GTE::string_view const& text) override;
		void LogError  (GTE::string_view const& text) override;
		void LogAssert (GTE::string_view const& text) override;

		template <typename ... Args> void Log       (GTE::string_view const& text, Args&& ... args);
		template <typename ... Args> void LogWarning(GTE::string_view const& text, Args&& ... args);
		template <typename ... Args> void LogError  (GTE::string_view const& text, Args&& ... args);
		template <typename ... Args> void LogAssert (GTE::string_view const& text, Args&& ... args);

		GTE::string const& GetName() const;

	private:

		GTE::string _name          { GTE_STRING("Default Logger") };
		GTE::string _default_format{ Log::Colour::DEFAULT         };
		GTE::string _warning_format{ Log::Colour::BRIGHT_YELLOW   };
		GTE::string _error_format  { Log::Colour::BRIGHT_MAGENTA  };
		GTE::string _assert_format { Log::Colour::BRIGHT_RED      };
		LogHandler  _log_handler;
	};

}
