/******************************************************************************/
/*!
  \project ChillDew-Engine
  \file    CD_LogHandler.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Handles where the log gets output to. Acts as the sink in spdlog.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "CD_pch.h"
#include "CD_LogHandler.h"
#include <iostream>

namespace CD
{

    LogHandler::LogHandler()
    : _log{ CD::cout.rdbuf() }
    {}

    void LogHandler::Log(CD::string_view const& text)
    {
        _log << text;
    }

    CD::iostream& LogHandler::GetStream()
    {
        return _log;
    }

    CD::iostream const& LogHandler::GetStream() const
    {
        return _log;
    }

}
