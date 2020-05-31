/******************************************************************************/
/*!
  \project Chilldew-Engine
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
#include "CD_MathDefines.h"

namespace chilldew
{

    struct degree;

    struct CD_API radian final
    {
    public:

        real _angle = static_cast<real>(0.0l);

        constexpr          radian()                 noexcept = default;
        constexpr          radian(radian const&)    noexcept = default;
        constexpr explicit radian(real   rad_angle) noexcept;
                  explicit radian(degree deg_angle) noexcept;

        constexpr radian& operator=(radian const&) noexcept = default;

        radian& operator+=(radian angle) noexcept;
        radian& operator-=(radian angle) noexcept;
        radian& operator*=(real   scale) noexcept;
        radian& operator/=(real   scale) noexcept;                              // If scale is 0, value will be set to infinity
    };

    radian operator+(radian lhs  , radian rhs  );
    radian operator-(radian lhs  , radian rhs  );
    radian operator*(radian angle, real   scale);
    radian operator*(real   scale, radian angle);
    radian operator/(radian angle, real   scale);
    radian operator-(radian angle              );

    bool operator==(radian lhs, radian rhs);
    bool operator< (radian lhs, radian rhs);
    bool operator> (radian lhs, radian rhs);
    bool operator!=(radian lhs, radian rhs);
    bool operator<=(radian lhs, radian rhs);
    bool operator>=(radian lhs, radian rhs);

}
