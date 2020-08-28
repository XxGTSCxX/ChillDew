/******************************************************************************/
/*!
  \project Chilldew-Math
  \file    cdm_vec2.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Partial vector specialisation for 2D vector implementation.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cdm_vec2.h"
#include <algorithm> // std::min, std::max

namespace chilldew::math
{

    template <typename elem_t> vector<elem_t, 2> const vector<elem_t, 2>::up   {  0,  1 };
    template <typename elem_t> vector<elem_t, 2> const vector<elem_t, 2>::down {  0, -1 };
    template <typename elem_t> vector<elem_t, 2> const vector<elem_t, 2>::left { -1,  0 };
    template <typename elem_t> vector<elem_t, 2> const vector<elem_t, 2>::right{  1,  0 };
    template <typename elem_t> vector<elem_t, 2> const vector<elem_t, 2>::one  {  1,  1 };
    template <typename elem_t> vector<elem_t, 2> const vector<elem_t, 2>::zero {  0,  0 };

    template <typename elem_t>
    constexpr vector<elem_t, 2>::vector(elem_t const& fill_value)
    : detail::vector_base<elem_t, 2>
    {
          fill_value
        , fill_value
    }
    {}

    template <typename elem_t>
    template <typename val1_t, typename val2_t, typename>
    constexpr vector<elem_t, 2>::vector(val1_t&& val1, val2_t&& val2)
    : detail::vector_base<elem_t, 2>
    {
          static_cast<elem_t>(std::forward<val1_t>(val1))
        , static_cast<elem_t>(std::forward<val2_t>(val2))
    }
    {}

    template <typename  elem_t>
    template <typename _elem_t, std::size_t _size_v, typename>
    constexpr vector<elem_t, 2>::vector(vector<_elem_t, _size_v> const& vec)
    : detail::vector_base<elem_t, 2>
    {
          static_cast<elem_t>(vec[0])
        , static_cast<elem_t>(vec[1])
    }
    {}

    template <typename elem_t>
    constexpr vector<elem_t, 2>& vector<elem_t, 2>::operator+=(vector<elem_t, 2> const& vec)
    {
        this->_data[0] += vec[0];
        this->_data[1] += vec[1];
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2>& vector<elem_t, 2>::operator-=(vector<elem_t, 2> const& vec)
    {
        this->_data[0] -= vec[0];
        this->_data[1] -= vec[1];
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2>& vector<elem_t, 2>::operator*=(vector<elem_t, 2> const& vec)
    {
        this->_data[0] *= vec[0];
        this->_data[1] *= vec[1];
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2>& vector<elem_t, 2>::operator/=(vector<elem_t, 2> const& vec)
    {
        this->_data[0] /= vec[0];
        this->_data[1] /= vec[1];
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2>& vector<elem_t, 2>::operator*=(elem_t const& scale)
    {
        this->_data[0] *= scale;
        this->_data[1] *= scale;
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2>& vector<elem_t, 2>::operator/=(elem_t const& scale)
    {
        this->_data[0] /= scale;
        this->_data[1] /= scale;
        return *this;
    }

    template <typename elem_t>
    constexpr elem_t& vector<elem_t, 2>::operator[](std::size_t index)
    {
        return this->_data[index];
    }

    template <typename elem_t>
    constexpr elem_t const& vector<elem_t, 2>::operator[](std::size_t index) const
    {
        return this->_data[index];
    }

    template <typename elem_t>
    constexpr elem_t* vector<elem_t, 2>::data() noexcept
    {
        return this->_data;
    }

    template <typename elem_t>
    constexpr elem_t const* vector<elem_t, 2>::data() const noexcept
    {
        return this->_data;
    }

    template <typename elem_t>
    void vector<elem_t, 2>::fill(elem_t const& value)
    {
        this->_data[0] = value;
        this->_data[1] = value;
    }

    template <typename elem_t>
    constexpr std::size_t vector<elem_t, 2>::size() noexcept
    {
        return 2;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2> operator-(vector<elem_t, 2> const& vec)
    {
        return vector<elem_t, 2>{ -vec[0], -vec[1] };
    }

    template <typename elem_t>
    constexpr bool operator==(vector<elem_t, 2> const& lhs, vector<elem_t, 2> const& rhs) noexcept
    {
        return lhs[0] == rhs[0] && lhs[1] == rhs[1];
    }

    template <typename elem_t>
    constexpr cd::ostream& operator<<(cd::ostream& stream, vector<elem_t, 2> const& vec)
    {
        return stream << CD_L("{ ") << vec[0] << CD_L(", ") << vec[1] << CD_L(" }");
    }

    template <typename elem_t>
    constexpr cd::istream& operator>>(cd::istream& stream, vector<elem_t, 2>& vec)
    {
        TCHAR discard;
        return stream >> discard >> vec[0] >> discard >> vec[1] >> discard;
    }

    template <typename elem_t>
    constexpr elem_t dot(vector<elem_t, 2> const& lhs, vector<elem_t, 2> const& rhs)
    {
        return lhs[0] * rhs[0] + lhs[1] * rhs[1];
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2> min(vector<elem_t, 2> const& lhs, vector<elem_t, 2> const& rhs)
    {
        return vector<elem_t, 2>{ std::min(lhs[0], rhs[0])
                                , std::min(lhs[1], rhs[1]) };
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2> max(vector<elem_t, 2> const& lhs, vector<elem_t, 2> const& rhs)
    {
        return vector<elem_t, 2>{ std::max(lhs[0], rhs[0])
                                , std::max(lhs[1], rhs[1]) };
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2> cw_perp(vector<elem_t, 2> const& vec)
    {
        return vector<elem_t, 2>{ vec.y, -vec.x };
    }

    template <typename elem_t>
    constexpr vector<elem_t, 2> ccw_perp(vector<elem_t, 2> const& vec)
    {
        return vector<elem_t, 2>{ -vec.y, vec.x };
    }

    template<typename elem_t>
    constexpr radian signed_angle(vector<elem_t, 2> const& from, vector<elem_t, 2> const& to)
    {
        return cdm::dot(cdm::ccw_perp(from), to) < static_cast<elem_t>(0) ? -cdm::angle(from, to) : cdm::angle(from, to);
    }

}
