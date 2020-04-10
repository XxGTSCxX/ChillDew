/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Degree.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Angles in degrees.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "GTE_pch.h"
#include "GTE_Degree.h"
#include "GTE_Radian.h"
#include "GTE_Debug.h"

namespace GTE
{

    Degree::Degree(Radian rad_angle) noexcept
    : _angle{ static_cast<FLD>(rad_angle)* RAD_TO_DEG }
    {}

    Degree& Degree::operator+=(Degree angle) noexcept
    {
        _angle += angle._angle;
        return *this;
    }

    Degree& Degree::operator-=(Degree angle) noexcept
    {
        _angle -= angle._angle;
        return *this;
    }

    Degree& Degree::operator*=(FLD scale) noexcept
    {
        _angle *= scale;
        return *this;
    }

    Degree& Degree::operator/=(FLD scale) noexcept
    {
        if (scale)
            _angle /= scale;
        else
        {
            _angle = std::numeric_limits<FLD>::infinity();
            Debug::Get()->LogWarning("[GTE_Degree.cpp] Zero Division Occurred - Value set to infinity.");
        }
        return *this;
    }

    Degree::operator FLD()
    {
        return _angle;
    }

    inline bool FuzzyEqual(Degree lhs, Degree rhs, Degree epsilon)
    {
        return FuzzyEqual(static_cast<FLD>(lhs), static_cast<FLD>(rhs), static_cast<FLD>(epsilon));
    }

    inline bool FuzzyEqual(Degree lhs, Degree rhs)
    {
        return FuzzyEqual(lhs, rhs, Degree{ EPSIlON });
    }

    Degree operator+(Degree lhs, Degree rhs)
    {
        return Degree{ lhs } += rhs;
    }

    Degree operator-(Degree lhs, Degree rhs)
    {
        return Degree{ lhs } -= rhs;
    }

    Degree operator*(Degree angle, FLD scale)
    {
        return Degree{ angle } *= scale;
    }

    Degree operator*(FLD scale, Degree angle)
    {
        return Degree{ angle } *= scale;
    }

    Degree operator/(Degree angle, FLD scale)
    {
        return Degree{ angle } /= scale;
    }

    Degree operator-(Degree angle)
    {
        return Degree{ -static_cast<FLD>(angle) };
    }

    bool operator==(Degree lhs, Degree rhs)
    {
        return static_cast<FLD>(lhs) == static_cast<FLD>(rhs);
    }

    bool operator<(Degree lhs, Degree rhs)
    {
        return static_cast<FLD>(lhs) < static_cast<FLD>(rhs);
    }

    bool operator>(Degree lhs, Degree rhs)
    {
        return static_cast<FLD>(lhs) > static_cast<FLD>(rhs);
    }

    bool operator!=(Degree lhs, Degree rhs)
    {
        return !(lhs == rhs);
    }

    bool operator<=(Degree lhs, Degree rhs)
    {
        return !(lhs > rhs);
    }

    bool operator>=(Degree lhs, Degree rhs)
    {
        return !(lhs < rhs);
    }

}
