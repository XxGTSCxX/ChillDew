/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    CD_LogHandler.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Handles where the log gets output to. Acts as the sink in spdlog.

    All content (C) 2019 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Core.h"
#include "CD_ILogHandler.h"
#include <iostream> // std::iostream

namespace chilldew
{

    class CD_API LogHandler : public ILogHandler
    {
    public:

        LogHandler();

        void Log(CD::string_view const& text) override;

        CD::iostream&       GetStream()       override;
        CD::iostream const& GetStream() const override;

    private:

        CD::iostream _log;
    };

}
