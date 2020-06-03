/******************************************************************************/
/*!
  \project GTE
  \file    CD_Log.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Defines most of the commonly used data by all log features.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "cd_pch.h"
#include "cde_log.h"

namespace chilldew::engine
{

    cd::string log::format::format_text(cd::string_view const& text)
    {
        return cd::string{ text };
    }

}
