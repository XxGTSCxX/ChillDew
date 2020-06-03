#pragma once

#include "cdm_vector.h"
#include <algorithm> // std::min, std::max
#include <cmath>     // sqrt

namespace chilldew::math
{

    template <typename elem_t, std::size_t size_v>
    template <typename ... params_t, typename>
    constexpr vector<elem_t, size_v>::vector(params_t&& ... args)
    : detail::vector_base<elem_t, size_v>{ static_cast<elem_t>(std::forward<params_t>(args))... }
    {}

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v>::vector(elem_t const& fill_value)
    {
        for (std::size_t i = 0; i < size_v; ++i)
        {
            this->_data[i] = fill_value;
        }
    }

    template <typename  elem_t, std::size_t  size_v          >
    template <typename _elem_t, std::size_t _size_v, typename>
    constexpr vector<elem_t, size_v>::vector(vector<_elem_t, _size_v> const& vec)
    {
        for (std::size_t i = 0; i < size_v; ++i)
        {
            this->_data[i] = static_cast<elem_t>(vec[i]);
        }
        return *this;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v>& vector<elem_t, size_v>::operator+=(vector<elem_t, size_v> const& vec)
    {
        for (std::size_t i = 0; i < size_v; ++i)
        {
            this->_data[i] += vec[i];
        }
        return *this;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v>& vector<elem_t, size_v>::operator-=(vector<elem_t, size_v> const& vec)
    {
        for (std::size_t i = 0; i < size_v; ++i)
        {
            this->_data[i] -= vec[i];
        }
        return *this;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v>& vector<elem_t, size_v>::operator*=(vector<elem_t, size_v> const& vec)
    {
        for (std::size_t i = 0; i < size_v; ++i)
        {
            this->_data[i] *= vec[i];
        }
        return *this;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v>& vector<elem_t, size_v>::operator/=(vector<elem_t, size_v> const& vec)
    {
        for (std::size_t i = 0; i < size_v; ++i)
        {
            this->_data[i] /= vec[i];
        }
        return *this;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v>& vector<elem_t, size_v>::operator*=(elem_t const& scale)
    {
        for (std::size_t i = 0; i < size_v; ++i)
        {
            this->_data[i] *= scale;
        }
        return *this;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v>& vector<elem_t, size_v>::operator/=(elem_t const& scale)
    {
        elem_t inv_scale = static_cast<elem_t>(1) / scale;
        for (std::size_t i = 0; i < size_v; ++i)
        {
            this->_data[i] *= inv_scale;
        }
        return *this;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr elem_t& vector<elem_t, size_v>::operator[](std::size_t index)
    {
        return this->_data[index];
    }

    template <typename elem_t, std::size_t size_v>
    constexpr elem_t const& vector<elem_t, size_v>::operator[](std::size_t index) const
    {
        return this->_data[index];
    }

    template <typename elem_t, std::size_t size_v>
    constexpr elem_t* vector<elem_t, size_v>::data() noexcept
    {
        return this->_data;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr elem_t const* vector<elem_t, size_v>::data() const noexcept
    {
        return this->_data;
    }

    template <typename elem_t, std::size_t size_v>
    void vector<elem_t, size_v>::fill(elem_t const& value)
    {
        for (std::size_t i = 0; i < size_v; ++i)
        {
            this->_data[i] = value;
        }
    }

    template <typename elem_t, std::size_t size_v>
    constexpr std::size_t vector<elem_t, size_v>::size() noexcept
    {
        return size_v;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> operator+(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs)
    {
        return vector<elem_t, size_v>{ lhs } += rhs;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> operator-(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs)
    {
        return vector<elem_t, size_v>{ lhs } -= rhs;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> operator*(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs)
    {
        return vector<elem_t, size_v>{ lhs } *= rhs;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> operator*(vector<elem_t, size_v> const& vec, elem_t const& scale)
    {
        return vector<elem_t, size_v>{ vec } *= scale;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> operator*(elem_t const& scale, vector<elem_t, size_v> const& vec)
    {
        return vector<elem_t, size_v>{ vec } *= scale;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> operator/(vector<elem_t, size_v> const& vec, elem_t const& scale)
    {
        return vector<elem_t, size_v>{ vec } /= scale;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> operator-(vector<elem_t, size_v> const& vec)
    {
        vector<elem_t, size_v> result = vec;
        for (std::size_t i = 0; i < size_v; ++i)
        {
            result[i] = -result[i];
        }
        return result;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr bool operator==(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs) noexcept
    {
        for (std::size_t i = 0; i < size_v; ++i)
            if (lhs[i] != rhs[i])
                return false;
        return true;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr bool operator!=(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs) noexcept
    {
        return !(lhs == rhs);
    }

    template <typename elem_t, std::size_t size_v>
    constexpr cd::ostream& operator<<(cd::ostream& stream, vector<elem_t, size_v> const& vec)
    {
        stream << CD_STRING("{ ") << vec[0];
        for (std::size_t i = 1; i < size_v; ++i)
            stream << CD_STRING(", ") << vec[i];
        return stream << CD_STRING(" }");
    }

    template <typename elem_t, std::size_t size_v>
    constexpr cd::istream& operator>>(cd::istream& stream, vector<elem_t, size_v>& vec)
    {
        TCHAR discard;
        for (std::size_t i = 0; i < size_v; ++i)
            stream >> discard >> vec[i];
        return stream >> discard;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr elem_t dot(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs)
    {
        elem_t result{};
        for (std::size_t i = 0; i < size_v; ++i)
        {
            result += lhs[i] * rhs[i];
        }
        return result;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr elem_t length_square(vector<elem_t, size_v> const& vec)
    {
        return dot(vec, vec);
    }

    template <typename elem_t, std::size_t size_v>
    constexpr elem_t length(vector<elem_t, size_v> const& vec)
    {
        return sqrt(length_square(vec));
    }

    template <typename elem_t, std::size_t size_v>
    constexpr elem_t distance(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs)
    {
        return length(rhs - lhs);
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> reflect(vector<elem_t, size_v> const& vec, vector<elem_t, size_v> const& normal)
    {
        return vec - static_cast<elem_t>(2) * dot(vec, normal) * normal;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> normalise(vector<elem_t, size_v> const& vec)
    {
        return vector<elem_t, size_v>{ vec } /= length(vec);
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v>& normalised(vector<elem_t, size_v>& vec)
    {
        return vec /= length(vec);
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> min(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs)
    {
        vector<elem_t, size_v> result;
        for (std::size_t i = 0; i < size_v; ++i)
        {
            result[i] = std::min(lhs[i], rhs[i]);
        }
        return result;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> max(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs)
    {
        vector<elem_t, size_v> result;
        for (std::size_t i = 0; i < size_v; ++i)
        {
            result[i] = std::max(lhs[i], rhs[i]);
        }
        return result;
    }

}
