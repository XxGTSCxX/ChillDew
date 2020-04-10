/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Radian.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Angles in radians.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "GTE_pch.h"
#include "GTE_Radian.h"
#include "GTE_Degree.h"
#include "GTE_Debug.h"

namespace GTE
{

    Radian::Radian(Degree deg_angle) noexcept
    : _angle{ deg_angle._angle * DEG_TO_RAD }
    {}

    Radian& GTE::Radian::operator+=(Radian angle) noexcept
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
            Debug::Get()->LogWarning("[GTE_Radian.cpp] Zero Division Occurred - Value set to infinity.");
        }
        return *this;
    }

    bool FuzzyEqual(Radian lhs, Radian rhs, Radian epsilon)
    {
        return FuzzyEqual(lhs._angle, rhs._angle, epsilon._angle);
    }

    bool FuzzyEqual(Radian lhs, Radian rhs)
    {
        return FuzzyEqual(lhs._angle, rhs._angle, EPSIlON);
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
