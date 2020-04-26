/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Vector3D.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    General 3D vector implementation.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Vector3D.h"
#include "GTE_Degree.inl"

namespace GTE
{

    template <typename T> Vector<T, 3> const Vector<T, 3>::up     {  0,  1,  0 };
    template <typename T> Vector<T, 3> const Vector<T, 3>::down   {  0, -1,  0 };
    template <typename T> Vector<T, 3> const Vector<T, 3>::left   { -1,  0,  0 };
    template <typename T> Vector<T, 3> const Vector<T, 3>::right  {  1,  0,  0 };
    template <typename T> Vector<T, 3> const Vector<T, 3>::forward{  0,  0,  1 };
    template <typename T> Vector<T, 3> const Vector<T, 3>::back   {  0,  0, -1 };
    template <typename T> Vector<T, 3> const Vector<T, 3>::one    {  1,  1,  1 };
    template <typename T> Vector<T, 3> const Vector<T, 3>::zero   {  0,  0,  0 };

    template <typename T>
    template <typename ... Params, typename>
    inline constexpr Vector<T, 3>::Vector(Params&& ... args) noexcept
    : _array{ static_cast<T>(std::forward<Params>(args))... }
    {}

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline Vector<T, 3>::Vector(Vector<U, U_SZ> const& vector)
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
    inline Vector<T, 3>& Vector<T, 3>::operator=(Vector<U, U_SZ> const& vector)
    {
        new (this) Vector<T, 3>{ vector };
        return *this;
    }

