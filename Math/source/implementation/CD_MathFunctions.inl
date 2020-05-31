#pragma once

#include "CD_MathFunctions.h"
#include <algorithm> // std::max, std::min

namespace chilldew
{

    template<typename type>
    constexpr bool fuzzy_equal(type const& lhs, type const& rhs, type const& epsilon) noexcept
    {
        return std::max<type>(lhs - rhs, rhs - lhs) < epsilon;
    }

    template<typename type>
    constexpr type clamp(type const& value, type const& lower_bound, type const& upper_bound) noexcept
    {
        return std::max<type>(lower_bound, std::min<type>(value, upper_bound));
    }

}
