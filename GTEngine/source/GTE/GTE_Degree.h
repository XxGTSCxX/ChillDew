/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Degree.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Angles in degrees.

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

    struct Radian;

    struct GTE_API Degree final
    {
        Real _angle = static_cast<Real>(0.0l);

        constexpr          Degree()                 noexcept = default;
        constexpr          Degree(Degree const&)    noexcept = default;
        constexpr explicit Degree(Real   deg_angle) noexcept;
                  explicit Degree(Radian rad_angle) noexcept;

        Degree& operator=(Degree const&) noexcept = default;

        Degree& operator+=(Degree angle) noexcept;
        Degree& operator-=(Degree angle) noexcept;
        Degree& operator*=(Real   scale) noexcept;
        Degree& operator/=(Real   scale) noexcept; // If scale is 0, value will be set to infinity
    };

    Degree operator+(Degree lhs  , Degree rhs  );
    Degree operator-(Degree lhs  , Degree rhs  );
    Degree operator*(Degree angle, Real   scale);
    Degree operator*(Real   scale, Degree angle);
    Degree operator/(Degree angle, Real   scale);
    Degree operator-(Degree angle              );

    bool operator==(Degree lhs, Degree rhs);
    bool operator< (Degree lhs, Degree rhs);
    bool operator> (Degree lhs, Degree rhs);
    bool operator!=(Degree lhs, Degree rhs);
    bool operator<=(Degree lhs, Degree rhs);
    bool operator>=(Degree lhs, Degree rhs);

}

#include "GTE_Degree.inl"
