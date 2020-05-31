/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    CD_Radian.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Angles in radians.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "CD_pch.h"
#include "CD_Radian.h"
#include "CD_Degree.h"

namespace chilldew
{

    radian::radian(degree deg_angle) noexcept
    : _angle{ deg_angle._angle * math::deg_to_rad }
    {}

    radian& CD::radian::operator+=(radian angle) noexcept
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
