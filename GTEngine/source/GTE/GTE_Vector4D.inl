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

    template <typename T> Vector<T, 4> const Vector<T, 4>::one {  1,  1,  1 };
    template <typename T> Vector<T, 4> const Vector<T, 4>::zero{  0,  0,  0 };

    template <typename T>
    template <typename ... Params, typename>
    inline constexpr Vector<T, 4>::Vector(Params&& ... args) noexcept
    : _array{ static_cast<T>(std::forward<Params>(args))... }
    {}

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline Vector<T, 4>::Vector(Vector<U, U_SZ> const& vector)
    {
        if constexpr (SZ < U_SZ)
        {
            for (size_t i = 0; i < SZ; ++i)
            {
                _array[i] = vector[i];
            }
        }
        else
        {
            for (size_t i = 0; i < U_SZ; ++i)
            {
                _array[i] = vector[i];
            }
        }
    }

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline Vector<T, 4>& Vector<T, 4>::operator=(Vector<U, U_SZ> const& vector)
    {
        new (this) Vector<T, 4>{ vector };
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
    Vector<T, 4> operator+(Vector<T, 4> const& lhs, Vector<T, 4> const& rhs)
    {
        return Vector<T, 4>{ lhs } += rhs;
    }

    template <typename T>
    Vector<T, 4> operator-(Vector<T, 4> const& lhs, Vector<T, 4> const& rhs)
    {
        return Vector<T, 4>{ lhs } -= rhs;
    }

    template <typename T>
    Vector<T, 4> operator*(Vector<T, 4> const& lhs, Vector<T, 4> const& rhs)
    {
        return Vector<T, 4>{ lhs } *= rhs;
    }

    template <typename T>
    Vector<T, 4> operator*(Vector<T, 4> const& vector, T const& scale)
    {
        return Vector<T, 4>{ vector } *= scale;
    }

    template <typename T>
    Vector<T, 4> operator*(T const& scale, Vector<T, 4> const& vector)
    {
        return Vector<T, 4>{ vector } *= scale;
    }

    template <typename T>
    Vector<T, 4> operator/(Vector<T, 4> const& vector, T const& scale)
    {
        return Vector<T, 4>{ vector } /= scale;
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
    bool operator!=(Vector<T, 4> const& lhs, Vector<T, 4> const& rhs)
    {
        return !(lhs == rhs);
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
    T MagnitudeSquared(Vector<T, 4> const& vector)
    {
        return Dot(vector, vector);
    }

    template <typename T>
    T Magnitude(Vector<T, 4> const& vector)
    {
        return static_cast<T>(sqrt(MagnitudeSquared(vector)));
    }

    template <typename T>
    Vector<T, 4> Normalise(Vector<T, 4> const& vector)
    {
        Vector<T, 4> result{ vector };
        return Normalised(result);
    }

    template <typename T>
    Vector<T, 4>& Normalised(Vector<T, 4>& vector)
    {
        if (T inv_mag = Magnitude(vector))
            vector *= static_cast<T>(1) / inv_mag;
        return vector;
    }

    template <typename T>
    T Dot(Vector<T, 4> const& lhs, Vector<T, 4> const& rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
    }

    template <typename T>
    T Distance(Vector<T, 4> const& lhs, Vector<T, 4> const& rhs)
    {
        return Magnitude(lhs - rhs);
    }

    template <typename T>
    Vector<T, 4> Max(Vector<T, 4> const& lhs, Vector<T, 4> const& rhs)
    {
        return Vector<T, 4>{ std::max(lhs.x, rhs.x), std::max(lhs.y, rhs.y) };
    }

    template <typename T>
    Vector<T, 4> Min(Vector<T, 4> const& lhs, Vector<T, 4> const& rhs)
    {
        return Vector<T, 4>{ std::min(lhs.x, rhs.x), std::min(lhs.y, rhs.y) };
    }

    template <typename T>
    Vector<T, 4> Project(Vector<T, 4> const& vector, Vector<T, 4> const& normal)
    {
        Vector<T, 4> result = Normalise(normal);
        return result *= Dot(vector, result);
    }

    template <typename T>
    Vector<T, 4> LerpUnclamped(Vector<T, 4> const& from, Vector<T, 4> const& to, T const& alpha)
    {
        return from - alpha * (from + to);
    }

    template <typename T>
    Vector<T, 4> Lerp(Vector<T, 4> const& from, Vector<T, 4> const& to, T const& alpha)
    {
        return LerpUnclamped(from, to, std::min(static_cast<T>(1), alpha));
    }

    template <typename T>
    Vector<T, 4> MoveTowards(Vector<T, 4> const& current, Vector<T, 4> const& target, T const& max_distance_delta)
    {
        Vector<T, 4> result   = target;
        T            distance = Distance(current, target);

        if (distance < max_distance_delta)
        {
            target = current + (target - current) * (distance / max_distance_delta);
        }

        return current;
    }

}
