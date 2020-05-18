/******************************************************************************/
/*!
  \project ChillDew-Engine
  \file    CD_Vector3D.h
  \author  Gabrielle Tan Suan Choo
  \brief
    General 3D vector implementation.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Core.h"
#include "CD_Math.h"
#include "CD_Vector.h"
#include "CD_Degree.h"
#include "CD_Swizzle.inl"

namespace CD
{

    template <typename T>
    struct CD_API VectorData<T, 3>
    {
        template <typename ... Params> using IS_CONVERTIBLE_SFINAE = std::enable_if_t<std::conjunction_v<std::is_convertible<Params, T>...>>;

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

        template <typename ... Params, typename = IS_CONVERTIBLE_SFINAE<Params...>>
        constexpr VectorData(Params&& ... args) noexcept;
    };

    template <typename T>
    struct CD_API Vector<T, 3> : private VectorData<T, 3>
    {
    private:

        template <typename ... Params    > using IS_CONVERTIBLE_SFINAE = std::enable_if_t<std::conjunction_v<std::is_convertible<Params, T>...>>;
        template <typename U, size_t U_SZ> using VEC_CONVERSION_SFINAE = std::enable_if_t<std::is_convertible_v<U, T> && (U_SZ > 2)>;

    public:

        static Vector<T, 3> const up;
        static Vector<T, 3> const down;
        static Vector<T, 3> const left;
        static Vector<T, 3> const right;
        static Vector<T, 3> const forward;
        static Vector<T, 3> const back;
        static Vector<T, 3> const one;
        static Vector<T, 3> const zero;

        using VectorData<T, 3>::x;
        using VectorData<T, 3>::y;
        using VectorData<T, 3>::z;

        using VectorData<T, 3>::r;
        using VectorData<T, 3>::g;
        using VectorData<T, 3>::b;

        using VectorData<T, 3>::xy;
        using VectorData<T, 3>::xz;
        using VectorData<T, 3>::yx;
        using VectorData<T, 3>::yz;
        using VectorData<T, 3>::zx;
        using VectorData<T, 3>::zy;
        using VectorData<T, 3>::xyz;
        using VectorData<T, 3>::xzy;
        using VectorData<T, 3>::yxz;
        using VectorData<T, 3>::yzx;
        using VectorData<T, 3>::zxy;
        using VectorData<T, 3>::zyx;

        using VectorData<T, 3>::rg;
        using VectorData<T, 3>::rb;
        using VectorData<T, 3>::gr;
        using VectorData<T, 3>::gb;
        using VectorData<T, 3>::br;
        using VectorData<T, 3>::bg;
        using VectorData<T, 3>::rgb;
        using VectorData<T, 3>::rbg;
        using VectorData<T, 3>::grb;
        using VectorData<T, 3>::gbr;
        using VectorData<T, 3>::brg;
        using VectorData<T, 3>::bgr;

        template <typename X, typename Y, typename Z, typename = IS_CONVERTIBLE_SFINAE<X, Y, Z>>
        explicit constexpr Vector(X&& x, Y&& y, Z&& z) noexcept; // Construct with elements

        template <typename U, typename = IS_CONVERTIBLE_SFINAE<U>>
        explicit constexpr Vector(U&& fill_value) noexcept; // Fill constructor

        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>>
        explicit constexpr Vector(Vector<U, U_SZ> const& vector) noexcept; // Conversion construction between vectors with different dimensions and element types

        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>> Vector<T, 3>& operator= (Vector<U, U_SZ> const& vector); // Conversion assignment between vectors with different dimensions and element types
        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>> Vector<T, 3>& operator+=(Vector<U, U_SZ> const& vector);
        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>> Vector<T, 3>& operator-=(Vector<U, U_SZ> const& vector);
        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>> Vector<T, 3>& operator*=(Vector<U, U_SZ> const& vector); // Multiplies two vectors component-wise (Hadamard Product)
        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>> Vector<T, 3>& operator/=(Vector<U, U_SZ> const& vector); // Divides self with other vector component-wise

        template <typename U, typename = IS_CONVERTIBLE_SFINAE<U>> Vector<T, 3>& operator*=(U const& scale);
        template <typename U, typename = IS_CONVERTIBLE_SFINAE<U>> Vector<T, 3>& operator/=(U const& scale); // Division by 0 will set the values to infinity

        T&       operator[](size_t index);
        T const& operator[](size_t index) const;

        T*       data();
        T const* data() const;

        void fill(T const& value);
        static constexpr size_t size();

    protected:

        using VectorData<T, 3>::_array;
    };

    template <typename T> Vector<T, 3> operator-(Vector<T, 3> const& vector);

    template <typename T> bool operator==(Vector<T, 3> const& lhs, Vector<T, 3> const& rhs);

    template <typename T> CD::ostream& operator<<(CD::ostream& stream, Vector<T, 3> const& vector);
    template <typename T> CD::istream& operator>>(CD::istream& stream, Vector<T, 3>&       vector);

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
