/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_LogHandler.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Handles where the log gets output to. Acts as the sink in spdlog.

    All content (C) 2019 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Core.h"
#include "GTE_ILogHandler.h"
#include <iostream> // std::iostream

namespace GTE
{

    class GTE_API LogHandler : public ILogHandler
    {
    public:

        LogHandler();

        void Log(GTE::string_view const& text) override;

        GTE::iostream&       GetStream()       override;
        GTE::iostream const& GetStream() const override;

    private:

        GTE::iostream _log;
    };

}
