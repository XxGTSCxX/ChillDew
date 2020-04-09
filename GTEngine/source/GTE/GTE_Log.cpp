/******************************************************************************/
/*!
  \project GTE
  \file    GTE_Log.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Defines most of the commonly used data by all log features.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "GTE_pch.h"
#include "GTE_Log.h"

namespace GTE
{

    GTE::string Log::Format::FormatText(GTE::string_view const& text)
    {
        return GTE::string{ text };
    }

}
