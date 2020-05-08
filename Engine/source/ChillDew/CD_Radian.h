/******************************************************************************/
/*!
  \project ChillDew-Engine
  \file    CD_Radian.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Angles in radians.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Core.h"
#include "CD_Math.h"

namespace CD
{

    struct Degree;

    struct CD_API Radian final
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

#include "CD_Radian.inl"
