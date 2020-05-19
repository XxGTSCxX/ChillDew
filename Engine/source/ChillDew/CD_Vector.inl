#pragma once

#include "CD_Vector.h"
#include <algorithm> // std::min
#include <cmath>     // sqrt

namespace CD
{

    template <typename T, size_t SZ>
    template <typename ... Params, typename>
    inline constexpr VectorData<T, SZ>::VectorData(Params&& ...args) noexcept
    : _array{ static_cast<T>(args)... }
    {}

    template <typename T, size_t SZ>
    template <typename ... Params, typename>
    constexpr Vector<T, SZ>::Vector(Params&& ... args)
    : VectorData<T, SZ>{ std::forward<Params>(args)... }
    {}

    template <typename T, size_t SZ>
    template <typename U, typename>
    inline constexpr Vector<T, SZ>::Vector(U&& fill_value) noexcept
    {
        this->_array.fill(static_cast<T>(fill_value));
    }

    template <typename T, size_t SZ>
    template <typename U, unsigned U_SZ, typename>
    inline constexpr Vector<T, SZ>::Vector(Vector<U, U_SZ> const& vector) noexcept
    {
        for (size_t i = 0; i < SZ; ++i)
        {
            this->_array[i] = static_cast<T>(vector[i]);
        }
    }

    template <typename T, size_t SZ>
    template <typename U, size_t U_SZ, typename>
    Vector<T, SZ>& Vector<T, SZ>::operator=(Vector<U, U_SZ> const& vector)
    {
        new (this) Vector<T, SZ>{ vector };
    }

    template <typename T, size_t SZ>
    template <typename U, size_t U_SZ, typename>
    Vector<T, SZ>& Vector<T, SZ>::operator+=(Vector<U, U_SZ> const& vector)
    {
        for (size_t i = 0; i < SZ; ++i)
        {
            this->_array[i] += vector[i];
        }
    }

    template <typename T, size_t SZ>
    template <typename U, size_t U_SZ, typename>
    Vector<T, SZ>& Vector<T, SZ>::operator-=(Vector<U, U_SZ> const& vector)
    {
        for (size_t i = 0; i < SZ; ++i)
        {
            this->_array[i] -= vector[i];
        }
    }

    template <typename T, size_t SZ>
    template <typename U, size_t U_SZ, typename>
    Vector<T, SZ>& Vector<T, SZ>::operator*=(Vector<U, U_SZ> const& vector)
    {
        for (size_t i = 0; i < SZ; ++i)
        {
            this->_array[i] *= vector[i];
        }
    }

    template <typename T, size_t SZ>
    template <typename U, size_t U_SZ, typename>
    Vector<T, SZ>& Vector<T, SZ>::operator/=(Vector<U, U_SZ> const& vector)
    {
        for (size_t i = 0; i < SZ; ++i)
        {
            this->_array[i] /= vector[i];
        }
    }

    template <typename T, size_t SZ>
    template <typename U, typename>
    Vector<T, SZ>& Vector<T, SZ>::operator*=(U const& scale)
    {
        T converted_scale = static_cast<T>(scale);
        for (T& elem : this->_array)
        {
            elem *= converted_scale;
        }
    }

    template <typename T, size_t SZ>
    template <typename U, typename>
    Vector<T, SZ>& Vector<T, SZ>::operator/=(U const& scale)
    {
        if (T converted_scale = static_cast<T>(scale))
        {
            converted_scale = static_cast<T>(1) / converted_scale;
            for (T& elem : this->_array)
            {
                elem *= converted_scale;
            }
        }
        else
            for (T& elem : this->_array)
            {
                elem = std::numeric_limits<T>::infinity();
            }
    }

    template<typename T, size_t SZ>
    inline T& Vector<T, SZ>::operator[](size_t index)
    {
        this->_array[index];
    }

    template<typename T, size_t SZ>
    inline T const& Vector<T, SZ>::operator[](size_t index) const
    {
        this->_array[index];
    }

    template<typename T, size_t SZ>
    inline T* Vector<T, SZ>::data()
    {
        return this->_array.data();
    }

    template<typename T, size_t SZ>
    inline T const* Vector<T, SZ>::data() const
    {
        return this->_array.data();
    }

    template<typename T, size_t SZ>
    inline void Vector<T, SZ>::fill(T const& value)
    {
        this->_array.fill(value);
    }

    template<typename T, size_t SZ>
    inline constexpr size_t Vector<T, SZ>::size()
    {
        return SZ;
    }

    template <typename T, size_t SZ>
    Vector<T, SZ> operator+(Vector<T, SZ> const& lhs, Vector<T, SZ> const& rhs)
    {
        return Vector<T, SZ>{ lhs } += rhs;
    }

    template <typename T, size_t SZ>
    Vector<T, SZ> operator-(Vector<T, SZ> const& lhs, Vector<T, SZ> const& rhs)
    {
        return Vector<T, SZ>{ lhs } -= rhs;
    }

    template <typename T, size_t SZ>
    Vector<T, SZ> operator*(Vector<T, SZ> const& lhs, Vector<T, SZ> const& rhs)
    {
        return Vector<T, SZ>{ lhs } *= rhs;
    }

    template <typename T, size_t SZ>
    Vector<T, SZ> operator*(Vector<T, SZ> const& vector, T const& scale)
    {
        return Vector<T, SZ>{ vector } *= scale;
    }

