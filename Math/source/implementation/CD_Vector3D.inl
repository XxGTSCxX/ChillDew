/******************************************************************************/
/*!
  \project Chilldew-Engine
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

namespace chilldew
{

    template <typename T> vector<T, 3> const vector<T, 3>::up     {  0,  1,  0 };
    template <typename T> vector<T, 3> const vector<T, 3>::down   {  0, -1,  0 };
    template <typename T> vector<T, 3> const vector<T, 3>::left   { -1,  0,  0 };
    template <typename T> vector<T, 3> const vector<T, 3>::right  {  1,  0,  0 };
    template <typename T> vector<T, 3> const vector<T, 3>::forward{  0,  0,  1 };
    template <typename T> vector<T, 3> const vector<T, 3>::back   {  0,  0, -1 };
    template <typename T> vector<T, 3> const vector<T, 3>::one    {  1,  1,  1 };
    template <typename T> vector<T, 3> const vector<T, 3>::zero   {  0,  0,  0 };

    template <typename T>
    template <typename X, typename Y, typename Z, typename>
    inline constexpr vector<T, 3>::vector(X&& x, Y&& y, Z&& z) noexcept
    : detail::vector_base<T, 3>{ std::forward<X>(x), std::forward<Y>(y), std::forward<Z>(z) }
    {}

    template <typename T>
    template <typename U, typename>
    inline constexpr vector<T, 3>::vector(U&& fill_value) noexcept
    : detail::vector_base<T, 3>{ std::forward<U>(fill_value), std::forward<U>(fill_value), std::forward<U>(fill_value) }
    {}

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline constexpr vector<T, 3>::vector(vector<U, U_SZ> const& vec) noexcept
    : detail::vector_base<T, 3>{ vec[0], vec[1], vec[2] }
    {}

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline vector<T, 3>& vector<T, 3>::operator=(vector<U, U_SZ> const& vec)
    {
        this->x = static_cast<T>(vec[0]);
        this->y = static_cast<T>(vec[1]);
        this->z = static_cast<T>(vec[2]);
        return *this;
    }

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline vector<T, 3>& vector<T, 3>::operator+=(vector<U, U_SZ> const& vec)
    {
        this->x += static_cast<T>(vec.x);
        this->y += static_cast<T>(vec.y);
        this->z += static_cast<T>(vec.z);
        return *this;
    }

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline vector<T, 3>& vector<T, 3>::operator-=(vector<U, U_SZ> const& vec)
    {
        this->x -= static_cast<T>(vec.x);
        this->y -= static_cast<T>(vec.y);
        this->z -= static_cast<T>(vec.z);
        return *this;
    }

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline vector<T, 3>& vector<T, 3>::operator*=(vector<U, U_SZ> const& vec)
    {
        this->x *= static_cast<T>(vec.x);
        this->y *= static_cast<T>(vec.y);
        this->z *= static_cast<T>(vec.z);
        return *this;
    }

    template <typename T>
    template <typename U, size_t U_SZ, typename>
    inline vector<T, 3>& vector<T, 3>::operator/=(vector<U, U_SZ> const& vec)
    {
        this->x /= static_cast<T>(vec.x);
        this->y /= static_cast<T>(vec.y);
        this->z /= static_cast<T>(vec.z);
        return *this;
    }

    template <typename T>
    template <typename U, typename>
    inline vector<T, 3>& vector<T, 3>::operator*=(U const& scale)
    {
        this->x *= static_cast<T>(scale);
        this->y *= static_cast<T>(scale);
        this->z *= static_cast<T>(scale);
        return *this;
    }

    template <typename T>
    template <typename U, typename>
    inline vector<T, 3>& vector<T, 3>::operator/=(U const& scale)
    {
        this->x /= static_cast<T>(scale);
        this->y /= static_cast<T>(scale);
        this->z /= static_cast<T>(scale);
        return *this;
    }

    template <typename T>
    inline T& vector<T, 3>::operator[](size_t index)
    {
        return this->_array[index];
    }

    template <typename T>
    inline T const& vector<T, 3>::operator[](size_t index) const
    {
        return this->_array[index];
    }

    template <typename T>
    inline T* vector<T, 3>::data()
    {
        return this->_array.data();
    }

    template <typename T>
    inline T const* vector<T, 3>::data() const
    {
        return this->_array.data();
    }

    template <typename T>
    inline void CD::vector<T, 3>::fill(T const& value)
    {
        this->_array.fill(value);
    }

    template <typename T>
    inline constexpr size_t vector<T, 3>::size()
    {
        return 3;
    }

    template <typename T>
    vector<T, 3> operator-(vector<T, 3> const& vec)
    {
        return vector<T, 3>{ -vec.x, -vec.y, -vec.z };
    }

    template <typename T>
    bool operator==(vector<T, 3> const& lhs, vector<T, 3> const& rhs)
    {
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
    }

    template <typename T>
    CD::ostream& operator<<(CD::ostream& stream, vector<T, 3> const& vec)
    {
        return stream << CD_STRING("{ ") << vec.x << CD_STRING(", ") << vec.y << CD_STRING(", ") << vec.z << CD_STRING(" }");
    }

    template <typename T>
    CD::istream& operator>>(CD::istream& stream, vector<T, 3>& vec)
    {
        TCHAR discard;
        return stream >> discard >> vec.x >> discard >> vec.y >> discard >> vec.z >> discard;
    }

    template <typename T>
    T Dot(vector<T, 3> const& lhs, vector<T, 3> const& rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    template <typename T>
    vector<T, 3> Max(vector<T, 3> const& lhs, vector<T, 3> const& rhs)
    {
        return vector<T, 3>{ std::max<T>(lhs.x, rhs.x), std::max<T>(lhs.y, rhs.y), std::max<T>(lhs.z, rhs.z) };
    }

    template <typename T>
    vector<T, 3> Min(vector<T, 3> const& lhs, vector<T, 3> const& rhs)
    {
        return vector<T, 3>{ std::min<T>(lhs.x, rhs.x), std::min<T>(lhs.y, rhs.y), std::min<T>(lhs.z, rhs.z) };
    }

    template <typename T>
    degree Angle(vector<T, 3> const& lhs, vector<T, 3> const& rhs)
    {
        return degree{ static_cast<real>(acos(Dot(Normalise(lhs), Normalise(rhs)))) * math::rad_to_deg };
    }

    template <typename T>
    degree SignedAngle(vector<T, 3> const& from, vector<T, 3> const& to)
    {
        degree angle = Angle(from, to);
        if (Dot(to, Perpendicular(from)) < static_cast<T>(0))
            angle = -angle;
        return angle;
    }

    template <typename T>
    vector<T, 3> Reflect(vector<T, 3> const& vec, vector<T, 3> const& normal)
    {
        return vec - static_cast<T>(2) * Project(vec, normal);
    }

    template <typename T>
    vector<T, 3> Cross(vector<T, 3> const& lhs, vector<T, 3> const& rhs)
    {
        return vector<T, 3>{ lhs.y * rhs.z - lhs.z * rhs.y
                           , lhs.z * rhs.x - lhs.x * rhs.z
                           , lhs.x * rhs.y - lhs.y * rhs.x };
    }

    template <typename T>
    vector<T, 3> ProjectOnPlane(vector<T, 3> const& vec, vector<T, 3> const& normal)
    {
        return vec - Project(vec, normal);;
    }

    template <typename T>
    void OrthoNormalise(vector<T, 3>& normal, vector<T, 3>& tangent)
    {
        Normalized(normal );
        Normalized(tangent);

        tangent = Cross(normal, Cross(normal, tangent));
    }

    template <typename T>
    vector<T, 3> RotateTowards(vector<T, 3> const& current, vector<T, 3> const& target, radian max_angle_delta, T const& max_magnitude_delta)
    {
        // TODO: Implement this once Quaternions is done(?)
        return vector<T, 3>();
    }

}
