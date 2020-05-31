/******************************************************************************/
/*!
  \project Chilldew-Engine
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
#include "CD_MathDefines.h"
#include "CD_Vector.h"
#include "CD_Degree.h"
#include "CD_Swizzle.inl"

namespace chilldew
{

    template <typename T>
    struct CD_API detail::vector_base<T, 3>
    {
        union
        {
            std::array<T, 3> _array;

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

            swizzle<vector, T, 3, 0, 1   > xy;
            swizzle<vector, T, 3, 0, 2   > xz;
            swizzle<vector, T, 3, 1, 0   > yx;
            swizzle<vector, T, 3, 1, 2   > yz;
            swizzle<vector, T, 3, 2, 0   > zx;
            swizzle<vector, T, 3, 2, 1   > zy;
            swizzle<vector, T, 3, 0, 1, 2> xyz;
            swizzle<vector, T, 3, 0, 2, 1> xzy;
            swizzle<vector, T, 3, 1, 0, 2> yxz;
            swizzle<vector, T, 3, 1, 2, 0> yzx;
            swizzle<vector, T, 3, 2, 0, 1> zxy;
            swizzle<vector, T, 3, 2, 1, 0> zyx;

            swizzle<vector, T, 3, 0, 1   > rg;
            swizzle<vector, T, 3, 0, 2   > rb;
            swizzle<vector, T, 3, 1, 0   > gr;
            swizzle<vector, T, 3, 1, 2   > gb;
            swizzle<vector, T, 3, 2, 0   > br;
            swizzle<vector, T, 3, 2, 1   > bg;
            swizzle<vector, T, 3, 0, 1, 2> rgb;
            swizzle<vector, T, 3, 0, 2, 1> rbg;
            swizzle<vector, T, 3, 1, 0, 2> grb;
            swizzle<vector, T, 3, 1, 2, 0> gbr;
            swizzle<vector, T, 3, 2, 0, 1> brg;
            swizzle<vector, T, 3, 2, 1, 0> bgr;
        };
    };

    template <typename T>
    struct CD_API vector<T, 3> : private detail::vector_base<T, 3>
    {
    private:

        template <typename ... Params    > using IS_CONVERTIBLE_SFINAE = std::enable_if_t<std::conjunction_v<std::is_convertible<Params, T>...>>;
        template <typename U, size_t U_SZ> using VEC_CONVERSION_SFINAE = std::enable_if_t<std::is_convertible_v<U, T> && (U_SZ > 2)>;

    public:

        static vector<T, 3> const up;
        static vector<T, 3> const down;
        static vector<T, 3> const left;
        static vector<T, 3> const right;
        static vector<T, 3> const forward;
        static vector<T, 3> const back;
        static vector<T, 3> const one;
        static vector<T, 3> const zero;

        using detail::vector_base<T, 3>::x;
        using detail::vector_base<T, 3>::y;
        using detail::vector_base<T, 3>::z;

        using detail::vector_base<T, 3>::r;
        using detail::vector_base<T, 3>::g;
        using detail::vector_base<T, 3>::b;

        using detail::vector_base<T, 3>::xy;
        using detail::vector_base<T, 3>::xz;
        using detail::vector_base<T, 3>::yx;
        using detail::vector_base<T, 3>::yz;
        using detail::vector_base<T, 3>::zx;
        using detail::vector_base<T, 3>::zy;
        using detail::vector_base<T, 3>::xyz;
        using detail::vector_base<T, 3>::xzy;
        using detail::vector_base<T, 3>::yxz;
        using detail::vector_base<T, 3>::yzx;
        using detail::vector_base<T, 3>::zxy;
        using detail::vector_base<T, 3>::zyx;

        using detail::vector_base<T, 3>::rg;
        using detail::vector_base<T, 3>::rb;
        using detail::vector_base<T, 3>::gr;
        using detail::vector_base<T, 3>::gb;
        using detail::vector_base<T, 3>::br;
        using detail::vector_base<T, 3>::bg;
        using detail::vector_base<T, 3>::rgb;
        using detail::vector_base<T, 3>::rbg;
        using detail::vector_base<T, 3>::grb;
        using detail::vector_base<T, 3>::gbr;
        using detail::vector_base<T, 3>::brg;
        using detail::vector_base<T, 3>::bgr;

        constexpr vector() noexcept = default;

        template <typename X, typename Y, typename Z, typename = IS_CONVERTIBLE_SFINAE<X, Y, Z>>
        explicit constexpr vector(X&& x, Y&& y, Z&& z) noexcept; // Construct with elements

        template <typename U, typename = IS_CONVERTIBLE_SFINAE<U>>
        explicit constexpr vector(U&& fill_value) noexcept; // Fill constructor

        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>>
        explicit constexpr vector(vector<U, U_SZ> const& vector) noexcept; // Conversion construction between vectors with different dimensions and element types

        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>> vector<T, 3>& operator= (vector<U, U_SZ> const& vector); // Conversion assignment between vectors with different dimensions and element types
        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>> vector<T, 3>& operator+=(vector<U, U_SZ> const& vector);
        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>> vector<T, 3>& operator-=(vector<U, U_SZ> const& vector);
        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>> vector<T, 3>& operator*=(vector<U, U_SZ> const& vector); // Multiplies two vectors component-wise (Hadamard Product)
        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>> vector<T, 3>& operator/=(vector<U, U_SZ> const& vector); // Divides self with other vector component-wise

        template <typename U, typename = IS_CONVERTIBLE_SFINAE<U>> vector<T, 3>& operator*=(U const& scale);
        template <typename U, typename = IS_CONVERTIBLE_SFINAE<U>> vector<T, 3>& operator/=(U const& scale); // Division by 0 will set the values to infinity

        T&       operator[](size_t index);
        T const& operator[](size_t index) const;

        T*       data();
        T const* data() const;

        void fill(T const& value);
        static constexpr size_t size() noexcept;
    };

    template <typename T> vector<T, 3> operator-(vector<T, 3> const& vec);

    template <typename T> bool operator==(vector<T, 3> const& lhs, vector<T, 3> const& rhs);

    template <typename T> CD::ostream& operator<<(CD::ostream& stream, vector<T, 3> const& vec);
    template <typename T> CD::istream& operator>>(CD::istream& stream, vector<T, 3>&       vec);

    template <typename T> T            Dot           (vector<T, 3> const& lhs   , vector<T, 3> const& rhs    );
    template <typename T> vector<T, 3> Max           (vector<T, 3> const& lhs   , vector<T, 3> const& rhs    );
    template <typename T> vector<T, 3> Min           (vector<T, 3> const& lhs   , vector<T, 3> const& rhs    );
    template <typename T> degree       Angle         (vector<T, 3> const& lhs   , vector<T, 3> const& rhs    );
    template <typename T> degree       SignedAngle   (vector<T, 3> const& from  , vector<T, 3> const& to     );
    template <typename T> vector<T, 3> Reflect       (vector<T, 3> const& vec   , vector<T, 3> const& normal );
    template <typename T> vector<T, 3> Cross         (vector<T, 3> const& lhs   , vector<T, 3> const& rhs    );
    template <typename T> vector<T, 3> ProjectOnPlane(vector<T, 3> const& vec   , vector<T, 3> const& normal );
    template <typename T> void         OrthoNormalise(vector<T, 3>&       normal, vector<T, 3>&       tangent);

    template <typename T> vector<T, 3> RotateTowards(vector<T, 3> const& current, vector<T, 3> const& target, radian max_angle_delta, T const& max_magnitude_delta); // TODO: Might wanna consider moving this to Quaternion instead?

    template <typename T>
    using Vector3D = vector<T, 3>;

}
