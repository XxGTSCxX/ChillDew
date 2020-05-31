/******************************************************************************/
/*!
  \project Chilldew-Engine
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

namespace chilldew
{

    template <typename T> vector<T, 4> const vector<T, 4>::one {  1,  1,  1 };
    template <typename T> vector<T, 4> const vector<T, 4>::zero{  0,  0,  0 };

    template <typename T>
    template <typename X, typename Y, typename Z, typename W, typename>
    inline constexpr vector<T, 4>::vector(X&& x, Y&& y, Z&& z, W&& w) noexcept
    : detail::vector_base<T, 4>{ static_cast<T>(x), static_cast<T>(y), static_cast<T>(z), static_cast<T>(w) }
    {}

    template <typename T>
    template <typename U, typename>
    inline constexpr vector<T, 4>::vector(U&& fill_value) noexcept
    : detail::vector_base<T, 4>{ static_cast<T>(fill_value), static_cast<T>(fill_value), static_cast<T>(fill_value), static_cast<T>(fill_value) }
    {}

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline constexpr vector<T, 4>::vector(vector<U, U_SZ> const& vector) noexcept
    : detail::vector_base<T, 4>{ vector[0], vector[1], vector[2], vector[3] }
    {}

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline vector<T, 4>& vector<T, 4>::operator=(vector<U, U_SZ> const& vector)
    {
        x = static_cast<T>(vector[0]);
        y = static_cast<T>(vector[1]);
        z = static_cast<T>(vector[2]);
        w = static_cast<T>(vector[3]);
        return *this;
    }

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline vector<T, 4>& vector<T, 4>::operator+=(vector<U, U_SZ> const& vector)
    {
        x += static_cast<T>(vector[0]);
        y += static_cast<T>(vector[1]);
        z += static_cast<T>(vector[2]);
        w += static_cast<T>(vector[3]);
        return *this;
    }

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline vector<T, 4>& vector<T, 4>::operator-=(vector<U, U_SZ> const& vector)
    {
        x -= static_cast<T>(vector[0]);
        y -= static_cast<T>(vector[1]);
        z -= static_cast<T>(vector[2]);
        w -= static_cast<T>(vector[3]);
        return *this;
    }

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline vector<T, 4>& vector<T, 4>::operator*=(vector<U, U_SZ> const& vector)
    {
        x *= static_cast<T>(vector[0]);
        y *= static_cast<T>(vector[1]);
        z *= static_cast<T>(vector[2]);
        w *= static_cast<T>(vector[3]);
        return *this;
    }

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline vector<T, 4>& vector<T, 4>::operator/=(vector<U, U_SZ> const& vector)
    {
        x /= static_cast<T>(vector[0]);
        y /= static_cast<T>(vector[1]);
        z /= static_cast<T>(vector[2]);
        w /= static_cast<T>(vector[3]);
        return *this;
    }

    template <typename T>
    template <typename U, typename>
    inline vector<T, 4>& vector<T, 4>::operator*=(U const& scale)
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
    inline vector<T, 4>& vector<T, 4>::operator/=(U const& scale)
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
    inline T& vector<T, 4>::operator[](size_t index)
    {
        return _array[index];
    }

    template <typename T>
    inline T const& vector<T, 4>::operator[](size_t index) const
    {
        return _array[index];
    }

    template <typename T>
    inline T* vector<T, 4>::data()
    {
        return _array.data();
    }

    template <typename T>
    inline T const* vector<T, 4>::data() const
    {
        return _array.data();
    }

    template <typename T>
    inline void CD::vector<T, 4>::fill(T const& value)
    {
        _array.fill(value);
    }

    template <typename T>
    inline constexpr std::size_t vector<T, 4>::size() noexcept
    {
        return 4;
    }

    template <typename T>
    vector<T, 4> operator-(vector<T, 4> const& vector)
    {
        return vector<T, 4>{ -vector.x, -vector.y, -vector.z, -vector.w };
    }

    template <typename T>
    bool operator==(vector<T, 4> const& lhs, vector<T, 4> const& rhs)
    {
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
    }

    template <typename T>
    CD::ostream& operator<<(CD::ostream& stream, vector<T, 4> const& vector)
    {
        return stream << CD_STRING("{ ") << vector.x << CD_STRING(", ") << vector.y << CD_STRING(", ") << vector.z << CD_STRING(", ") << vector.w << CD_STRING(" }");
    }

    template <typename T>
    CD::istream& operator>>(CD::istream& stream, vector<T, 4>& vector)
    {
        TCHAR discard;
        return stream >> discard >> vector.x >> discard >> vector.y >> discard >> vector.z >> discard >> vector.w >> discard;
    }

    template <typename T>
    T Dot(vector<T, 4> const& lhs, vector<T, 4> const& rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
    }

    template <typename T>
    vector<T, 4> Max(vector<T, 4> const& lhs, vector<T, 4> const& rhs)
    {
        return vector<T, 4>{ std::max<T>(lhs.x, rhs.x), std::max<T>(lhs.y, rhs.y), std::max<T>(lhs.z, rhs.z), std::max<T>(lhs.w, rhs.w) };
    }

    template <typename T>
    vector<T, 4> Min(vector<T, 4> const& lhs, vector<T, 4> const& rhs)
    {
        return vector<T, 4>{ std::min<T>(lhs.x, rhs.x), std::min<T>(lhs.y, rhs.y), std::min<T>(lhs.z, rhs.z), std::min<T>(lhs.w, rhs.w) };
    }

}
