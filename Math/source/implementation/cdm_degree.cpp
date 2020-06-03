/******************************************************************************/
/*!
  \project Chilldew-Math
  \file    cdm_degree.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Angles in degrees.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "cdm_degree.h"
#include "cdm_radian.h"

namespace chilldew::math
{

    degree::degree(radian rad_angle) noexcept
    : _angle{ rad_angle._angle * math::rad_to_deg }
    {}

    degree& degree::operator+=(degree angle) noexcept
    {
        _angle += angle._angle;
        return *this;
    }

    degree& degree::operator-=(degree angle) noexcept
    {
        _angle -= angle._angle;
        return *this;
    }

    degree& degree::operator*=(real scale) noexcept
    {
        _angle *= scale;
        return *this;
    }

    degree& degree::operator/=(real scale) noexcept
    {
        _angle /= scale;
        return *this;
    }

    degree operator+(degree lhs, degree rhs)
    {
        return degree{ lhs } += rhs;
    }

    degree operator-(degree lhs, degree rhs)
    {
        return degree{ lhs } -= rhs;
    }

    degree operator*(degree angle, real scale)
    {
        return degree{ angle } *= scale;
    }

    degree operator*(real scale, degree angle)
    {
        return degree{ angle } *= scale;
    }

    degree operator/(degree angle, real scale)
    {
        return degree{ angle } /= scale;
    }

    degree operator-(degree angle)
    {
        return degree{ -angle._angle };
    }

    bool operator==(degree lhs, degree rhs)
    {
        return lhs._angle == rhs._angle;
    }

    bool operator<(degree lhs, degree rhs)
    {
        return lhs._angle < rhs._angle;
    }

    bool operator>(degree lhs, degree rhs)
    {
        return lhs._angle > rhs._angle;
    }

    bool operator!=(degree lhs, degree rhs)
    {
        return !(lhs == rhs);
    }

    bool operator<=(degree lhs, degree rhs)
    {
        return !(lhs > rhs);
    }

    bool operator>=(degree lhs, degree rhs)
    {
        return !(lhs < rhs);
    }

}
