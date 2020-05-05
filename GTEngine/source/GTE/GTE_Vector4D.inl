/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Vector4D.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    General 4D vector implementation.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Vector4D.h"

namespace GTE
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
    inline void GTE::Vector<T, 4>::fill(T const& value)
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
    GTE::ostream& operator<<(GTE::ostream& stream, Vector<T, 4> const& vector)
    {
        return stream << GTE_STRING("{ ") << vector.x << GTE_STRING(", ") << vector.y << GTE_STRING(", ") << vector.z << GTE_STRING(", ") << vector.w << GTE_STRING(" }");
    }

    template <typename T>
    GTE::istream& operator>>(GTE::istream& stream, Vector<T, 4>& vector)
    {
        char discard;
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
        return Vector<T, 4>{ std::max(lhs.x, rhs.x), std::max(lhs.y, rhs.y), std::max(lhs.z, rhs.z), std::max(lhs.w, rhs.w) };
    }

    template <typename T>
    Vector<T, 4> Min(Vector<T, 4> const& lhs, Vector<T, 4> const& rhs)
    {
        return Vector<T, 4>{ std::min(lhs.x, rhs.x), std::min(lhs.y, rhs.y), std::min(lhs.z, rhs.z), std::min(lhs.w, rhs.w) };
    }

}
