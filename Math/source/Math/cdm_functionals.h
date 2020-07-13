/******************************************************************************/
/*!
  \project Chilldew-Math
  \file    cdm_functionals.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Math functions.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cdm_defines.h"

namespace chilldew::math
{

    constexpr bool fuzzy_equal(real lhs, real rhs, real epsilon_value) noexcept;
    constexpr bool fuzzy_equal(real lhs, real rhs                    ) noexcept;

    template <typename type> constexpr bool fuzzy_equal(type const& lhs  , type const& rhs        , type const& epsilon_value) noexcept; // Requires binary operator - and operator < for T
    template <typename type> constexpr type clamp      (type const& value, type const& lower_bound, type const& upper_bound  ) noexcept; // Requires < operator for T

}
