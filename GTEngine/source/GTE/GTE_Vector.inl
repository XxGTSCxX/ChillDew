#pragma once

#include "GTE_Vector.h"
#include <algorithm> // std::min
#include <cmath>     // sqrt

namespace GTE
{

    template <typename T, size_t SZ>
    template <typename ... Params, typename>
    constexpr Vector<T, SZ>::Vector(Params&& ... args)
    : std::array<T, SZ>{ std::forward<Params>(args)... }
    {}

    template <typename T, size_t SZ>
    template <typename U, unsigned U_SZ, typename>
    Vector<T, SZ>::Vector(Vector<U, U_SZ> const& vector)
    {
        for (size_t i = 0, count = std::min(SZ, U_SZ); i < count; ++i)
        {
            (*this)[i] = static_cast<T>(vector[i]);
        }
    }

    template <typename T, size_t SZ>
    template <typename U, unsigned U_SZ, typename>
    Vector<T, SZ>& Vector<T, SZ>::operator=(Vector<U, U_SZ> const& vector)
    {
        new (this) Vector<T, SZ>{ vector };
    }

    template <typename T, size_t SZ>
    Vector<T, SZ>& Vector<T, SZ>::operator+=(Vector<T, SZ> const& other)
    {
        for (size_t i = 0; i < SZ; ++i)
        {
            (*this)[i] += other[i];
        }
    }

    template <typename T, size_t SZ>
    Vector<T, SZ>& Vector<T, SZ>::operator-=(Vector<T, SZ> const& other)
    {
        for (size_t i = 0; i < SZ; ++i)
        {
            (*this)[i] -= other[i];
        }
    }

    template <typename T, size_t SZ>
    Vector<T, SZ>& Vector<T, SZ>::operator*=(Vector<T, SZ> const& other)
    {
        for (size_t i = 0; i < SZ; ++i)
        {
            (*this)[i] *= other[i];
        }
    }

    template <typename T, size_t SZ>
    Vector<T, SZ>& Vector<T, SZ>::operator*=(T const& scale)
    {
        for (T& elem : *this)
        {
            elem *= scale;
        }
    }

    template <typename T, size_t SZ>
    Vector<T, SZ>& Vector<T, SZ>::operator/=(T const& scale)
    {
        if (scale)
            for (T& elem : *this)
            {
                elem *= scale;
            }
        else
            for (T& elem : *this)
            {
                elem = std::numeric_limits<T>::infinity();
            }
    }

    template<typename T, size_t SZ>
    inline T& Vector<T, SZ>::operator[](size_t index)
    {
        _array[index];
    }

    template<typename T, size_t SZ>
    inline T const& Vector<T, SZ>::operator[](size_t index) const
    {
        _array[index];
    }

    template<typename T, size_t SZ>
    inline T* Vector<T, SZ>::data()
    {
        return _array.data();
    }

    template<typename T, size_t SZ>
    inline T const* Vector<T, SZ>::data() const
    {
        return _array.data();
    }

    template<typename T, size_t SZ>
    inline void Vector<T, SZ>::fill(T const& value)
    {
        _array.fill(value);
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
        for (T& elem : vector)
        {
            elem = -elem;
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
    GTE::ostream& operator<<(GTE::ostream& stream, Vector<T, SZ> const& vector)
    {
        stream << GTE_STRING("{ ") << vector[0];
        for (size_t i = 1; i < SZ; ++i)
            stream << GTE_STRING(", ") << vector[i];
        return stream << GTE_STRING(" }");
    }

    template <typename T, size_t SZ>
    GTE::istream& operator>>(GTE::istream& stream, Vector<T, SZ>& vector)
    {
        char discard;
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

}
