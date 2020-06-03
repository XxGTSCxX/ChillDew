/******************************************************************************/
/*!
  \project Chilldew-Math
  \file    cdm_functionals.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Math functions.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cdm_functionals.h"
#include <algorithm> // std::max, std::min

namespace chilldew::math
{

    template <typename type>
    constexpr bool fuzzy_equal(type const& lhs, type const& rhs, type const& epsilon) noexcept
    {
        return std::max<type>(lhs - rhs, rhs - lhs) < epsilon;
    }

    template <typename type>
    constexpr type clamp(type const& value, type const& lower_bound, type const& upper_bound) noexcept
    {
        return std::max<type>(lower_bound, std::min<type>(value, upper_bound));
    }

}
