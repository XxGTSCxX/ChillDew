/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Vector3D.h
  \author  Gabrielle Tan Suan Choo
  \brief
    General 3D vector implementation.

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
    struct GTE_API Vector<T, 3>
    {
    protected:

        template <typename ... Params> using IS_VECTOR_SFINAE      = std::enable_if_t<is_all_same_v<Vector, Params...>>;
        template <typename ... Params> using IS_CONVERTIBLE_SFINAE = std::enable_if_t<std::conjunction_v<std::is_convertible<Params, T>...>>;

    public:

        static Vector<T, 3> const up;
        static Vector<T, 3> const down;
        static Vector<T, 3> const left;
        static Vector<T, 3> const right;
        static Vector<T, 3> const forward;
        static Vector<T, 3> const back;
        static Vector<T, 3> const one;
        static Vector<T, 3> const zero;

        union
        {
            std::array<T, 3> _array{};

            struct
            {
                T x;
                T y;
                T z;
            };

            struct
            {
                T r;
                T g;
                T b;
            };

            Swizzle<Vector, T, 3, 0, 1   > xy;
            Swizzle<Vector, T, 3, 0, 2   > xz;
            Swizzle<Vector, T, 3, 1, 0   > yx;
            Swizzle<Vector, T, 3, 1, 2   > yz;
            Swizzle<Vector, T, 3, 2, 0   > zx;
            Swizzle<Vector, T, 3, 2, 1   > zy;
            Swizzle<Vector, T, 3, 0, 1, 2> xyz;
            Swizzle<Vector, T, 3, 0, 2, 1> xzy;
            Swizzle<Vector, T, 3, 1, 0, 2> yxz;
            Swizzle<Vector, T, 3, 1, 2, 0> yzx;
            Swizzle<Vector, T, 3, 2, 0, 1> zxy;
            Swizzle<Vector, T, 3, 2, 1, 0> zyx;

            Swizzle<Vector, T, 3, 0, 1   > rg;
            Swizzle<Vector, T, 3, 0, 2   > rb;
            Swizzle<Vector, T, 3, 1, 0   > gr;
            Swizzle<Vector, T, 3, 1, 2   > gb;
            Swizzle<Vector, T, 3, 2, 0   > br;
            Swizzle<Vector, T, 3, 2, 1   > bg;
            Swizzle<Vector, T, 3, 0, 1, 2> rgb;
            Swizzle<Vector, T, 3, 0, 2, 1> rbg;
            Swizzle<Vector, T, 3, 1, 0, 2> grb;
            Swizzle<Vector, T, 3, 1, 2, 0> gbr;
            Swizzle<Vector, T, 3, 2, 0, 1> brg;
            Swizzle<Vector, T, 3, 2, 1, 0> bgr;
        };

        constexpr Vector()                           noexcept = default;
        constexpr Vector(Vector<T, 3> const&)        noexcept = default;
        Vector<T, 3>& operator=(Vector<T, 3> const&) noexcept = default;

        template <typename U, typename = IS_CONVERTIBLE_SFINAE<U>> constexpr Vector(Vector<U, 1> const&)        noexcept;
        template <typename U, typename = IS_CONVERTIBLE_SFINAE<U>> constexpr Vector(Vector<U, 2> const&)        noexcept;
        template <typename U, typename = IS_CONVERTIBLE_SFINAE<U>> Vector<T, 3>& operator=(Vector<U, 1> const&) noexcept;
        template <typename U, typename = IS_CONVERTIBLE_SFINAE<U>> Vector<T, 3>& operator=(Vector<U, 2> const&) noexcept;

        template <typename ... Params, typename = IS_CONVERTIBLE_SFINAE<Params...>>
        constexpr Vector(Params&& ... args) noexcept;                           // Construct with elements

        template <typename U, size_t U_SZ, typename = IS_CONVERTIBLE_SFINAE<U>>
        explicit Vector(Vector<U, U_SZ> const& vector);                         // Conversion construction between vectors with different dimensions and element types

        template <typename U, size_t U_SZ, typename = IS_CONVERTIBLE_SFINAE<U>>
        Vector<T, 3>& operator=(Vector<U, U_SZ> const& vector);                 // Conversion assignment between vectors with different dimensions and element types

        Vector<T, 3>& operator+=(Vector<T, 3> const& other);
        Vector<T, 3>& operator-=(Vector<T, 3> const& other);
        Vector<T, 3>& operator*=(Vector<T, 3> const& other);                    // Multiplies two vectors component-wise (Hadamard Product)
        Vector<T, 3>& operator*=(T            const& scale);
        Vector<T, 3>& operator/=(T            const& scale);                    // Division by 0 will set the values to infinity

        T&       operator[](size_t index);
        T const& operator[](size_t index) const;

        T*       data();
        T const* data() const;

        void fill(T const& value);
        static constexpr size_t size();
    };

    template <typename T> Vector<T, 3> operator-(Vector<T, 3> const& vector);

    template <typename T> bool operator==(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs);

    template <typename T> GTE::ostream& operator<<(GTE::ostream& stream, Vector<T, 3> const& vector);
    template <typename T> GTE::istream& operator>>(GTE::istream& stream, Vector<T, 3>&       vector);

    template <typename T> T            Dot           (Vector<T, 3> const& lhs   , Vector<T, 3> const& rhs    );
    template <typename T> Vector<T, 3> Max           (Vector<T, 3> const& lhs   , Vector<T, 3> const& rhs    );
    template <typename T> Vector<T, 3> Min           (Vector<T, 3> const& lhs   , Vector<T, 3> const& rhs    );
    template <typename T> Degree       Angle         (Vector<T, 3> const& lhs   , Vector<T, 3> const& rhs    );
    template <typename T> Degree       SignedAngle   (Vector<T, 3> const& from  , Vector<T, 3> const& to     );
    template <typename T> Vector<T, 3> Reflect       (Vector<T, 3> const& vector, Vector<T, 3> const& normal );
    template <typename T> Vector<T, 3> Cross         (Vector<T, 3> const& lhs   , Vector<T, 3> const& rhs    );
    template <typename T> Vector<T, 3> ProjectOnPlane(Vector<T, 3> const& vector, Vector<T, 3> const& normal );
    template <typename T> void         OrthoNormalise(Vector<T, 3>&       normal, Vector<T, 3>&       tangent);

    template <typename T> Vector<T, 3> RotateTowards(Vector<T, 3> const& current, Vector<T, 3> const& target, Radian max_angle_delta, T const& max_magnitude_delta); // TODO: Might wanna consider moving this to Quaternion instead?

    template <typename T>
    using Vector3D = Vector<T, 3>;

}
