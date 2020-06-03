/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    cde_loghandler.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Handles where the log gets output to. Acts as the sink in spdlog.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "cd_pch.h"
#include "cde_loghandler.h"
#include <iostream>

namespace chilldew::engine
{

    loghandler::loghandler()
    : _log{ cd::cout.rdbuf() }
    {}

    void loghandler::log(cd::string_view const& text)
    {
        _log << text;
    }

    cd::iostream& loghandler::get_stream()
    {
        return _log;
    }

    cd::iostream const& loghandler::get_stream() const
    {
        return _log;
    }

}