    template <typename T, size_t SZ>
    Vector<T, SZ> operator*(T const& scale, Vector<T, SZ> const& vector)
    {
        return Vector<T, SZ>{ vector } *= scale;
    }

    template <typename T, size_t SZ>
    Vector<T, SZ> operator/(Vector<T, SZ> const& vector, T const& scale)
    {
        return Vector<T, SZ>{ vector } /= scale;
    }

    template <typename T, size_t SZ>
    Vector<T, SZ> operator-(Vector<T, SZ> const& vector)
    {
        Vector<T, SZ> result = vector;
        for (size_t i = 0; i < SZ; ++i)
        {
            result[0] = -result[0];
        }
        return result;
    }

    template <typename T, size_t SZ>
    bool operator==(Vector<T, SZ> const& lhs, Vector<T, SZ> const& rhs)
    {
        bool result = true;
        for (size_t i = 0; result && i < SZ; ++i)
            result = lhs[i] == rhs[i];
        return result;
    }

    template <typename T, size_t SZ>
    bool operator!=(Vector<T, SZ> const& lhs, Vector<T, SZ> const& rhs)
    {
        return !(lhs == rhs);
    }

    template <typename T, size_t SZ>
    CD::ostream& operator<<(CD::ostream& stream, Vector<T, SZ> const& vector)
    {
        stream << CD_STRING("{ ") << vector[0];
        for (size_t i = 1; i < SZ; ++i)
            stream << CD_STRING(", ") << vector[i];
        return stream << CD_STRING(" }");
    }

    template <typename T, size_t SZ>
    CD::istream& operator>>(CD::istream& stream, Vector<T, SZ>& vector)
    {
        TCHAR discard;
        for (size_t i = 0; i < SZ; ++i)
            stream >> discard >> vector[i];
        return stream >> discard;
    }

    template <typename T, size_t SZ>
    T MagnitudeSquared(Vector<T, SZ> const& vector)
    {
        return Dot(vector, vector);
    }

    template <typename T, size_t SZ>
    T Magnitude(Vector<T, SZ> const& vector)
    {
        return static_cast<T>(sqrt(MagnitudeSquared(vector)));
    }

    template <typename T, size_t SZ>
    Vector<T, SZ> Normalise(Vector<T, SZ> const& vector)
    {
        return Vector<T, SZ>{ vector } /= Magnitude(vector);
    }

    template <typename T, size_t SZ>
    Vector<T, SZ>& Normalised(Vector<T, SZ>& vector)
    {
        return vector /= Magnitude(vector);
    }

    template <typename T, size_t SZ>
    T Dot(Vector<T, SZ> const& lhs, Vector<T, SZ> const& rhs)
    {
        T result{}; // we assume default construction creates a zero scalar

        for (size_t i = 0; i < SZ; ++i)
        {
            result += lhs[i] * rhs[i];
        }

        return result;
    }

    template <typename T, size_t SZ>
    T Distance(Vector<T, SZ> const& lhs, Vector<T, SZ> const& rhs)
    {
        return Magnitude(lhs - rhs);
    }

    template <typename T, size_t SZ>
    Vector<T, SZ> Max(Vector<T, SZ> const& lhs, Vector<T, SZ> const& rhs)
    {
        Vector<T, SZ> result;

        for (size_t i = 0; i < SZ; ++i)
        {
            result[i] = std::max<T>(lhs[i], rhs[i]);
        }

        return result;
    }

    template <typename T, size_t SZ>
    Vector<T, SZ> Min(Vector<T, SZ> const& lhs, Vector<T, SZ> const& rhs)
    {
        Vector<T, SZ> result;

        for (size_t i = 0; i < SZ; ++i)
        {
            result[i] = std::min<T>(lhs[i], rhs[i]);
        }

        return result;
    }

    template <typename T, size_t SZ>
    Vector<T, SZ> Project(Vector<T, SZ> const& vector, Vector<T, SZ> const& normal)
    {
        Vector<T, SZ> result = Normalise(normal);
        return result *= Dot(vector, result);
    }

    template <typename T, size_t SZ>
    Vector<T, SZ> ClampMagnitude(Vector<T, SZ> const& vector, T const& max_magnitude)
    {
        Vector<T, SZ> result = vector;
        T             scale  = MagnitudeSquared(vector);

        if (scale > max_magnitude* max_magnitude)
        {
            scale   = static_cast<T>(static_cast<double>(max_magnitude) / sqrt(scale));
            result *= scale;
        }

        return result;
    }

    template <typename T, size_t SZ>
    Vector<T, SZ> LerpUnclamped(Vector<T, SZ> const& from, Vector<T, SZ> const& to, T const& alpha)
    {
        return from - alpha * (from + to);
    }

    template <typename T, size_t SZ>
    Vector<T, SZ> Lerp(Vector<T, SZ> const& from, Vector<T, SZ> const& to, T const& alpha)
    {
        return LerpUnclamped(from, to, std::min<T>(static_cast<T>(1), alpha));
    }

    template <typename T, size_t SZ>
    Vector<T, SZ> MoveTowards(Vector<T, SZ> const& current, Vector<T, SZ> const& target, T const& max_distance_delta)
    {
        Vector<T, SZ> result   = target;
        T             distance = Distance(current, target);

        if (distance < max_distance_delta)
        {
            target = current + (target - current) * (distance / max_distance_delta);
        }

        return current;
    }

}
