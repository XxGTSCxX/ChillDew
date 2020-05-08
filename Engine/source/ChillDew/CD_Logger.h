/******************************************************************************/
/*!
  \project ChillDew-Engine
  \file    CD_Logger.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Logger for debug messages. Specifies where to stream the messages to.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Core.h"
#include "CD_ILogger.h"
#include "CD_LogHandler.h"
#include "CD_Log.h"
#include <ostream> // std::ostream
#include <cstdint> // std::ostream

namespace CD
{

	class CD_API Logger : public ILogger
	{
	public:

		Logger()  = default;
		~Logger() = default;

		explicit Logger(CD::string_view const& logger_name, CD::string_view const& default_colour, CD::string_view const& error_colour, CD::string_view const& warning_colour, CD::string_view const& assert_colour);

		void FilterLogType(Log::TypeFlag type) override;

		void Log       (CD::string_view const& text) override;
		void LogWarning(CD::string_view const& text) override;
		void LogError  (CD::string_view const& text) override;
		void LogAssert (CD::string_view const& text) override;

		template <typename ... Args> void Log       (CD::string_view const& text, Args&& ... args);
		template <typename ... Args> void LogWarning(CD::string_view const& text, Args&& ... args);
		template <typename ... Args> void LogError  (CD::string_view const& text, Args&& ... args);
		template <typename ... Args> void LogAssert (CD::string_view const& text, Args&& ... args);

		CD::string const& GetName() const;

	private:

		CD::string _name          { CD_STRING("Default Logger") };
		CD::string _default_format{ Log::Colour::DEFAULT         };
		CD::string _warning_format{ Log::Colour::BRIGHT_YELLOW   };
		CD::string _error_format  { Log::Colour::BRIGHT_MAGENTA  };
		CD::string _assert_format { Log::Colour::BRIGHT_RED      };
		LogHandler  _log_handler;
	};

}
