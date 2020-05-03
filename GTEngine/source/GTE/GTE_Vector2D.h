/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Vector2D.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Partial vector specialisation for 2D vector implementation.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Core.h"
#include "GTE_Math.h"
#include "GTE_Vector.h"
#include "GTE_Swizzle.h"
#include "GTE_Degree.h"

namespace GTE
{

    template <typename T>
    struct GTE_API Vector<T, 2>
    {
    protected:

        template <typename ... Params> using IS_VECTOR_SFINAE      = std::enable_if_t<is_all_same_v<Vector, Params...>>;
        template <typename ... Params> using IS_CONVERTIBLE_SFINAE = std::enable_if_t<std::conjunction_v<std::is_convertible<Params, T>...>>;

    public:

        static Vector<T, 2> const up;
        static Vector<T, 2> const down;
        static Vector<T, 2> const left;
        static Vector<T, 2> const right;
        static Vector<T, 2> const one;
        static Vector<T, 2> const zero;

        union
        {
            std::array<T, 2> _array{};

            struct
            {
                T x;
                T y;
            };

            Swizzle<Vector, T, 2, 0, 1> xy;
            Swizzle<Vector, T, 2, 1, 0> yx;
        };

        constexpr Vector()                           noexcept = default;
        constexpr Vector(Vector<T, 2> const&)        noexcept = default;
        Vector<T, 2>& operator=(Vector<T, 2> const&) noexcept = default;

        template <typename ... Params, typename = IS_CONVERTIBLE_SFINAE<Params...>>
        constexpr Vector(Params&& ... args) noexcept;                           // Construct with elements

        template <typename U, size_t U_SZ, typename = IS_CONVERTIBLE_SFINAE<U>>
        explicit Vector(Vector<U, U_SZ> const& vector);                         // Conversion construction between vectors with different dimensions and element types

        template <typename U, size_t U_SZ, typename = IS_CONVERTIBLE_SFINAE<U>>
        Vector<T, 2>& operator=(Vector<U, U_SZ> const& vector);                 // Conversion assignment between vectors with different dimensions and element types

        Vector<T, 2>& operator+=(Vector<T, 2> const& other);
        Vector<T, 2>& operator-=(Vector<T, 2> const& other);
        Vector<T, 2>& operator*=(Vector<T, 2> const& other);                    // Multiplies two vectors component-wise (Hadamard Product)
        Vector<T, 2>& operator*=(T            const& scale);
        Vector<T, 2>& operator/=(T            const& scale);                    // Division by 0 will set the values to infinity

        T&       operator[](size_t index);
        T const& operator[](size_t index) const;

        T*       data();
        T const* data() const;

        void fill(T const& value);
        static constexpr size_t size();
    };

    template <typename T> Vector<T, 2> operator+(Vector<T, 2> const& lhs   , Vector<T, 2> const& rhs   );
    template <typename T> Vector<T, 2> operator-(Vector<T, 2> const& lhs   , Vector<T, 2> const& rhs   );
    template <typename T> Vector<T, 2> operator*(Vector<T, 2> const& lhs   , Vector<T, 2> const& rhs   ); // Multiplies two vectors component-wise (Hadamard Product)
    template <typename T> Vector<T, 2> operator*(Vector<T, 2> const& vector, T            const& scale );
    template <typename T> Vector<T, 2> operator*(T            const& scale , Vector<T, 2> const& vector);
    template <typename T> Vector<T, 2> operator/(Vector<T, 2> const& vector, T            const& scale ); // Division by 0 will set the values to infinity
    template <typename T> Vector<T, 2> operator-(Vector<T, 2> const& vector                            );

    template <typename T> bool operator==(Vector<T, 2> const& lhs, Vector<T, 2> const& rhs);
    template <typename T> bool operator!=(Vector<T, 2> const& lhs, Vector<T, 2> const& rhs);

    template <typename T> GTE::ostream& operator<<(GTE::ostream& stream, Vector<T, 2> const& vector);
    template <typename T> GTE::istream& operator>>(GTE::istream& stream, Vector<T, 2>&       vector);

    template <typename T> T             MagnitudeSquared(Vector<T, 2> const& vector);
    template <typename T> T             Magnitude       (Vector<T, 2> const& vector);
    template <typename T> Vector<T, 2>  Perpendicular   (Vector<T, 2> const& vector);
    template <typename T> Vector<T, 2>  Normalise       (Vector<T, 2> const& vector);
    template <typename T> Vector<T, 2>& Normalised      (Vector<T, 2>&       vector);

    template <typename T> T            Dot     (Vector<T, 2> const& lhs, Vector<T, 2> const& rhs);
    template <typename T> Degree       Angle   (Vector<T, 2> const& lhs, Vector<T, 2> const& rhs);
    template <typename T> T            Distance(Vector<T, 2> const& lhs, Vector<T, 2> const& rhs);
    template <typename T> Vector<T, 2> Max     (Vector<T, 2> const& lhs, Vector<T, 2> const& rhs);
    template <typename T> Vector<T, 2> Min     (Vector<T, 2> const& lhs, Vector<T, 2> const& rhs);

    template <typename T> Vector<T, 2> Project    (Vector<T, 2> const& vector, Vector<T, 2> const& normal);
    template <typename T> Vector<T, 2> Reflect    (Vector<T, 2> const& vector, Vector<T, 2> const& normal);
    template <typename T> Degree       SignedAngle(Vector<T, 2> const& from  , Vector<T, 2> const& to    );

    template <typename T> Vector<T, 2> ClampMagnitude(Vector<T, 2> const& vector, T const& max_magnitude);

    template <typename T> Vector<T, 2> LerpUnclamped(Vector<T, 2> const& from   , Vector<T, 2> const& to    , T const& alpha             );
    template <typename T> Vector<T, 2> Lerp         (Vector<T, 2> const& from   , Vector<T, 2> const& to    , T const& alpha             );
    template <typename T> Vector<T, 2> MoveTowards  (Vector<T, 2> const& current, Vector<T, 2> const& target, T const& max_distance_delta);

    template <typename T>
    using Vector2D = Vector<T, 2>;

}
