/******************************************************************************/
/*!
  \project Chilldew-Math
  \file    CD_Vector3D.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    General 3D vector implementation.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cdm_vec3.h"
#include <algorithm> // std::min, std::max

namespace chilldew::math
{

    template <typename elem_t> vector<elem_t, 3> const vector<elem_t, 3>::up     {  0,  1,  0 };
    template <typename elem_t> vector<elem_t, 3> const vector<elem_t, 3>::down   {  0, -1,  0 };
    template <typename elem_t> vector<elem_t, 3> const vector<elem_t, 3>::left   { -1,  0,  0 };
    template <typename elem_t> vector<elem_t, 3> const vector<elem_t, 3>::right  {  1,  0,  0 };
    template <typename elem_t> vector<elem_t, 3> const vector<elem_t, 3>::forward{  0,  0,  1 };
    template <typename elem_t> vector<elem_t, 3> const vector<elem_t, 3>::back   {  0,  0, -1 };
    template <typename elem_t> vector<elem_t, 3> const vector<elem_t, 3>::one    {  1,  1,  1 };
    template <typename elem_t> vector<elem_t, 3> const vector<elem_t, 3>::zero   {  0,  0,  0 };

    template <typename elem_t>
    constexpr vector<elem_t, 3>::vector(elem_t const& fill_value)
    : detail::vector_base<elem_t, 3>
    {
          fill_value
        , fill_value
        , fill_value
    }
    {}

    template <typename elem_t>
    template <typename val1_t, typename val2_t, typename val3_t, typename>
    constexpr vector<elem_t, 3>::vector(val1_t&& val1, val2_t&& val2, val3_t&& val3)
    : detail::vector_base<elem_t, 3>
    {
          static_cast<elem_t>(std::forward<val1_t>(val1))
        , static_cast<elem_t>(std::forward<val2_t>(val2))
        , static_cast<elem_t>(std::forward<val3_t>(val3))
    }
    {}

    template <typename  elem_t>
    template <typename _elem_t, std::size_t _size_v, typename>
    constexpr vector<elem_t, 3>::vector(vector<_elem_t, _size_v> const& vec)
    : detail::vector_base<elem_t, 3>
    {
          static_cast<elem_t>(vec[0])
        , static_cast<elem_t>(vec[1])
        , static_cast<elem_t>(vec[2])
    }
    {}

    template <typename elem_t>
    constexpr vector<elem_t, 3>& vector<elem_t, 3>::operator+=(vector<elem_t, 3> const& vec)
    {
        this->_data[0] += vec[0];
        this->_data[1] += vec[1];
        this->_data[2] += vec[2];
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 3>& vector<elem_t, 3>::operator-=(vector<elem_t, 3> const& vec)
    {
        this->_data[0] -= vec[0];
        this->_data[1] -= vec[1];
        this->_data[2] -= vec[2];
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 3>& vector<elem_t, 3>::operator*=(vector<elem_t, 3> const& vec)
    {
        this->_data[0] *= vec[0];
        this->_data[1] *= vec[1];
        this->_data[2] *= vec[2];
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 3>& vector<elem_t, 3>::operator/=(vector<elem_t, 3> const& vec)
    {
        this->_data[0] /= vec[0];
        this->_data[1] /= vec[1];
        this->_data[2] /= vec[2];
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 3>& vector<elem_t, 3>::operator*=(elem_t const& scale)
    {
        this->_data[0] *= scale;
        this->_data[1] *= scale;
        this->_data[2] *= scale;
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 3>& vector<elem_t, 3>::operator/=(elem_t const& scale)
    {
        this->_data[0] /= scale;
        this->_data[1] /= scale;
        this->_data[2] /= scale;
        return *this;
    }

    template <typename elem_t>
    constexpr elem_t& vector<elem_t, 3>::operator[](std::size_t index)
    {
        return this->_data[index];
    }

    template <typename elem_t>
    constexpr elem_t const& vector<elem_t, 3>::operator[](std::size_t index) const
    {
        return this->_data[index];
    }

    template <typename elem_t>
    constexpr elem_t* vector<elem_t, 3>::data() noexcept
    {
        return this->_data;
    }

    template <typename elem_t>
    constexpr elem_t const* vector<elem_t, 3>::data() const noexcept
    {
        return this->_data;
    }

    template <typename elem_t>
    void vector<elem_t, 3>::fill(elem_t const& value)
    {
        this->_data[0] = value;
        this->_data[1] = value;
        this->_data[2] = value;
    }

    template <typename elem_t>
    constexpr std::size_t vector<elem_t, 3>::size() noexcept
    {
        return 3;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 3> operator-(vector<elem_t, 3> const& vec)
    {
        return vector<elem_t, 3>{ -vec[0], -vec[1], -vec[2] };
    }

    template <typename elem_t>
    constexpr bool operator==(vector<elem_t, 3> const& lhs, vector<elem_t, 3> const& rhs) noexcept
    {
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
    }

    template <typename elem_t>
    constexpr cd::ostream& operator<<(cd::ostream& stream, vector<elem_t, 3> const& vec)
    {
        return stream << CD_STRING("{ ") << vec[0] << CD_STRING(", ") << vec[1] << CD_STRING(", ") << vec[2] << CD_STRING(" }");
    }

    template <typename elem_t>
    constexpr cd::istream& operator>>(cd::istream& stream, vector<elem_t, 3>& vec)
    {
        TCHAR discard;
        return stream >> discard >> vec[0] >> discard >> vec[1] >> discard >> vec[2] >> discard;
    }

    template <typename elem_t>
    constexpr elem_t dot(vector<elem_t, 3> const& lhs, vector<elem_t, 3> const& rhs)
    {
        return lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2];
    }

    template <typename elem_t>
    constexpr vector<elem_t, 3> min(vector<elem_t, 3> const& lhs, vector<elem_t, 3> const& rhs)
    {
        return vector<elem_t, 3>{ std::min(lhs[0], rhs[0])
                                , std::min(lhs[1], rhs[1])
                                , std::min(lhs[2], rhs[2]) };
    }

    template <typename elem_t>
    constexpr vector<elem_t, 3> max(vector<elem_t, 3> const& lhs, vector<elem_t, 3> const& rhs)
    {
        return vector<elem_t, 3>{ std::max(lhs[0], rhs[0])
                                , std::max(lhs[1], rhs[1])
                                , std::max(lhs[2], rhs[2]) };
    }

    template<typename elem_t>
    constexpr vector<elem_t, 3> cross(vector<elem_t, 3> const& from, vector<elem_t, 3> const& to)
    {
        return vector<elem_t, 3>{ from.y * to.z - from.z * to.y
                                , from.z * to.x - from.x * to.z
                                , from.x * to.y - from.y * to.x };
    }

    template<typename elem_t>
    constexpr vector<elem_t, 3> cw_perp(vector<elem_t, 3> const& vec, vector<elem_t, 3> const& normal)
    {
        return cross(normal, vec);
    }

    template<typename elem_t>
    constexpr vector<elem_t, 3> ccw_perp(vector<elem_t, 3> const& vec, vector<elem_t, 3> const& normal)
    {
        return cross(vec, normal);
    }

}
