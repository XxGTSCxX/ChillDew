/******************************************************************************/
/*!
  \project ChillDew-Engine
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
#include "CD_Debug.h"

namespace CD
{

    Radian::Radian(Degree deg_angle) noexcept
    : _angle{ deg_angle._angle * Math::DEG_TO_RAD }
    {}

    Radian& CD::Radian::operator+=(Radian angle) noexcept
    {
        _angle += angle._angle;
        return *this;
    }

    Radian& Radian::operator-=(Radian angle) noexcept
    {
        _angle -= angle._angle;
        return *this;
    }

    Radian& Radian::operator*=(Real scale) noexcept
    {
        _angle *= scale;
        return *this;
    }

    Radian& Radian::operator/=(Real scale) noexcept
    {
        if (scale)
            _angle /= scale;
        else
        {
            _angle = std::numeric_limits<Real>::infinity();
            Debug::Get()->LogWarning("[CD_Radian.cpp] Zero Division Occurred - Value set to infinity.");
        }
        return *this;
    }

    Radian operator+(Radian lhs, Radian rhs)
    {
        return Radian{ lhs } += rhs;
    }

    Radian operator-(Radian lhs, Radian rhs)
    {
        return Radian{ lhs } -= rhs;
    }

    Radian operator*(Radian angle, Real scale)
    {
        return Radian{ angle } *= scale;
    }

    Radian operator*(Real scale, Radian angle)
    {
        return Radian{ angle } *= scale;
    }

    Radian operator/(Radian angle, Real scale)
    {
        return Radian{ angle } /= scale;
    }

    Radian operator-(Radian angle)
    {
        return Radian{ -angle._angle };
    }

    bool operator==(Radian lhs, Radian rhs)
    {
        return lhs._angle == rhs._angle;
    }

    bool operator<(Radian lhs, Radian rhs)
    {
        return lhs._angle < rhs._angle;
    }

    bool operator>(Radian lhs, Radian rhs)
    {
        return lhs._angle > rhs._angle;
    }

    bool operator!=(Radian lhs, Radian rhs)
    {
        return !(lhs == rhs);
    }

    bool operator<=(Radian lhs, Radian rhs)
    {
        return !(lhs > rhs);
    }

    bool operator>=(Radian lhs, Radian rhs)
    {
        return !(lhs < rhs);
    }

}
