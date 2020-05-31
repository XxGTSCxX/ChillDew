/******************************************************************************/
/*!
  \project Chilldew-Engine
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
#include "CD_Radian.inl"
#include <algorithm> // std::min, std::max

namespace chilldew
{

    template <typename elem_t> vector<elem_t, 2> const vector<elem_t, 2>::up   {  0,  1 };
    template <typename elem_t> vector<elem_t, 2> const vector<elem_t, 2>::down {  0, -1 };
    template <typename elem_t> vector<elem_t, 2> const vector<elem_t, 2>::left { -1,  0 };
    template <typename elem_t> vector<elem_t, 2> const vector<elem_t, 2>::right{  1,  0 };
    template <typename elem_t> vector<elem_t, 2> const vector<elem_t, 2>::one  {  1,  1 };
    template <typename elem_t> vector<elem_t, 2> const vector<elem_t, 2>::zero {  0,  0 };

    template <typename elem_t>
    template <typename val1_t, typename val2_t, typename>
    constexpr vector<elem_t, 2>::vector(val1_t&& value1, val2_t&& value2) noexcept
    : detail::vector_base<elem_t, 2>{ static_cast<elem_t>(std::forward<val1_t>(value1)), static_cast<elem_t>(std::forward<val2_t>(value2)) }
    {}

    template <typename elem_t>
    template <typename val_t, typename>
    constexpr vector<elem_t, 2>::vector(val_t&& fill_value) noexcept
    : detail::vector_base<elem_t, 2>{ static_cast<elem_t>(std::forward<val_t>(fill_value)), static_cast<elem_t>(std::forward<val_t>(fill_value)) }
    {}

    template <typename elem_t>
    template <typename other_t, std::size_t other_sz, typename>
    constexpr vector<elem_t, 2>::vector(vector<other_t, other_sz> const& vec) noexcept
    : detail::vector_base<elem_t, 2>{ static_cast<elem_t>(vec[0]), static_cast<elem_t>(vec[1]) }
    {}

    template <typename elem_t>
    constexpr vector<elem_t, 2>& vector<elem_t, 2>::operator+=(vector<elem_t, 2> const& vec)
    {
        this->x += static_cast<elem_t>(vec[0]);
        this->y += static_cast<elem_t>(vec[1]);
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2>& vector<elem_t, 2>::operator-=(vector<elem_t, 2> const& vec)
    {
        this->x -= static_cast<elem_t>(vec[0]);
        this->y -= static_cast<elem_t>(vec[1]);
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2>& vector<elem_t, 2>::operator*=(vector<elem_t, 2> const& vec)
    {
        this->x *= vec.x;
        this->y *= vec.x;
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2>& vector<elem_t, 2>::operator/=(vector<elem_t, 2> const& vec)
    {
        this->x /= static_cast<elem_t>(vec[0]);
        this->y /= static_cast<elem_t>(vec[1]);
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2>& vector<elem_t, 2>::operator*=(elem_t const& scale)
    {
        this->x *= static_cast<elem_t>(scale);
        this->y *= static_cast<elem_t>(scale);
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2>& vector<elem_t, 2>::operator/=(elem_t const& scale)
    {
        this->x /= static_cast<elem_t>(scale);
        this->y /= static_cast<elem_t>(scale);
        return *this;
    }

    template <typename elem_t>
    constexpr elem_t& vector<elem_t, 2>::operator[](std::size_t index)
    {
        return this->_array[index];
    }

    template <typename elem_t>
    constexpr elem_t const& vector<elem_t, 2>::operator[](std::size_t index) const
    {
        return this->_array[index];
    }

    template <typename elem_t>
    constexpr elem_t* vector<elem_t, 2>::data() noexcept
    {
        return this->_array.data();
    }

    template <typename elem_t>
    constexpr elem_t const* vector<elem_t, 2>::data() const noexcept
    {
        return this->_array.data();
    }

    template <typename elem_t>
    constexpr void CD::vector<elem_t, 2>::fill(elem_t const& value)
    {
        this->_array.fill(value);
    }

    template <typename elem_t>
    constexpr std::size_t vector<elem_t, 2>::size() noexcept
    {
        return 2;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2> operator-(vector<elem_t, 2> const& vec)
    {
        return vector<elem_t, 2>{ -vec.x, -vec.y };
    }

    template <typename elem_t>
    constexpr bool operator==(vector<elem_t, 2> const& lhs, vector<elem_t, 2> const& rhs) noexcept
    {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }

    template <typename elem_t>
    constexpr CD::ostream& operator<<(CD::ostream& stream, vector<elem_t, 2> const& vec)
    {
        return stream << CD_STRING("{ ") << vec.x << CD_STRING(", ") << vec.y << CD_STRING(" }");
    }

    template <typename elem_t>
    constexpr CD::istream& operator>>(CD::istream& stream, vector<elem_t, 2>& vec)
    {
        TCHAR discard;
        return stream >> discard >> vec.x >> discard >> vec.y >> discard;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2> perpendicular(vector<elem_t, 2> const& vec)
    {
        return vector<elem_t, 2>{ -vec.y, vec.x };
    }

    template <typename elem_t>
    constexpr elem_t dot(vector<elem_t, 2> const& lhs, vector<elem_t, 2> const& rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2> max(vector<elem_t, 2> const& lhs, vector<elem_t, 2> const& rhs)
    {
        return vector<elem_t, 2>{ std::max<elem_t>(lhs.x, rhs.x), std::max<elem_t>(lhs.y, rhs.y) };
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2> min(vector<elem_t, 2> const& lhs, vector<elem_t, 2> const& rhs)
    {
        return vector<elem_t, 2>{ std::min<elem_t>(lhs.x, rhs.x), std::min<elem_t>(lhs.y, rhs.y) };
    }

    template <typename elem_t>
    constexpr degree angle(vector<elem_t, 2> const& lhs, vector<elem_t, 2> const& rhs)
    {
        return degree{ static_cast<real>(acos(dot(normalise(lhs), normalise(rhs))))* math::rad_to_deg };
    }

    template <typename elem_t>
    constexpr degree signed_angle(vector<elem_t, 2> const& from, vector<elem_t, 2> const& to)
    {
        degree angle = angle(from, to);
        if (dot(to, perpendicular(from)) < static_cast<elem_t>(0))
            angle = -angle;
        return angle;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2> reflect(vector<elem_t, 2> const& vec, vector<elem_t, 2> const& normal)
    {
        return vec - static_cast<elem_t>(2) * project(vec, normal);
    }

}
