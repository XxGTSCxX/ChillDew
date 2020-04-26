/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Vector.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Base class for math vector class.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Core.h"          // GTE_API
#include "GTE_MetaFunctions.h" // is_all_same
#include <array>               // std::array

namespace GTE
{

    template <typename T, size_t SZ>
    struct GTE_API Vector final
    {
    private:

        template <typename ... Params> using IS_VECTOR_SFINAE      = std::enable_if_t<is_all_same_v<Vector, Params...>>;
        template <typename ... Params> using IS_CONVERTIBLE_SFINAE = std::enable_if_t<std::conjunction_v<std::is_convertible<Params, T>...>>;

        std::array<T, SZ> _array;

    public:

        Vector()              = default;
        Vector(Vector const&) = default;
        Vector(Vector&&)      = default;

        Vector& operator=(Vector const&) = default;
        Vector& operator=(Vector&&)      = default;

        template <typename ... Params, typename = IS_CONVERTIBLE_SFINAE<Params...>>
        constexpr Vector(Params&& ... args);                                    // Construct with elements

        template <typename U, unsigned U_SZ, typename = IS_CONVERTIBLE_SFINAE<U>>
        explicit Vector(Vector<U, U_SZ> const& vector);                         // Conversion construction between vectors with different dimensions and element types

        template <typename U, unsigned U_SZ, typename = IS_CONVERTIBLE_SFINAE<U>>
        Vector& operator=(Vector<U, U_SZ> const& vector);                       // Conversion assignment between vectors with different dimensions and element types

        Vector& operator+=(Vector const& other);
        Vector& operator-=(Vector const& other);
        Vector& operator*=(Vector const& other);                                // This is using Hadamard Product
        Vector& operator*=(T      const& scale);
        Vector& operator/=(T      const& scale);                                // Division by 0 will set the values to infinity

        T&       operator[](size_t index);
        T const& operator[](size_t index) const;

        T*       data();
        T const* data() const;

        void fill(T const& value);
        static constexpr size_t size();
    };

    template <typename T, size_t SZ> Vector<T, SZ> operator+(Vector<T, SZ> const& lhs   , Vector<T, SZ> const& rhs   );
    template <typename T, size_t SZ> Vector<T, SZ> operator-(Vector<T, SZ> const& lhs   , Vector<T, SZ> const& rhs   );
    template <typename T, size_t SZ> Vector<T, SZ> operator*(Vector<T, SZ> const& lhs   , Vector<T, SZ> const& rhs   ); // This is using Hadamard Product
    template <typename T, size_t SZ> Vector<T, SZ> operator*(Vector<T, SZ> const& vector, T             const& scale );
    template <typename T, size_t SZ> Vector<T, SZ> operator*(T             const& scale , Vector<T, SZ> const& vector);
    template <typename T, size_t SZ> Vector<T, SZ> operator/(Vector<T, SZ> const& vector, T             const& scale ); // Division by 0 will set the values to infinity
    template <typename T, size_t SZ> Vector<T, SZ> operator-(Vector<T, SZ> const& vector                             );

    template <typename T, size_t SZ> bool operator==(Vector<T, SZ> const& lhs, Vector<T, SZ> const& rhs);
    template <typename T, size_t SZ> bool operator!=(Vector<T, SZ> const& lhs, Vector<T, SZ> const& rhs);

    template <typename T, size_t SZ> GTE::ostream& operator<<(GTE::ostream& stream, Vector<T, SZ> const& vector);
    template <typename T, size_t SZ> GTE::istream& operator>>(GTE::istream& stream, Vector<T, SZ>&       vector);

    template <typename T, size_t SZ> T              MagnitudeSquared(Vector<T, SZ> const& vector);
    template <typename T, size_t SZ> T              Magnitude       (Vector<T, SZ> const& vector);
    template <typename T, size_t SZ> Vector<T, SZ>  Normalise       (Vector<T, SZ> const& vector);
    template <typename T, size_t SZ> Vector<T, SZ>& Normalised      (Vector<T, SZ>&       vector);

    template <typename T, size_t SZ> T Dot(Vector<T, SZ> const& lhs, Vector<T, SZ> const& rhs);

}
