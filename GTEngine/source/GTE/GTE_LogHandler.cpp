/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_LogHandler.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Handles where the log gets output to. Acts as the sink in spdlog.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "GTE_pch.h"
#include "GTE_LogHandler.h"
#include <iostream>

namespace GTE
{

    LogHandler::LogHandler()
    : _log{ GTE::cout.rdbuf() }
    {}

    void LogHandler::Log(GTE::string_view const& text)
    {
        _log << text;
    }

    GTE::iostream& LogHandler::GetStream()
    {
        return _log;
    }

    GTE::iostream const& LogHandler::GetStream() const
    {
        return _log;
    }

}
