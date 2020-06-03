/******************************************************************************/
/*!
  \project Chilldew-Math
  \file    cdm_defines.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Math definitions.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include <limits> // std::numeric_limits

namespace chilldew
{
  namespace math
  {

    using real = double;

    static constexpr real epsilon    = std::numeric_limits<real>::epsilon();
    static constexpr real pi         = static_cast<real>(3.14159265358979323846l);
    static constexpr real deg_to_rad = pi / static_cast<real>(180.0l);
    static constexpr real rad_to_deg = static_cast<real>(180.0l) / pi;

  }

}

namespace cdm = ::chilldew::math;
