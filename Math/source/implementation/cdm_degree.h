/******************************************************************************/
/*!
  \project Chilldew-Math
  \file    cdm_degree.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Angles in degrees.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cdm_defines.h"

namespace chilldew::math
{

    struct radian;

    struct degree final
    {
        real _angle = static_cast<real>(0.0l);

        constexpr          degree()                 noexcept = default;
        constexpr          degree(degree const&)    noexcept = default;
        constexpr explicit degree(real   deg_angle) noexcept;
                  explicit degree(radian rad_angle) noexcept;

        constexpr degree& operator=(degree const&) noexcept = default;

        degree& operator+=(degree angle) noexcept;
        degree& operator-=(degree angle) noexcept;
        degree& operator*=(real   scale) noexcept;
        degree& operator/=(real   scale) noexcept; // If scale is 0, value will be set to infinity
    };

    degree operator+(degree lhs  , degree rhs  );
    degree operator-(degree lhs  , degree rhs  );
    degree operator*(degree angle, real   scale);
    degree operator*(real   scale, degree angle);
    degree operator/(degree angle, real   scale);
    degree operator-(degree angle              );

    bool operator==(degree lhs, degree rhs);
    bool operator< (degree lhs, degree rhs);
    bool operator> (degree lhs, degree rhs);
    bool operator!=(degree lhs, degree rhs);
    bool operator<=(degree lhs, degree rhs);
    bool operator>=(degree lhs, degree rhs);

}
