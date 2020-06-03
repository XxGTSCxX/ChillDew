/******************************************************************************/
/*!
  \project Chilldew-Engine
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

#include "cd_core.h"
#include "CD_ILogger.h"
#include "CD_LogHandler.h"
#include "CD_Log.h"
#include <ostream> // std::ostream
#include <cstdint> // std::ostream

namespace chilldew
{

	class CD_API Logger : public ILogger
	{
	public:

		Logger()  = default;
		~Logger() = default;

		explicit Logger(cd::string_view const& logger_name, cd::string_view const& default_colour, cd::string_view const& error_colour, cd::string_view const& warning_colour, cd::string_view const& assert_colour);

		void FilterLogType(Log::TypeFlag type) override;

		void Log       (cd::string_view const& text) override;
		void LogWarning(cd::string_view const& text) override;
		void LogError  (cd::string_view const& text) override;
		void LogAssert (cd::string_view const& text) override;

		template <typename ... Args> void Log       (cd::string_view const& text, Args&& ... args);
		template <typename ... Args> void LogWarning(cd::string_view const& text, Args&& ... args);
		template <typename ... Args> void LogError  (cd::string_view const& text, Args&& ... args);
		template <typename ... Args> void LogAssert (cd::string_view const& text, Args&& ... args);

		cd::string const& GetName() const;

	private:

		cd::string _name          { CD_STRING("Default Logger") };
		cd::string _default_format{ Log::Colour::DEFAULT         };
		cd::string _warning_format{ Log::Colour::BRIGHT_YELLOW   };
		cd::string _error_format  { Log::Colour::BRIGHT_MAGENTA  };
		cd::string _assert_format { Log::Colour::BRIGHT_RED      };
		LogHandler  _log_handler;
	};

}
