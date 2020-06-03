/******************************************************************************/
/*!
  \project Chilldew-Math
  \file    cdm_radian.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Angles in radians.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "cdm_radian.h"
#include "cdm_degree.h"

namespace chilldew::math
{

    radian::radian(degree deg_angle) noexcept
    : _angle{ deg_angle._angle * math::deg_to_rad }
    {}

    radian& radian::operator+=(radian angle) noexcept
    {
        _angle += angle._angle;
        return *this;
    }

    radian& radian::operator-=(radian angle) noexcept
    {
        _angle -= angle._angle;
        return *this;
    }

    radian& radian::operator*=(real scale) noexcept
    {
        _angle *= scale;
        return *this;
    }

    radian& radian::operator/=(real scale) noexcept
    {
        _angle /= scale;
        return *this;
    }

    radian operator+(radian lhs, radian rhs)
    {
        return radian{ lhs } += rhs;
    }

    radian operator-(radian lhs, radian rhs)
    {
        return radian{ lhs } -= rhs;
    }

    radian operator*(radian angle, real scale)
    {
        return radian{ angle } *= scale;
    }

    radian operator*(real scale, radian angle)
    {
        return radian{ angle } *= scale;
    }

    radian operator/(radian angle, real scale)
    {
        return radian{ angle } /= scale;
    }

    radian operator-(radian angle)
    {
        return radian{ -angle._angle };
    }

    bool operator==(radian lhs, radian rhs)
    {
        return lhs._angle == rhs._angle;
    }

    bool operator<(radian lhs, radian rhs)
    {
        return lhs._angle < rhs._angle;
    }

    bool operator>(radian lhs, radian rhs)
    {
        return lhs._angle > rhs._angle;
    }

    bool operator!=(radian lhs, radian rhs)
    {
        return !(lhs == rhs);
    }

    bool operator<=(radian lhs, radian rhs)
    {
        return !(lhs > rhs);
    }

    bool operator>=(radian lhs, radian rhs)
    {
        return !(lhs < rhs);
    }

}
