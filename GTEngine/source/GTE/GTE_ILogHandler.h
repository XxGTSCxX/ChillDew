/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_ILogHandler.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Interface for all log handlers.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Core.h" // GTE::string_view, GTE::iostream

namespace GTE
{

    class GTE_API ILogHandler
    {
    public:

        virtual ~ILogHandler() = default;

        virtual void Log(GTE::string_view const& text) = 0;

        virtual GTE::iostream&       GetStream()       = 0;
        virtual GTE::iostream const& GetStream() const = 0;
    };

}
