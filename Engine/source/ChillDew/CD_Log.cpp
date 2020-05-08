/******************************************************************************/
/*!
  \project GTE
  \file    CD_Log.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Defines most of the commonly used data by all log features.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "CD_pch.h"
#include "CD_Log.h"

namespace CD
{

    CD::string Log::Format::FormatText(CD::string_view const& text)
    {
        return CD::string{ text };
    }

}
