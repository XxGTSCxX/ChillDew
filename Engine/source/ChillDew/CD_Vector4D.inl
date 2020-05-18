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
    : VectorData<T, 4>{ std::forward<X>(x), std::forward<Y>(y), std::forward<Z>(z), std::forward<W>(w) }
    {}

    template <typename T>
    template <typename U, typename>
    inline constexpr Vector<T, 4>::Vector(U&& fill_value) noexcept
    : VectorData<T, 4>{ std::forward<U>(fill_value), std::forward<U>(fill_value), std::forward<U>(fill_value), std::forward<U>(fill_value) }
    {}

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline constexpr Vector<T, 4>::Vector(Vector<U, U_SZ> const& vector) noexcept
    : VectorData<T, 4>{ vector[0], vector[1], vector[2], vector[3] }
    {}

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline Vector<T, 4>& Vector<T, 4>::operator=(Vector<U, U_SZ> const& vector)
    {
        x = static_cast<T>(vector[0]);
        y = static_cast<T>(vector[1]);
        z = static_cast<T>(vector[2]);
        w = static_cast<T>(vector[3]);
        return *this;
    }

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline Vector<T, 4>& Vector<T, 4>::operator+=(Vector<U, U_SZ> const& vector)
    {
        x += static_cast<T>(vector[0]);
        y += static_cast<T>(vector[1]);
        z += static_cast<T>(vector[2]);
        w += static_cast<T>(vector[3]);
        return *this;
    }

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline Vector<T, 4>& Vector<T, 4>::operator-=(Vector<U, U_SZ> const& vector)
    {
        x -= static_cast<T>(vector[0]);
        y -= static_cast<T>(vector[1]);
        z -= static_cast<T>(vector[2]);
        w -= static_cast<T>(vector[3]);
        return *this;
    }

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline Vector<T, 4>& Vector<T, 4>::operator*=(Vector<U, U_SZ> const& vector)
    {
        x *= static_cast<T>(vector[0]);
        y *= static_cast<T>(vector[1]);
        z *= static_cast<T>(vector[2]);
        w *= static_cast<T>(vector[3]);
        return *this;
    }

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline Vector<T, 4>& Vector<T, 4>::operator/=(Vector<U, U_SZ> const& vector)
    {
        x /= static_cast<T>(vector[0]);
        y /= static_cast<T>(vector[1]);
        z /= static_cast<T>(vector[2]);
        w /= static_cast<T>(vector[3]);
        return *this;
    }

    template <typename T>
    template <typename U, typename>
    inline Vector<T, 4>& Vector<T, 4>::operator*=(U const& scale)
    {
        T converted_scale = static_cast<T>(scale);
        x *= converted_scale;
        y *= converted_scale;
        z *= converted_scale;
        w *= converted_scale;
        return *this;
    }

    template <typename T>
    template <typename U, typename>
    inline Vector<T, 4>& Vector<T, 4>::operator/=(U const& scale)
    {
        if (T converted_scale = static_cast<T>(scale))
        {
            converted_scale = static_cast<T>(1) / converted_scale;
            x *= converted_scale;
            y *= converted_scale;
            z *= converted_scale;
            w *= converted_scale;
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
