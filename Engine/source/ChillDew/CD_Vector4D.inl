/******************************************************************************/
/*!
  \project ChillDew-Engine
  \file    CD_Vector4D.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    General 4D vector implementation.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Vector4D.h"
#include <algorithm> // std::min, std::max

namespace CD
{

    template <typename T>
    template <typename ... Params, typename>
    inline constexpr VectorData<T, 4>::VectorData(Params&& ... args) noexcept
    : _array{ static_cast<T>(args)... }
    {}

    template <typename T> Vector<T, 4> const Vector<T, 4>::one {  1,  1,  1 };
    template <typename T> Vector<T, 4> const Vector<T, 4>::zero{  0,  0,  0 };

    template <typename T>
    template <typename X, typename Y, typename Z, typename W, typename>
    inline constexpr Vector<T, 4>::Vector(X&& x, Y&& y, Z&& z, W&& w) noexcept
    : VectorData<T, 4>{ static_cast<T>(x), static_cast<T>(y), static_cast<T>(z), static_cast<T>(w) }
    {}

    template <typename T>
    template <typename U, typename>
    inline constexpr Vector<T, 4>::Vector(U&& fill_value) noexcept
    : VectorData<T, 4>{ static_cast<T>(fill_value), static_cast<T>(fill_value), static_cast<T>(fill_value), static_cast<T>(fill_value) }
    {}

    template <typename T>
    template <typename U, typename>
    inline constexpr Vector<T, 4>::Vector(Vector<U, 1> const& vector) noexcept
    : VectorData<T, 4>{ static_cast<T>(vector[0]) }
    {}

    template <typename T>
    template <typename U, typename>
    inline constexpr Vector<T, 4>::Vector(Vector<U, 2> const& vector) noexcept
    : VectorData<T, 4>{ static_cast<T>(vector[0]), static_cast<T>(vector[1]) }
    {}

    template <typename T>
    template <typename U, typename>
    inline constexpr Vector<T, 4>::Vector(Vector<U, 3> const& vector) noexcept
    : VectorData<T, 4>{ static_cast<T>(vector[0]), static_cast<T>(vector[1]), static_cast<T>(vector[2]) }
    {}

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline constexpr Vector<T, 4>::Vector(Vector<U, U_SZ> const& vector) noexcept
    : VectorData<T, 4>{ static_cast<T>(vector[0]), static_cast<T>(vector[1]), static_cast<T>(vector[2]), static_cast<T>(vector[3]) }
    {}

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline Vector<T, 4>& Vector<T, 4>::operator=(Vector<U, U_SZ> const& vector)
    {
        switch (U_SZ)
        {
        default: w = static_cast<T>(vector[3]);
        case 3 : z = static_cast<T>(vector[2]);
        case 2 : y = static_cast<T>(vector[1]);
        case 1 : x = static_cast<T>(vector[0]);
        }        
        return *this;
    }

    template <typename T>
    inline Vector<T, 4>& Vector<T, 4>::operator+=(Vector<T, 4> const& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }

    template <typename T>
    inline Vector<T, 4>& Vector<T, 4>::operator-=(Vector<T, 4> const& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
        return *this;
    }

    template <typename T>
    inline Vector<T, 4>& Vector<T, 4>::operator*=(Vector<T, 4> const& other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        w *= other.w;
        return *this;
    }

    template <typename T>
    inline Vector<T, 4>& Vector<T, 4>::operator*=(T const& scale)
    {
        x *= scale;
        y *= scale;
        z *= scale;
        w *= scale;
        return *this;
    }

    template <typename T>
    inline Vector<T, 4>& Vector<T, 4>::operator/=(T const& scale)
    {
        if (scale)
        {
            x /= scale;
            y /= scale;
            z /= scale;
            w /= scale;
        }
        else
        {
            x = y = z = w = std::numeric_limits<T>::infinity();
        }
        return *this;
    }

    template <typename T>
    inline T& Vector<T, 4>::operator[](size_t index)
    {
        return _array[index];
    }

    template <typename T>
    inline T const& Vector<T, 4>::operator[](size_t index) const
    {
        return _array[index];
    }

    template <typename T>
    inline T* Vector<T, 4>::data()
    {
        return _array.data();
    }

    template <typename T>
    inline T const* Vector<T, 4>::data() const
    {
        return _array.data();
    }

    template <typename T>
    inline void CD::Vector<T, 4>::fill(T const& value)
    {
        _array.fill(value);
    }

    template <typename T>
    inline constexpr size_t Vector<T, 4>::size()
    {
        return 4;
    }

    template <typename T>
    Vector<T, 4> operator-(Vector<T, 4> const& vector)
    {
        return Vector<T, 4>{ -vector.x, -vector.y, -vector.z, -vector.w };
    }

    template <typename T>
    bool operator==(Vector<T, 4> const& lhs, Vector<T, 4> const& rhs)
    {
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
    }

    template <typename T>
    CD::ostream& operator<<(CD::ostream& stream, Vector<T, 4> const& vector)
    {
        return stream << CD_STRING("{ ") << vector.x << CD_STRING(", ") << vector.y << CD_STRING(", ") << vector.z << CD_STRING(", ") << vector.w << CD_STRING(" }");
    }

    template <typename T>
    CD::istream& operator>>(CD::istream& stream, Vector<T, 4>& vector)
    {
        TCHAR discard;
        return stream >> discard >> vector.x >> discard >> vector.y >> discard >> vector.z >> discard >> vector.w >> discard;
    }

    template <typename T>
    T Dot(Vector<T, 4> const& lhs, Vector<T, 4> const& rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
    }

    template <typename T>
    Vector<T, 4> Max(Vector<T, 4> const& lhs, Vector<T, 4> const& rhs)
    {
        return Vector<T, 4>{ std::max<T>(lhs.x, rhs.x), std::max<T>(lhs.y, rhs.y), std::max<T>(lhs.z, rhs.z), std::max<T>(lhs.w, rhs.w) };
    }

    template <typename T>
    Vector<T, 4> Min(Vector<T, 4> const& lhs, Vector<T, 4> const& rhs)
    {
        return Vector<T, 4>{ std::min<T>(lhs.x, rhs.x), std::min<T>(lhs.y, rhs.y), std::min<T>(lhs.z, rhs.z), std::min<T>(lhs.w, rhs.w) };
    }

}
