/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Math.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Math stuff.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include <limits> // std::numeric_limits

namespace GTE
{

    using FLD = double;

    static constexpr FLD EPSIlON    = std::numeric_limits<FLD>::epsilon();
    static constexpr FLD M_PI       = static_cast<FLD>(3.14159265358979323846l);
    static constexpr FLD DEG_TO_RAD = M_PI / static_cast<FLD>(180.0l);
    static constexpr FLD RAD_TO_DEG = static_cast<FLD>(180.0l) / M_PI;

    inline bool FuzzyEqual(FLD lhs, FLD rhs, FLD epsilon);
    inline bool FuzzyEqual(FLD lhs, FLD rhs             );

    template <typename T>
    inline T Clamp(T const& value, T const& lower_bound, T const& upper_bound); // Requires < operator for T

}
