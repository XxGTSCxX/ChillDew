/******************************************************************************/
/*!
  \project ChillDew-Engine
  \file    CD_Vector2D.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Partial vector specialisation for 2D vector implementation.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Vector2D.h"
#include "CD_Degree.inl"
#include <algorithm> // std::min, std::max

namespace CD
{

    template <typename T>
    template <typename ... Params, typename>
    inline constexpr VectorData<T, 2>::VectorData(Params&& ... args) noexcept
    : _array{ static_cast<T>(args)... }
    {}

    template <typename T> Vector<T, 2> const Vector<T, 2>::up   {  0,  1 };
    template <typename T> Vector<T, 2> const Vector<T, 2>::down {  0, -1 };
    template <typename T> Vector<T, 2> const Vector<T, 2>::left { -1,  0 };
    template <typename T> Vector<T, 2> const Vector<T, 2>::right{  1,  0 };
    template <typename T> Vector<T, 2> const Vector<T, 2>::one  {  1,  1 };
    template <typename T> Vector<T, 2> const Vector<T, 2>::zero {  0,  0 };

    template <typename T>
    template <typename U, typename V, typename>
    inline constexpr Vector<T, 2>::Vector(U&& x, V&& y) noexcept
    : VectorData<T, 2>{ static_cast<T>(x), static_cast<T>(y) }
    {}

    template <typename T>
    template <typename U, typename>
    inline constexpr Vector<T, 2>::Vector(U&& fill_value) noexcept
    : VectorData<T, 2>{ static_cast<T>(fill_value), static_cast<T>(fill_value) }
    {}

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline constexpr Vector<T, 2>::Vector(Vector<U, U_SZ> const& vector) noexcept
    : VectorData<T, 2>{ vector[0], vector[1] }
    {}

    template <typename T>
    template <typename U, typename>
    inline constexpr Vector<T, 2>::Vector(Vector<U, 1> const& vector) noexcept
    : VectorData<T, 2>{ vector[0] }
    {}

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline Vector<T, 2>& Vector<T, 2>::operator=(Vector<U, U_SZ> const& vector)
    {
        switch (U_SZ)
        {
        default: y = static_cast<T>(vector[1]);
        case 1 : x = static_cast<T>(vector[0]);
        }
        return *this;
    }

    template <typename T>
    inline Vector<T, 2>& Vector<T, 2>::operator+=(Vector<T, 2> const& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    template <typename T>
    inline Vector<T, 2>& Vector<T, 2>::operator-=(Vector<T, 2> const& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    template <typename T>
    inline Vector<T, 2>& Vector<T, 2>::operator*=(Vector<T, 2> const& other)
    {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    template <typename T>
    inline Vector<T, 2>& Vector<T, 2>::operator*=(T const& scale)
    {
        x *= scale;
        y *= scale;
        return *this;
    }

    template <typename T>
    inline Vector<T, 2>& Vector<T, 2>::operator/=(T const& scale)
    {
        if (scale)
        {
            x /= scale;
            y /= scale;
        }
        else
        {
            x = y = std::numeric_limits<T>::infinity();
        }
        return *this;
    }

    template <typename T>
    inline T& Vector<T, 2>::operator[](size_t index)
    {
        return _array[index];
    }

    template <typename T>
    inline T const& Vector<T, 2>::operator[](size_t index) const
    {
        return _array[index];
    }

    template <typename T>
    inline T* Vector<T, 2>::data()
    {
        return _array.data();
    }

    template <typename T>
    inline T const* Vector<T, 2>::data() const
    {
        return _array.data();
    }

    template <typename T>
    inline void CD::Vector<T, 2>::fill(T const& value)
    {
        _array.fill(value);
    }

    template <typename T>
    inline constexpr size_t Vector<T, 2>::size()
    {
        return 2;
    }

    template <typename T>
    Vector<T, 2> operator-(Vector<T, 2> const& vector)
    {
        return Vector<T, 2>{ -vector.x, -vector.y };
    }

    template <typename T>
    bool operator==(Vector<T, 2> const& lhs, Vector<T, 2> const& rhs)
    {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }

    template <typename T>
    CD::ostream& operator<<(CD::ostream& stream, Vector<T, 2> const& vector)
    {
        return stream << CD_STRING("{ ") << vector.x << CD_STRING(", ") << vector.y << CD_STRING(" }");
    }

    template <typename T>
    CD::istream& operator>>(CD::istream& stream, Vector<T, 2>& vector)
    {
        TCHAR discard;
        return stream >> discard >> vector.x >> discard >> vector.y >> discard;
    }

    template <typename T>
    Vector<T, 2> Perpendicular(Vector<T, 2> const& vector)
    {
        Vector<T, 2> result{ 0,0 };
        T            mag = Magnitude(vector);

        if (mag)
        {
            Radian rad = acos(vector.x / mag) + 90 * Math::DEG_TO_RAD;
            result.x   = mag * cos(rad._angle);
            result.y   = mag * sin(rad._angle);
        }

        return result;
    }

    template <typename T>
    T Dot(Vector<T, 2> const& lhs, Vector<T, 2> const& rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    template <typename T>
    Vector<T, 2> Max(Vector<T, 2> const& lhs, Vector<T, 2> const& rhs)
    {
        return Vector<T, 2>{ std::max<T>(lhs.x, rhs.x), std::max<T>(lhs.y, rhs.y) };
    }

    template <typename T>
    Vector<T, 2> Min(Vector<T, 2> const& lhs, Vector<T, 2> const& rhs)
    {
        return Vector<T, 2>{ std::min<T>(lhs.x, rhs.x), std::min<T>(lhs.y, rhs.y) };
    }

    template <typename T>
    Degree Angle(Vector<T, 2> const& lhs, Vector<T, 2> const& rhs)
    {
        return Degree{ static_cast<Real>(acos(Dot(Normalise(lhs), Normalise(rhs))))* Math::RAD_TO_DEG };
    }

    template <typename T>
    Degree SignedAngle(Vector<T, 2> const& from, Vector<T, 2> const& to)
    {
        Degree angle = Angle(from, to);
        if (Dot(to, Perpendicular(from)) < static_cast<T>(0))
            angle = -angle;
        return angle;
    }

    template <typename T>
    Vector<T, 2> Reflect(Vector<T, 2> const& vector, Vector<T, 2> const& normal)
    {
        return vector - static_cast<T>(2) * Project(vector, normal);
    }

}
