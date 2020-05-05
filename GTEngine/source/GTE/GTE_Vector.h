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
    struct VectorData
    {
        template <typename ... Params> using SFINAE = std::enable_if_t<std::conjunction_v<std::is_convertible<Params, T>...>>;

        std::array<T, SZ> _array{};

        template <typename ... Params, typename = SFINAE<Params...>>
        constexpr VectorData(Params&& ... args) noexcept;
    };

    template <typename T, size_t SZ>
    struct GTE_API Vector : private VectorData<T, SZ>
    {
    protected:

        template <typename ... Params> using IS_CONVERTIBLE_SFINAE = std::enable_if_t<std::conjunction_v<std::is_convertible<Params, T>...>>;
        template <typename ... Params> using MULTI_PARAM_SFINAE    = std::enable_if_t<(std::conjunction_v<std::is_convertible<Params, T>...> && sizeof...(Params) == SZ)>;

    public:

        template <typename ... Params, typename = MULTI_PARAM_SFINAE<Params...>>
        constexpr Vector(Params&& ... args);                                    // Construct with elements

        template <typename U, typename = IS_CONVERTIBLE_SFINAE<U>>
        explicit constexpr Vector(U&& fill_value) noexcept;                     // Fill constructor

        template <typename U, unsigned U_SZ, typename = IS_CONVERTIBLE_SFINAE<U>>
        explicit constexpr Vector(Vector<U, U_SZ> const& vector) noexcept;      // Conversion construction between vectors with different dimensions and element types

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

    template <typename T, size_t SZ> T             Dot           (Vector<T, SZ> const& lhs   , Vector<T, SZ> const& rhs          );
    template <typename T, size_t SZ> T             Distance      (Vector<T, SZ> const& lhs   , Vector<T, SZ> const& rhs          );
    template <typename T, size_t SZ> Vector<T, SZ> Max           (Vector<T, SZ> const& lhs   , Vector<T, SZ> const& rhs          );
    template <typename T, size_t SZ> Vector<T, SZ> Min           (Vector<T, SZ> const& lhs   , Vector<T, SZ> const& rhs          );
    template <typename T, size_t SZ> Vector<T, SZ> Project       (Vector<T, SZ> const& vector, Vector<T, SZ> const& normal       );
    template <typename T, size_t SZ> Vector<T, SZ> ClampMagnitude(Vector<T, SZ> const& vector, T             const& max_magnitude);

    template <typename T, size_t SZ> Vector<T, SZ> LerpUnclamped(Vector<T, SZ> const& from   , Vector<T, SZ> const& to    , T const& alpha             );
    template <typename T, size_t SZ> Vector<T, SZ> Lerp         (Vector<T, SZ> const& from   , Vector<T, SZ> const& to    , T const& alpha             );
    template <typename T, size_t SZ> Vector<T, SZ> MoveTowards  (Vector<T, SZ> const& current, Vector<T, SZ> const& target, T const& max_distance_delta);

    template <typename T>
    struct Vector<T, 0>; // There shouldn't be a 0 dimension vector

}
