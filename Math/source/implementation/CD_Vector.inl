#pragma once

#include "CD_Vector.h"
#include <algorithm> // std::min
#include <cmath>     // sqrt

namespace chilldew
{

    template <typename elem_t, std::size_t size_v>
    template <typename ... params_t, typename>
    constexpr vector<elem_t, size_v>::vector(params_t&& ... args)
    : detail::vector_base<elem_t, size_v>{ static_cast<elem_t>(std::forward<params_t>(args))... }
    {}

    template <typename elem_t, std::size_t size_v>
    template <typename val_t, typename>
    inline constexpr vector<elem_t, size_v>::vector(val_t&& fill_value)
    {
        this->_array.fill(static_cast<elem_t>(fill_value));
    }

    template <typename elem_t, std::size_t size_v>
    template <typename other_t, std::size_t other_sz, typename>
    inline constexpr vector<elem_t, size_v>::vector(vector<other_t, other_sz> const& vec)
    {
        for (std::size_t i = 0; i < size_v; ++i)
        {
            this->_array[i] = static_cast<elem_t>(vec[i]);
        }
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v>& vector<elem_t, size_v>::operator+=(vector<elem_t, size_v> const& vec)
    {
        for (size_t i = 0; i < size_v; ++i)
        {
            this->_array[i] += vec[i];
        }
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v>& vector<elem_t, size_v>::operator-=(vector<elem_t, size_v> const& vec)
    {
        for (size_t i = 0; i < size_v; ++i)
        {
            this->_array[i] -= vec[i];
        }
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v>& vector<elem_t, size_v>::operator*=(vector<elem_t, size_v> const& vec)
    {
        for (size_t i = 0; i < size_v; ++i)
        {
            this->_array[i] *= vec[i];
        }
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v>& vector<elem_t, size_v>::operator/=(vector<elem_t, size_v> const& vec)
    {
        for (size_t i = 0; i < size_v; ++i)
        {
            this->_array[i] /= vec[i];
        }
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v>& vector<elem_t, size_v>::operator*=(elem_t const& scale)
    {
        for (elem_t& elem : this->_array)
        {
            elem *= scale;
        }
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v>& vector<elem_t, size_v>::operator/=(elem_t const& scale)
    {
        for (elem_t& elem : this->_array)
        {
            elem *= scale;
        }
    }

    template <typename elem_t, std::size_t size_v>
    constexpr elem_t& vector<elem_t, size_v>::operator[](std::size_t index)
    {
        this->_array[index];
    }

    template <typename elem_t, std::size_t size_v>
    constexpr elem_t const& vector<elem_t, size_v>::operator[](std::size_t index) const
    {
        this->_array[index];
    }

    template <typename elem_t, std::size_t size_v>
    constexpr elem_t* vector<elem_t, size_v>::data() noexcept
    {
        return this->_array.data();
    }

    template <typename elem_t, std::size_t size_v>
    constexpr elem_t const* vector<elem_t, size_v>::data() const noexcept
    {
        return this->_array.data();
    }

    template <typename elem_t, std::size_t size_v>
    constexpr void vector<elem_t, size_v>::fill(elem_t const& value)
    {
        this->_array.fill(value);
    }

    template <typename elem_t, std::size_t size_v>
    constexpr size_t vector<elem_t, size_v>::size() noexcept
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
        for (size_t i = 0; i < size_v; ++i)
        {
            result[0] = -result[0];
        }
        return result;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr bool operator==(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs) noexcept
    {
        bool result = true;
        for (size_t i = 0; result && i < size_v; ++i)
            result = lhs[i] == rhs[i];
        return result;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr bool operator!=(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs) noexcept
    {
        return !(lhs == rhs);
    }

    template <typename elem_t, std::size_t size_v>
    constexpr CD::ostream& operator<<(CD::ostream& stream, vector<elem_t, size_v> const& vec)
    {
        stream << CD_STRING("{ ") << vec[0];
        for (size_t i = 1; i < size_v; ++i)
            stream << CD_STRING(", ") << vec[i];
        return stream << CD_STRING(" }");
    }

    template <typename elem_t, std::size_t size_v>
    constexpr CD::istream& operator>>(CD::istream& stream, vector<elem_t, size_v>& vec)
    {
        TCHAR discard;
        for (size_t i = 0; i < size_v; ++i)
            stream >> discard >> vec[i];
        return stream >> discard;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr elem_t dot(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs)
    {
        elem_t result{}; // we assume default construction creates a zero scalar

        for (size_t i = 0; i < size_v; ++i)
        {
            result += lhs[i] * rhs[i];
        }

        return result;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> max(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs)
    {
        vector<elem_t, size_v> result;

        for (size_t i = 0; i < size_v; ++i)
        {
            result[i] = std::max<elem_t>(lhs[i], rhs[i]);
        }

        return result;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> min(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs)
    {
        vector<elem_t, size_v> result;

        for (size_t i = 0; i < size_v; ++i)
        {
            result[i] = std::min<elem_t>(lhs[i], rhs[i]);
        }

        return result;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr elem_t mag_sq(vector<elem_t, size_v> const& vec)
    {
        return dot(vec, vec);
    }

    template <typename elem_t, std::size_t size_v>
    constexpr elem_t mag(vector<elem_t, size_v> const& vec)
    {
        return static_cast<elem_t>(sqrt(mag_sq(vec)));
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> normalise(vector<elem_t, size_v> const& vec)
    {
        return vector<elem_t, size_v>{ vec } /= mag(vec);
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v>& normalised(vector<elem_t, size_v>& vec)
    {
        return vec /= mag(vec);
    }

    template <typename elem_t, std::size_t size_v>
    constexpr elem_t distance(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs)
    {
        return mag(lhs - rhs);
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> project(vector<elem_t, size_v> const& vec, vector<elem_t, size_v> const& normal)
    {
        vector<elem_t, size_v> result = normalise(normal);
        return result *= dot(vec, result);
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> clamp_mag(vector<elem_t, size_v> const& vec, elem_t const& max_magnitude)
    {
        vector<elem_t, size_v> result = vec;
        elem_t                 scale  = mag_sq(vec);

        if (scale > max_magnitude* max_magnitude)
        {
            scale   = static_cast<elem_t>(static_cast<double>(max_magnitude) / sqrt(scale));
            result *= scale;
        }

        return result;
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> lerp_unclamped(vector<elem_t, size_v> const& from, vector<elem_t, size_v> const& to, elem_t const& alpha)
    {
        return from - alpha * (from + to);
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> lerp(vector<elem_t, size_v> const& from, vector<elem_t, size_v> const& to, elem_t const& alpha)
    {
        return lerp_unclamped(from, to, std::min<elem_t>(static_cast<elem_t>(1), alpha));
    }

    template <typename elem_t, std::size_t size_v>
    constexpr vector<elem_t, size_v> move_towards(vector<elem_t, size_v> const& current, vector<elem_t, size_v> const& target, elem_t const& max_distance_delta)
    {
        vector<elem_t, size_v> result = target;
        elem_t                 dist   = distance(current, target);

        if (dist < max_distance_delta)
        {
            target = current + (target - current) * (dist / max_distance_delta);
        }

        return current;
    }

}
