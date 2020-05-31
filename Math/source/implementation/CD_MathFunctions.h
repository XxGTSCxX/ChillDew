#pragma once

#include "CD_MathDefines.h"

namespace chilldew
{

    inline bool fuzzy_equal(real lhs, real rhs, real epsilon) noexcept;
    inline bool fuzzy_equal(real lhs, real rhs              ) noexcept;

    template <typename type> constexpr bool fuzzy_equal(type const& lhs  , type const& rhs        , type const& epsilon    ) noexcept; // Requires binary operator - and operator < for T
    template <typename type> constexpr type clamp      (type const& value, type const& lower_bound, type const& upper_bound) noexcept; // Requires < operator for T

}
