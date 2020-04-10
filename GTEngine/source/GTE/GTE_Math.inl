/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Math.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Math stuff.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Math.h"
#include <algorithm> // std::max, std::min

namespace GTE
{

    template <typename T>
    inline T Clamp(T const& value, T const& lower_bound, T const& upper_bound)
    {
        return std::max(lower_bound, std::min(value, upper_bound));
    }

}
