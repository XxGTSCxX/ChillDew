/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    CD_LogHandler.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Handles where the log gets output to. Acts as the sink in spdlog.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "cd_pch.h"
#include "CD_LogHandler.h"
#include <iostream>

namespace chilldew
{

    LogHandler::LogHandler()
    : _log{ cd::cout.rdbuf() }
    {}

    void LogHandler::Log(cd::string_view const& text)
    {
        _log << text;
    }

    cd::iostream& LogHandler::GetStream()
    {
        return _log;
    }

    cd::iostream const& LogHandler::GetStream() const
    {
        return _log;
    }

}
