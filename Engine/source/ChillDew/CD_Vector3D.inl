/******************************************************************************/
/*!
  \project ChillDew-Engine
  \file    CD_Vector3D.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    General 3D vector implementation.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Vector3D.h"
#include "CD_Degree.inl"
#include <algorithm> // std::min, std::max

namespace CD
{

    template <typename T>
    template <typename ... Params, typename>
    inline constexpr VectorData<T, 3>::VectorData(Params&& ...args) noexcept
    : _array{ static_cast<T>(args)... }
    {}

    template <typename T> Vector<T, 3> const Vector<T, 3>::up     {  0,  1,  0 };
    template <typename T> Vector<T, 3> const Vector<T, 3>::down   {  0, -1,  0 };
    template <typename T> Vector<T, 3> const Vector<T, 3>::left   { -1,  0,  0 };
    template <typename T> Vector<T, 3> const Vector<T, 3>::right  {  1,  0,  0 };
    template <typename T> Vector<T, 3> const Vector<T, 3>::forward{  0,  0,  1 };
    template <typename T> Vector<T, 3> const Vector<T, 3>::back   {  0,  0, -1 };
    template <typename T> Vector<T, 3> const Vector<T, 3>::one    {  1,  1,  1 };
    template <typename T> Vector<T, 3> const Vector<T, 3>::zero   {  0,  0,  0 };

    template <typename T>
    template <typename U, typename V, typename W, typename>
    inline constexpr Vector<T, 3>::Vector(U&& x, V&& y, W&& z) noexcept
    : VectorData<T, 3>{ static_cast<T>(x), static_cast<T>(y), static_cast<T>(z) }
    {}

    template <typename T>
    template <typename U, typename>
    inline constexpr Vector<T, 3>::Vector(U&& fill_value) noexcept
    : VectorData<T, 3>{ static_cast<T>(fill_value), static_cast<T>(fill_value), static_cast<T>(fill_value) }
    {}

    template <typename T>
    template <typename U, typename>
    inline constexpr Vector<T, 3>::Vector(Vector<U, 1> const& vector) noexcept
    : VectorData<T, 3>{ static_cast<T>(vector[0]) }
    {}

    template <typename T>
    template <typename U, typename>
    inline constexpr Vector<T, 3>::Vector(Vector<U, 2> const& vector) noexcept
    : VectorData<T, 3>{ static_cast<T>(vector[0]), static_cast<T>(vector[1]) }
    {}

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline constexpr Vector<T, 3>::Vector(Vector<U, U_SZ> const& vector) noexcept
    : VectorData<T, 3>{ static_cast<T>(vector[0]), static_cast<T>(vector[1]), static_cast<T>(vector[2]) }
    {}

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline Vector<T, 3>& Vector<T, 3>::operator=(Vector<U, U_SZ> const& vector)
    {
        switch (U_SZ)
        {
        default: z = static_cast<T>(vector[2]);
        case 2 : y = static_cast<T>(vector[1]);
        case 1 : x = static_cast<T>(vector[0]);
        }
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
            x = y = z = std::numeric_limits<T>::infinity();
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
    inline void CD::Vector<T, 3>::fill(T const& value)
    {
        _array.fill(value);
    }

    template <typename T>
    inline constexpr size_t Vector<T, 3>::size()
    {
        return 3;
    }

    template <typename T>
    Vector<T, 3> operator-(Vector<T, 3> const& vector)
    {
        return Vector<T, 3>{ -vector.x, -vector.y, -vector.z };
    }

    template <typename T>
    bool operator==(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs)
    {
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
    }

    template <typename T>
    CD::ostream& operator<<(CD::ostream& stream, Vector<T, 3> const& vector)
    {
        return stream << CD_STRING("{ ") << vector.x << CD_STRING(", ") << vector.y << CD_STRING(", ") << vector.z << CD_STRING(" }");
    }

    template <typename T>
    CD::istream& operator>>(CD::istream& stream, Vector<T, 3>& vector)
    {
        TCHAR discard;
        return stream >> discard >> vector.x >> discard >> vector.y >> discard >> vector.z >> discard;
    }

    template <typename T>
    T Dot(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    template <typename T>
    Vector<T, 3> Max(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs)
    {
        return Vector<T, 3>{ std::max<T>(lhs.x, rhs.x), std::max<T>(lhs.y, rhs.y), std::max<T>(lhs.z, rhs.z) };
    }

    template <typename T>
    Vector<T, 3> Min(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs)
    {
        return Vector<T, 3>{ std::min<T>(lhs.x, rhs.x), std::min<T>(lhs.y, rhs.y), std::min<T>(lhs.z, rhs.z) };
    }

    template <typename T>
    Degree Angle(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs)
    {
        return Degree{ static_cast<Real>(acos(Dot(Normalise(lhs), Normalise(rhs)))) * Math::RAD_TO_DEG };
    }

    template <typename T>
    Degree SignedAngle(Vector<T, 3> const& from, Vector<T, 3> const& to)
    {
        Degree angle = Angle(from, to);
        if (Dot(to, Perpendicular(from)) < static_cast<T>(0))
            angle = -angle;
        return angle;
    }

    template <typename T>
    Vector<T, 3> Reflect(Vector<T, 3> const& vector, Vector<T, 3> const& normal)
    {
        return vector - static_cast<T>(2) * Project(vector, normal);
    }

    template <typename T>
    Vector<T, 3> Cross(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs)
    {
        return Vector<T, 3>{ lhs.y * rhs.z - lhs.z * rhs.y
                           , lhs.z * rhs.x - lhs.x * rhs.z
                           , lhs.x * rhs.y - lhs.y * rhs.x };
    }

    template <typename T>
    Vector<T, 3> ProjectOnPlane(Vector<T, 3> const& vector, Vector<T, 3> const& normal)
    {
        return vector - Project(vector, normal);;
    }

    template <typename T>
    void OrthoNormalise(Vector<T, 3>& normal, Vector<T, 3>& tangent)
    {
        Normalized(normal );
        Normalized(tangent);

        tangent = Cross(normal, Cross(normal, tangent));
    }

    template <typename T>
    Vector<T, 3> RotateTowards(Vector<T, 3> const& current, Vector<T, 3> const& target, Radian max_angle_delta, T const& max_magnitude_delta)
    {
        // TODO: Implement this once Quaternions is done(?)
        return Vector<T, 3>();
    }

}
