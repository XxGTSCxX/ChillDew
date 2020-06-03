/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    cde_iloghandler.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Interface for all log handlers.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cd_core.h" // cd::string_view, cd::iostream

namespace chilldew::engine
{

    struct CD_API iloghandler
    {
        virtual ~iloghandler() = default;

        virtual void log(cd::string_view const& text) = 0;

        virtual cd::iostream&       get_stream()       = 0;
        virtual cd::iostream const& get_stream() const = 0;
    };

}
