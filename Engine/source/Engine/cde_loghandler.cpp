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

    loghandler::loghandler(cd::string const& name, cdu::filesystem::path const& directory)
    : iloghandler{ name                                                                                                         }
    , m_log      { cd::cout.rdbuf()                                                                                             }
    , m_file     { cdu::filesystem::get()->create_file(directory / (name + CD_L(".log")), cdu::filesystem::file::access::write) }
    {}

    void loghandler::log(cd::string_view const& text)
    {
        m_log  << text;
        m_file << text;
    }

    cd::iostream& loghandler::get_stream()
    {
        return m_log;
    }

    cd::iostream const& loghandler::get_stream() const
    {
        return m_log;
    }

}
