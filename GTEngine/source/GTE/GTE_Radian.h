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

    class Degree;

    class GTE_API Radian final
    {
    public:

        constexpr          Radian()                 noexcept = default;
        constexpr          Radian(Radian const&)    noexcept = default;
        constexpr explicit Radian(FLD    rad_angle) noexcept;
                           Radian(Degree deg_angle) noexcept;

        Radian& operator=(Radian const&) noexcept = default;

        Radian& operator+=(Radian angle) noexcept;
        Radian& operator-=(Radian angle) noexcept;
        Radian& operator*=(FLD    scale) noexcept;
        Radian& operator/=(FLD    scale) noexcept; // If scale is 0, value will be set to infinity

        explicit operator FLD();

    private:

        FLD _angle = static_cast<FLD>(0.0l);
    };

    inline bool FuzzyEqual(Radian lhs, Radian rhs, Radian epsilon);
    inline bool FuzzyEqual(Radian lhs, Radian rhs                );

    Radian operator+(Radian lhs  , Radian rhs  );
    Radian operator-(Radian lhs  , Radian rhs  );
    Radian operator*(Radian angle, FLD    scale);
    Radian operator*(FLD    scale, Radian angle);
    Radian operator/(Radian angle, FLD    scale);
    Radian operator-(Radian angle              );

    bool operator==(Radian lhs, Radian rhs);
    bool operator< (Radian lhs, Radian rhs);
    bool operator> (Radian lhs, Radian rhs);
    bool operator!=(Radian lhs, Radian rhs);
    bool operator<=(Radian lhs, Radian rhs);
    bool operator>=(Radian lhs, Radian rhs);

}

#include "GTE_Radian.inl"
