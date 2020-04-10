/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Radian.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Angles in radians.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Core.h"
#include "GTE_Math.h"

namespace GTE
{

    struct Degree;

    struct GTE_API Radian final
    {
    public:

        Real _angle = static_cast<Real>(0.0l);

        constexpr          Radian()                 noexcept = default;
        constexpr          Radian(Radian const&)    noexcept = default;
        constexpr explicit Radian(Real   rad_angle) noexcept;
                  explicit Radian(Degree deg_angle) noexcept;

        Radian& operator=(Radian const&) noexcept = default;

        Radian& operator+=(Radian angle) noexcept;
        Radian& operator-=(Radian angle) noexcept;
        Radian& operator*=(Real   scale) noexcept;
        Radian& operator/=(Real   scale) noexcept;                              // If scale is 0, value will be set to infinity
    };

    bool FuzzyEqual(Radian lhs, Radian rhs, Radian epsilon);
    bool FuzzyEqual(Radian lhs, Radian rhs                );

    Radian operator+(Radian lhs  , Radian rhs  );
    Radian operator-(Radian lhs  , Radian rhs  );
    Radian operator*(Radian angle, Real   scale);
    Radian operator*(Real   scale, Radian angle);
    Radian operator/(Radian angle, Real   scale);
    Radian operator-(Radian angle              );

    bool operator==(Radian lhs, Radian rhs);
    bool operator< (Radian lhs, Radian rhs);
    bool operator> (Radian lhs, Radian rhs);
    bool operator!=(Radian lhs, Radian rhs);
    bool operator<=(Radian lhs, Radian rhs);
    bool operator>=(Radian lhs, Radian rhs);

}

#include "GTE_Radian.inl"
