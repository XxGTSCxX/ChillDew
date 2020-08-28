/******************************************************************************/
/*!
  \project Chilldew-Math
  \file    CD_Vector4D.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    General 4D vector implementation.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cdm_vec4.h"

namespace chilldew::math
{

    template <typename elem_t> vector<elem_t, 4> const vector<elem_t, 4>::one {  1,  1,  1 };
    template <typename elem_t> vector<elem_t, 4> const vector<elem_t, 4>::zero{  0,  0,  0 };

    template <typename elem_t>
    constexpr vector<elem_t, 4>::vector(elem_t const& fill_value)
    : detail::vector_base<elem_t, 4>
    {
          fill_value
        , fill_value
        , fill_value
        , fill_value
    }
    {}

    template <typename elem_t>
    template <typename val1_t, typename val2_t, typename val3_t, typename val4_t, typename>
    constexpr vector<elem_t, 4>::vector(val1_t&& val1, val2_t&& val2, val3_t&& val3, val4_t&& val4)
    : detail::vector_base<elem_t, 4>
    {
          static_cast<elem_t>(std::forward<val1_t>(val1))
        , static_cast<elem_t>(std::forward<val2_t>(val2))
        , static_cast<elem_t>(std::forward<val3_t>(val3))
        , static_cast<elem_t>(std::forward<val4_t>(val4))
    }
    {}

    template <typename  elem_t>
    template <typename _elem_t, std::size_t _size_v, typename>
    constexpr vector<elem_t, 4>::vector(vector<_elem_t, _size_v> const& vec)
    : detail::vector_base<elem_t, 4>
    {
          static_cast<elem_t>(vec[0])
        , static_cast<elem_t>(vec[1])
        , static_cast<elem_t>(vec[2])
        , static_cast<elem_t>(vec[3])
    }
    {}

    template <typename elem_t>
    constexpr vector<elem_t, 4>& vector<elem_t, 4>::operator+=(vector<elem_t, 4> const& vec)
    {
        this->_data[0] += vec[0];
        this->_data[1] += vec[1];
        this->_data[2] += vec[2];
        this->_data[3] += vec[3];
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 4>& vector<elem_t, 4>::operator-=(vector<elem_t, 4> const& vec)
    {
        this->_data[0] -= vec[0];
        this->_data[1] -= vec[1];
        this->_data[2] -= vec[2];
        this->_data[3] -= vec[3];
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 4>& vector<elem_t, 4>::operator*=(vector<elem_t, 4> const& vec)
    {
        this->_data[0] *= vec[0];
        this->_data[1] *= vec[1];
        this->_data[2] *= vec[2];
        this->_data[3] *= vec[3];
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 4>& vector<elem_t, 4>::operator/=(vector<elem_t, 4> const& vec)
    {
        this->_data[0] /= vec[0];
        this->_data[1] /= vec[1];
        this->_data[2] /= vec[2];
        this->_data[3] /= vec[3];
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 4>& vector<elem_t, 4>::operator*=(elem_t const& scale)
    {
        this->_data[0] *= scale;
        this->_data[1] *= scale;
        this->_data[2] *= scale;
        this->_data[3] *= scale;
        return *this;
    }

    template <typename elem_t>
    constexpr vector<elem_t, 4>& vector<elem_t, 4>::operator/=(elem_t const& scale)
    {
        this->_data[0] /= scale;
        this->_data[1] /= scale;
        this->_data[2] /= scale;
        this->_data[3] /= scale;
        return *this;
    }

    template <typename elem_t>
    constexpr elem_t& vector<elem_t, 4>::operator[](std::size_t index)
    {
        return this->_data[index];
    }

    template <typename elem_t>
    constexpr elem_t const& vector<elem_t, 4>::operator[](std::size_t index) const
    {
        return this->_data[index];
    }

    template <typename elem_t>
    constexpr elem_t* vector<elem_t, 4>::data() noexcept
    {
        return this->_data;
    }

    template <typename elem_t>
    constexpr elem_t const* vector<elem_t, 4>::data() const noexcept
    {
        return this->_data;
    }

    template <typename elem_t>
    void vector<elem_t, 4>::fill(elem_t const& value)
    {
        this->_data[0] = value;
        this->_data[1] = value;
        this->_data[2] = value;
        this->_data[3] = value;
    }

    template <typename elem_t>
    constexpr std::size_t vector<elem_t, 4>::size() noexcept
    {
        return 4;
    }

    template <typename elem_t>
    vector<elem_t, 4> operator-(vector<elem_t, 4> const& vec)
    {
        return vector<elem_t, 4>{ -vec[0], -vec[1], -vec[2], -vec[3] };
    }

    template <typename elem_t>
    bool operator==(vector<elem_t, 4> const& lhs, vector<elem_t, 4> const& rhs)
    {
        return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2] && lhs[3] == rhs[3];
    }

    template <typename elem_t>
    cd::ostream& operator<<(cd::ostream& stream, vector<elem_t, 4> const& vec)
    {
        return stream << CD_L("{ ") << vec[0] << CD_L(", ") << vec[1] << CD_L(", ") << vec[2] << CD_L(", ") << vec[3] << CD_L(" }");
    }

    template <typename elem_t>
    cd::istream& operator>>(cd::istream& stream, vector<elem_t, 4>& vec)
    {
        TCHAR discard;
        return stream >> discard >> vec[0] >> discard >> vec[1] >> discard >> vec[2] >> discard >> vec[3] >> discard;
    }

    template <typename elem_t>
    constexpr elem_t dot(vector<elem_t, 4> const& lhs, vector<elem_t, 4> const& rhs)
    {
        return lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2] + lhs[3] * rhs[3];
    }

    template <typename elem_t>
    constexpr vector<elem_t, 4> min(vector<elem_t, 4> const& lhs, vector<elem_t, 4> const& rhs)
    {
        return vector<elem_t, 4>{ std::min(lhs[0], rhs[0])
                                , std::min(lhs[1], rhs[1])
                                , std::min(lhs[2], rhs[2])
                                , std::min(lhs[3], rhs[3]) };
    }

    template <typename elem_t>
    constexpr vector<elem_t, 4> max(vector<elem_t, 4> const& lhs, vector<elem_t, 4> const& rhs)
    {
        return vector<elem_t, 4>{ std::max(lhs[0], rhs[0])
                                , std::max(lhs[1], rhs[1])
                                , std::max(lhs[2], rhs[2])
                                , std::max(lhs[3], rhs[3]) };
    }

}
