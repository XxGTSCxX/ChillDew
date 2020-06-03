/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    CD_ILogHandler.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Interface for all log handlers.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cd_core.h" // cd::string_view, cd::iostream

namespace chilldew
{

    class CD_API ILogHandler
    {
    public:

        virtual ~ILogHandler() = default;

        virtual void Log(cd::string_view const& text) = 0;

        virtual cd::iostream&       GetStream()       = 0;
        virtual cd::iostream const& GetStream() const = 0;
    };

}
