/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Vector4D.h
  \author  Gabrielle Tan Suan Choo
  \brief
    General 4D vector implementation.

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
    struct GTE_API Vector<T, 4>
    {
    protected:

        template <typename ... Params> using IS_VECTOR_SFINAE      = std::enable_if_t<is_all_same_v<Vector, Params...>>;
        template <typename ... Params> using IS_CONVERTIBLE_SFINAE = std::enable_if_t<std::conjunction_v<std::is_convertible<Params, T>...>>;

    public:

        static Vector<T, 4> const one;
        static Vector<T, 4> const zero;

        union
        {
            std::array<T, 4> _array{};

            struct
            {
                T x;
                T y;
                T z;
                T w;
            };

            struct
            {
                T r;
                T g;
                T b;
                T a;
            };

            Swizzle<Vector, T, 4, 0, 1      > xy;
            Swizzle<Vector, T, 4, 0, 2      > xz;
            Swizzle<Vector, T, 4, 0, 3      > xw;
            Swizzle<Vector, T, 4, 1, 0      > yx;
            Swizzle<Vector, T, 4, 1, 2      > yz;
            Swizzle<Vector, T, 4, 1, 3      > yw;
            Swizzle<Vector, T, 4, 2, 0      > zx;
            Swizzle<Vector, T, 4, 2, 1      > zy;
            Swizzle<Vector, T, 4, 2, 3      > zw;
            Swizzle<Vector, T, 4, 3, 0      > wx;
            Swizzle<Vector, T, 4, 3, 1      > wy;
            Swizzle<Vector, T, 4, 3, 2      > wz;
            Swizzle<Vector, T, 4, 0, 1, 2   > xyz;
            Swizzle<Vector, T, 4, 0, 1, 3   > xyw;
            Swizzle<Vector, T, 4, 0, 2, 1   > xzy;
            Swizzle<Vector, T, 4, 0, 2, 3   > xzw;
            Swizzle<Vector, T, 4, 0, 3, 1   > xwy;
            Swizzle<Vector, T, 4, 0, 3, 2   > xwz;
            Swizzle<Vector, T, 4, 1, 0, 2   > yxz;
            Swizzle<Vector, T, 4, 1, 0, 3   > yxw;
            Swizzle<Vector, T, 4, 1, 2, 0   > yzx;
            Swizzle<Vector, T, 4, 1, 2, 3   > yzw;
            Swizzle<Vector, T, 4, 1, 3, 0   > ywx;
            Swizzle<Vector, T, 4, 1, 3, 2   > ywz;
            Swizzle<Vector, T, 4, 2, 0, 1   > zxy;
            Swizzle<Vector, T, 4, 2, 0, 3   > zxw;
            Swizzle<Vector, T, 4, 2, 1, 0   > zyx;
            Swizzle<Vector, T, 4, 2, 1, 3   > zyw;
            Swizzle<Vector, T, 4, 2, 3, 0   > zwx;
            Swizzle<Vector, T, 4, 2, 3, 1   > zwy;
            Swizzle<Vector, T, 4, 0, 1, 2, 3> xyzw;
            Swizzle<Vector, T, 4, 0, 1, 3, 2> xywz;
            Swizzle<Vector, T, 4, 0, 2, 1, 3> xzyw;
            Swizzle<Vector, T, 4, 0, 2, 3, 1> xzwy;
            Swizzle<Vector, T, 4, 0, 3, 1, 2> xwyz;
            Swizzle<Vector, T, 4, 0, 3, 2, 1> xwzy;
            Swizzle<Vector, T, 4, 1, 0, 2, 3> yxzw;
            Swizzle<Vector, T, 4, 1, 0, 3, 2> yxwz;
            Swizzle<Vector, T, 4, 1, 2, 0, 3> yzxw;
            Swizzle<Vector, T, 4, 1, 2, 3, 0> yzwx;
            Swizzle<Vector, T, 4, 1, 3, 0, 2> ywxz;
            Swizzle<Vector, T, 4, 1, 3, 2, 0> ywzx;
            Swizzle<Vector, T, 4, 2, 0, 1, 3> zxyw;
            Swizzle<Vector, T, 4, 2, 0, 3, 1> zxwy;
            Swizzle<Vector, T, 4, 2, 1, 0, 3> zyxw;
            Swizzle<Vector, T, 4, 2, 1, 3, 0> zywx;
            Swizzle<Vector, T, 4, 2, 3, 0, 1> zwxy;
            Swizzle<Vector, T, 4, 2, 3, 1, 0> zwyx;
            Swizzle<Vector, T, 4, 3, 0, 1, 2> wxyz;
            Swizzle<Vector, T, 4, 3, 0, 2, 1> wxzy;
            Swizzle<Vector, T, 4, 3, 1, 0, 2> wyxz;
            Swizzle<Vector, T, 4, 3, 1, 2, 0> wyzx;
            Swizzle<Vector, T, 4, 3, 2, 0, 1> wzxy;
            Swizzle<Vector, T, 4, 3, 2, 1, 0> wzyx;

            Swizzle<Vector, T, 4, 0, 1      > rg;
            Swizzle<Vector, T, 4, 0, 2      > rb;
            Swizzle<Vector, T, 4, 0, 3      > ra;
            Swizzle<Vector, T, 4, 1, 0      > gr;
            Swizzle<Vector, T, 4, 1, 2      > gb;
            Swizzle<Vector, T, 4, 1, 3      > ga;
            Swizzle<Vector, T, 4, 2, 0      > br;
            Swizzle<Vector, T, 4, 2, 1      > bg;
            Swizzle<Vector, T, 4, 2, 3      > ba;
            Swizzle<Vector, T, 4, 3, 0      > ar;
            Swizzle<Vector, T, 4, 3, 1      > ag;
            Swizzle<Vector, T, 4, 3, 2      > ab;
            Swizzle<Vector, T, 4, 0, 1, 2   > rgb;
            Swizzle<Vector, T, 4, 0, 1, 3   > rga;
            Swizzle<Vector, T, 4, 0, 2, 1   > rbg;
            Swizzle<Vector, T, 4, 0, 2, 3   > rba;
            Swizzle<Vector, T, 4, 0, 3, 1   > rag;
            Swizzle<Vector, T, 4, 0, 3, 2   > rab;
            Swizzle<Vector, T, 4, 1, 0, 2   > grb;
            Swizzle<Vector, T, 4, 1, 0, 3   > gra;
            Swizzle<Vector, T, 4, 1, 2, 0   > gbr;
            Swizzle<Vector, T, 4, 1, 2, 3   > gba;
            Swizzle<Vector, T, 4, 1, 3, 0   > gar;
            Swizzle<Vector, T, 4, 1, 3, 2   > gab;
            Swizzle<Vector, T, 4, 2, 0, 1   > brg;
            Swizzle<Vector, T, 4, 2, 0, 3   > bra;
            Swizzle<Vector, T, 4, 2, 1, 0   > bgr;
            Swizzle<Vector, T, 4, 2, 1, 3   > bga;
            Swizzle<Vector, T, 4, 2, 3, 0   > bar;
            Swizzle<Vector, T, 4, 2, 3, 1   > bag;
            Swizzle<Vector, T, 4, 0, 1, 2, 3> rgba;
            Swizzle<Vector, T, 4, 0, 1, 3, 2> rgab;
            Swizzle<Vector, T, 4, 0, 2, 1, 3> rbga;
            Swizzle<Vector, T, 4, 0, 2, 3, 1> rbag;
            Swizzle<Vector, T, 4, 0, 3, 1, 2> ragb;
            Swizzle<Vector, T, 4, 0, 3, 2, 1> rabg;
            Swizzle<Vector, T, 4, 1, 0, 2, 3> grba;
            Swizzle<Vector, T, 4, 1, 0, 3, 2> grab;
            Swizzle<Vector, T, 4, 1, 2, 0, 3> gbra;
            Swizzle<Vector, T, 4, 1, 2, 3, 0> gbar;
            Swizzle<Vector, T, 4, 1, 3, 0, 2> garb;
            Swizzle<Vector, T, 4, 1, 3, 2, 0> gabr;
            Swizzle<Vector, T, 4, 2, 0, 1, 3> brga;
            Swizzle<Vector, T, 4, 2, 0, 3, 1> brag;
            Swizzle<Vector, T, 4, 2, 1, 0, 3> bgra;
            Swizzle<Vector, T, 4, 2, 1, 3, 0> bgar;
            Swizzle<Vector, T, 4, 2, 3, 0, 1> barg;
            Swizzle<Vector, T, 4, 2, 3, 1, 0> bagr;
            Swizzle<Vector, T, 4, 3, 0, 1, 2> argb;
            Swizzle<Vector, T, 4, 3, 0, 2, 1> arbg;
            Swizzle<Vector, T, 4, 3, 1, 0, 2> agrb;
            Swizzle<Vector, T, 4, 3, 1, 2, 0> agbr;
            Swizzle<Vector, T, 4, 3, 2, 0, 1> abrg;
            Swizzle<Vector, T, 4, 3, 2, 1, 0> abgr;
        };

        constexpr Vector()                           noexcept = default;
        constexpr Vector(Vector<T, 4> const&)        noexcept = default;
        Vector<T, 4>& operator=(Vector<T, 4> const&) noexcept = default;

        template <typename ... Params, typename = IS_CONVERTIBLE_SFINAE<Params...>>
        constexpr Vector(Params&& ... args) noexcept;                           // Construct with elements

        template <typename U, size_t U_SZ, typename = IS_CONVERTIBLE_SFINAE<U>>
        explicit Vector(Vector<U, U_SZ> const& vector);                         // Conversion construction between vectors with different dimensions and element types

        template <typename U, size_t U_SZ, typename = IS_CONVERTIBLE_SFINAE<U>>
        Vector<T, 4>& operator=(Vector<U, U_SZ> const& vector);                 // Conversion assignment between vectors with different dimensions and element types

        Vector<T, 4>& operator+=(Vector<T, 4> const& other);
        Vector<T, 4>& operator-=(Vector<T, 4> const& other);
        Vector<T, 4>& operator*=(Vector<T, 4> const& other);                    // Multiplies two vectors component-wise (Hadamard Product)
        Vector<T, 4>& operator*=(T            const& scale);
        Vector<T, 4>& operator/=(T            const& scale);                    // Division by 0 will set the values to infinity

        T&       operator[](size_t index);
        T const& operator[](size_t index) const;

        T*       data();
        T const* data() const;

        void fill(T const& value);
        static constexpr size_t size();
    };

    template <typename T> Vector<T, 4> operator+(Vector<T, 4> const& lhs   , Vector<T, 4> const& rhs   );
    template <typename T> Vector<T, 4> operator-(Vector<T, 4> const& lhs   , Vector<T, 4> const& rhs   );
    template <typename T> Vector<T, 4> operator*(Vector<T, 4> const& lhs   , Vector<T, 4> const& rhs   ); // Multiplies two vectors component-wise (Hadamard Product)
    template <typename T> Vector<T, 4> operator*(Vector<T, 4> const& vector, T            const& scale );
    template <typename T> Vector<T, 4> operator*(T            const& scale , Vector<T, 4> const& vector);
    template <typename T> Vector<T, 4> operator/(Vector<T, 4> const& vector, T            const& scale ); // Division by 0 will set the values to infinity
    template <typename T> Vector<T, 4> operator-(Vector<T, 4> const& vector                            );

    template <typename T> bool operator==(Vector<T, 4> const& lhs, Vector<T, 4> const& rhs);
    template <typename T> bool operator!=(Vector<T, 4> const& lhs, Vector<T, 4> const& rhs);

    template <typename T> GTE::ostream& operator<<(GTE::ostream& stream, Vector<T, 4> const& vector);
    template <typename T> GTE::istream& operator>>(GTE::istream& stream, Vector<T, 4>&       vector);

    template <typename T> T             MagnitudeSquared(Vector<T, 4> const& vector);
    template <typename T> T             Magnitude       (Vector<T, 4> const& vector);
    template <typename T> Vector<T, 4>  Normalise       (Vector<T, 4> const& vector);
    template <typename T> Vector<T, 4>& Normalised      (Vector<T, 4>&       vector);

    template <typename T> T            Dot     (Vector<T, 4> const& lhs   , Vector<T, 4> const& rhs   );
    template <typename T> T            Distance(Vector<T, 4> const& lhs   , Vector<T, 4> const& rhs   );
    template <typename T> Vector<T, 4> Max     (Vector<T, 4> const& lhs   , Vector<T, 4> const& rhs   );
    template <typename T> Vector<T, 4> Min     (Vector<T, 4> const& lhs   , Vector<T, 4> const& rhs   );
    template <typename T> Vector<T, 4> Project (Vector<T, 4> const& vector, Vector<T, 4> const& normal);

    template <typename T> Vector<T, 4> LerpUnclamped(Vector<T, 4> const& from   , Vector<T, 4> const& to    , T const& alpha             );
    template <typename T> Vector<T, 4> Lerp         (Vector<T, 4> const& from   , Vector<T, 4> const& to    , T const& alpha             );
    template <typename T> Vector<T, 4> MoveTowards  (Vector<T, 4> const& current, Vector<T, 4> const& target, T const& max_distance_delta);

    template <typename T>
    using Vector4D = Vector<T, 4>;

}