    template <typename T>
    inline Vector<T, 3>& Vector<T, 3>::operator+=(Vector<T, 3> const& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    template <typename T>
    inline Vector<T, 3>& Vector<T, 3>::operator-=(Vector<T, 3> const& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    template <typename T>
    inline Vector<T, 3>& Vector<T, 3>::operator*=(Vector<T, 3> const& other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    template <typename T>
    inline Vector<T, 3>& Vector<T, 3>::operator*=(T const& scale)
    {
        x *= scale;
        y *= scale;
        z *= scale;
        return *this;
    }

    template <typename T>
    inline Vector<T, 3>& Vector<T, 3>::operator/=(T const& scale)
    {
        if (scale)
        {
            x /= scale;
            y /= scale;
            z /= scale;
        }
        else
        {
            x = std::numeric_limits<T>::infinity();
            y = std::numeric_limits<T>::infinity();
            z = std::numeric_limits<T>::infinity();
        }
        return *this;
    }

    template <typename T>
    inline T& Vector<T, 3>::operator[](size_t index)
    {
        return _array[index];
    }

    template <typename T>
    inline T const& Vector<T, 3>::operator[](size_t index) const
    {
        return _array[index];
    }

    template <typename T>
    inline T* Vector<T, 3>::data()
    {
        return _array.data();
    }

    template <typename T>
    inline T const* Vector<T, 3>::data() const
    {
        return _array.data();
    }

    template <typename T>
    inline void GTE::Vector<T, 3>::fill(T const& value)
    {
        _array.fill(value);
    }

    template <typename T>
    inline constexpr size_t Vector<T, 3>::size()
    {
        return 3;
    }

    template <typename T>
    Vector<T, 3> operator+(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs)
    {
        return Vector<T, 3>{ lhs } += rhs;
    }

    template <typename T>
    Vector<T, 3> operator-(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs)
    {
        return Vector<T, 3>{ lhs } -= rhs;
    }

    template <typename T>
    Vector<T, 3> operator*(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs)
    {
        return Vector<T, 3>{ lhs } *= rhs;
    }

    template <typename T>
    Vector<T, 3> operator*(Vector<T, 3> const& vector, T const& scale)
    {
        return Vector<T, 3>{ vector } *= scale;
    }

    template <typename T>
    Vector<T, 3> operator*(T const& scale, Vector<T, 3> const& vector)
    {
        return Vector<T, 3>{ vector } *= scale;
    }

    template <typename T>
    Vector<T, 3> operator/(Vector<T, 3> const& vector, T const& scale)
    {
        return Vector<T, 3>{ vector } /= scale;
    }

    template <typename T>
    Vector<T, 3> operator-(Vector<T, 3> const& vector)
    {
        return Vector<T, 3>{ -vector.x, -vector.y };
    }

    template <typename T>
    bool operator==(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs)
    {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }

    template <typename T>
    bool operator!=(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs)
    {
        return !(lhs == rhs);
    }

    template <typename T>
    GTE::ostream& operator<<(GTE::ostream& stream, Vector<T, 3> const& vector)
    {
        return stream << GTE_STRING("{ ") << vector.x << GTE_STRING(", ") << vector.y << GTE_STRING(", ") << vector.z << GTE_STRING(" }");
    }

    template <typename T>
    GTE::istream& operator>>(GTE::istream& stream, Vector<T, 3>& vector)
    {
        char discard;
        return stream >> discard >> vector.x >> discard >> vector.y >> discard >> vector.z >> discard;
    }

    template <typename T>
    T MagnitudeSquared(Vector<T, 3> const& vector)
    {
        return Dot(vector, vector);
    }

    template <typename T>
    T Magnitude(Vector<T, 3> const& vector)
    {
        return static_cast<T>(sqrt(MagnitudeSquared(vector)));
    }

    template <typename T>
    Vector<T, 3> Normalise(Vector<T, 3> const& vector)
    {
        Vector<T, 3> result{ vector };
        return Normalised(result);
    }

    template <typename T>
    Vector<T, 3>& Normalised(Vector<T, 3>& vector)
    {
        if (T inv_mag = Magnitude(vector))
            vector *= static_cast<T>(1) / inv_mag;
        return vector;
    }

    template <typename T>
    T Dot(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    template <typename T>
    Degree Angle(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs)
    {
        return Degree{ static_cast<Real>(acos(Dot(Normalise(lhs), Normalise(rhs)))) * Math::RAD_TO_DEG };
    }

    template <typename T>
    T Distance(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs)
    {
        return Magnitude(lhs - rhs);
    }

    template <typename T>
    Vector<T, 3> Max(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs)
    {
        return Vector<T, 3>{ std::max(lhs.x, rhs.x), std::max(lhs.y, rhs.y) };
    }

    template <typename T>
    Vector<T, 3> Min(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs)
    {
        return Vector<T, 3>{ std::min(lhs.x, rhs.x), std::min(lhs.y, rhs.y) };
    }

    template <typename T>
    Vector<T, 3> Project(Vector<T, 3> const& vector, Vector<T, 3> const& normal)
    {
        Vector<T, 3> result = Normalise(normal);
        return result *= Dot(vector, result);
    }

    template <typename T>
    Vector<T, 3> Reflect(Vector<T, 3> const& vector, Vector<T, 3> const& normal)
    {
        return vector - static_cast<T>(2) * Project(vector, normal);
    }

    template<typename T>
    Degree SignedAngle(Vector<T, 3> const& from, Vector<T, 3> const& to)
    {
        Degree angle = Angle(from, to);
        if (Dot(to, Perpendicular(from)) < static_cast<T>(0))
            angle = -angle;
        return angle;
    }

    template<typename T>
    Vector<T, 3> ClampMagnitude(Vector<T, 3> const& vector, T const& max_magnitude)
    {
        Vector<T, 3> result = vector;
        T            scale  = MagnitudeSquared(vector);

        if (scale > max_magnitude * max_magnitude)
        {
            scale   = max_magnitude / sqrt(scale);
            result *= scale;
        }

        return result;
    }

    template<typename T>
    Vector<T, 3> LerpUnclamped(Vector<T, 3> const& from, Vector<T, 3> const& to, T const& alpha)
    {
        return from - alpha * (from + to);
    }

    template<typename T>
    Vector<T, 3> Lerp(Vector<T, 3> const& from, Vector<T, 3> const& to, T const& alpha)
    {
        return LerpUnclamped(from, to, std::min(static_cast<T>(1), alpha));
    }

    template<typename T>
    Vector<T, 3> MoveTowards(Vector<T, 3> const& current, Vector<T, 3> const& target, T const& max_distance_delta)
    {
        Vector<T, 3> result   = target;
        T            distance = Distance(current, target);

        if (distance < max_distance_delta)
        {
            target = current + (target - current) * (distance / max_distance_delta);
        }

        return current;
    }

    template<typename T>
    Vector<T, 3> RotateTowards(Vector<T, 3> const& current, Vector<T, 3> const& target, Radian max_angle_delta, T const& max_magnitude_delta)
    {
        // TODO: Implement this once Quaternions is done(?)
        return Vector<T, 3>();
    }

}
