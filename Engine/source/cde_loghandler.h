/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    cde_loghandler.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Handles where the log gets output to. Acts as the sink in spdlog.

    all content (C) 2019 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cd_core.h"
#include "cde_iloghandler.h"
#include <iostream> // std::iostream

namespace chilldew::engine
{

    struct CD_API loghandler : public iloghandler
    {
        loghandler();

        void log(cd::string_view const& text) override;

        cd::iostream&       get_stream()       override;
        cd::iostream const& get_stream() const override;

    private:

        cd::iostream _log;
    };

}
