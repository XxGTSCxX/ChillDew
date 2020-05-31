/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    CD_Vector4D.h
  \author  Gabrielle Tan Suan Choo
  \brief
    General 4D vector implementation.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Core.h"
#include "CD_MathDefines.h"
#include "CD_Vector.h"
#include "CD_Swizzle.h"
#include "CD_Degree.h"

namespace chilldew
{

    template <typename T>
    struct CD_API detail::vector_base<T, 4>
    {
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

            swizzle<vector, T, 4, 0, 1      > xy;
            swizzle<vector, T, 4, 0, 2      > xz;
            swizzle<vector, T, 4, 0, 3      > xw;
            swizzle<vector, T, 4, 1, 0      > yx;
            swizzle<vector, T, 4, 1, 2      > yz;
            swizzle<vector, T, 4, 1, 3      > yw;
            swizzle<vector, T, 4, 2, 0      > zx;
            swizzle<vector, T, 4, 2, 1      > zy;
            swizzle<vector, T, 4, 2, 3      > zw;
            swizzle<vector, T, 4, 3, 0      > wx;
            swizzle<vector, T, 4, 3, 1      > wy;
            swizzle<vector, T, 4, 3, 2      > wz;
            swizzle<vector, T, 4, 0, 1, 2   > xyz;
            swizzle<vector, T, 4, 0, 1, 3   > xyw;
            swizzle<vector, T, 4, 0, 2, 1   > xzy;
            swizzle<vector, T, 4, 0, 2, 3   > xzw;
            swizzle<vector, T, 4, 0, 3, 1   > xwy;
            swizzle<vector, T, 4, 0, 3, 2   > xwz;
            swizzle<vector, T, 4, 1, 0, 2   > yxz;
            swizzle<vector, T, 4, 1, 0, 3   > yxw;
            swizzle<vector, T, 4, 1, 2, 0   > yzx;
            swizzle<vector, T, 4, 1, 2, 3   > yzw;
            swizzle<vector, T, 4, 1, 3, 0   > ywx;
            swizzle<vector, T, 4, 1, 3, 2   > ywz;
            swizzle<vector, T, 4, 2, 0, 1   > zxy;
            swizzle<vector, T, 4, 2, 0, 3   > zxw;
            swizzle<vector, T, 4, 2, 1, 0   > zyx;
            swizzle<vector, T, 4, 2, 1, 3   > zyw;
            swizzle<vector, T, 4, 2, 3, 0   > zwx;
            swizzle<vector, T, 4, 2, 3, 1   > zwy;
            swizzle<vector, T, 4, 0, 1, 2, 3> xyzw;
            swizzle<vector, T, 4, 0, 1, 3, 2> xywz;
            swizzle<vector, T, 4, 0, 2, 1, 3> xzyw;
            swizzle<vector, T, 4, 0, 2, 3, 1> xzwy;
            swizzle<vector, T, 4, 0, 3, 1, 2> xwyz;
            swizzle<vector, T, 4, 0, 3, 2, 1> xwzy;
            swizzle<vector, T, 4, 1, 0, 2, 3> yxzw;
            swizzle<vector, T, 4, 1, 0, 3, 2> yxwz;
            swizzle<vector, T, 4, 1, 2, 0, 3> yzxw;
            swizzle<vector, T, 4, 1, 2, 3, 0> yzwx;
            swizzle<vector, T, 4, 1, 3, 0, 2> ywxz;
            swizzle<vector, T, 4, 1, 3, 2, 0> ywzx;
            swizzle<vector, T, 4, 2, 0, 1, 3> zxyw;
            swizzle<vector, T, 4, 2, 0, 3, 1> zxwy;
            swizzle<vector, T, 4, 2, 1, 0, 3> zyxw;
            swizzle<vector, T, 4, 2, 1, 3, 0> zywx;
            swizzle<vector, T, 4, 2, 3, 0, 1> zwxy;
            swizzle<vector, T, 4, 2, 3, 1, 0> zwyx;
            swizzle<vector, T, 4, 3, 0, 1, 2> wxyz;
            swizzle<vector, T, 4, 3, 0, 2, 1> wxzy;
            swizzle<vector, T, 4, 3, 1, 0, 2> wyxz;
            swizzle<vector, T, 4, 3, 1, 2, 0> wyzx;
            swizzle<vector, T, 4, 3, 2, 0, 1> wzxy;
            swizzle<vector, T, 4, 3, 2, 1, 0> wzyx;

            swizzle<vector, T, 4, 0, 1      > rg;
            swizzle<vector, T, 4, 0, 2      > rb;
            swizzle<vector, T, 4, 0, 3      > ra;
            swizzle<vector, T, 4, 1, 0      > gr;
            swizzle<vector, T, 4, 1, 2      > gb;
            swizzle<vector, T, 4, 1, 3      > ga;
            swizzle<vector, T, 4, 2, 0      > br;
            swizzle<vector, T, 4, 2, 1      > bg;
            swizzle<vector, T, 4, 2, 3      > ba;
            swizzle<vector, T, 4, 3, 0      > ar;
            swizzle<vector, T, 4, 3, 1      > ag;
            swizzle<vector, T, 4, 3, 2      > ab;
            swizzle<vector, T, 4, 0, 1, 2   > rgb;
            swizzle<vector, T, 4, 0, 1, 3   > rga;
            swizzle<vector, T, 4, 0, 2, 1   > rbg;
            swizzle<vector, T, 4, 0, 2, 3   > rba;
            swizzle<vector, T, 4, 0, 3, 1   > rag;
            swizzle<vector, T, 4, 0, 3, 2   > rab;
            swizzle<vector, T, 4, 1, 0, 2   > grb;
            swizzle<vector, T, 4, 1, 0, 3   > gra;
            swizzle<vector, T, 4, 1, 2, 0   > gbr;
            swizzle<vector, T, 4, 1, 2, 3   > gba;
            swizzle<vector, T, 4, 1, 3, 0   > gar;
            swizzle<vector, T, 4, 1, 3, 2   > gab;
            swizzle<vector, T, 4, 2, 0, 1   > brg;
            swizzle<vector, T, 4, 2, 0, 3   > bra;
            swizzle<vector, T, 4, 2, 1, 0   > bgr;
            swizzle<vector, T, 4, 2, 1, 3   > bga;
            swizzle<vector, T, 4, 2, 3, 0   > bar;
            swizzle<vector, T, 4, 2, 3, 1   > bag;
            swizzle<vector, T, 4, 0, 1, 2, 3> rgba;
            swizzle<vector, T, 4, 0, 1, 3, 2> rgab;
            swizzle<vector, T, 4, 0, 2, 1, 3> rbga;
            swizzle<vector, T, 4, 0, 2, 3, 1> rbag;
            swizzle<vector, T, 4, 0, 3, 1, 2> ragb;
            swizzle<vector, T, 4, 0, 3, 2, 1> rabg;
            swizzle<vector, T, 4, 1, 0, 2, 3> grba;
            swizzle<vector, T, 4, 1, 0, 3, 2> grab;
            swizzle<vector, T, 4, 1, 2, 0, 3> gbra;
            swizzle<vector, T, 4, 1, 2, 3, 0> gbar;
            swizzle<vector, T, 4, 1, 3, 0, 2> garb;
            swizzle<vector, T, 4, 1, 3, 2, 0> gabr;
            swizzle<vector, T, 4, 2, 0, 1, 3> brga;
            swizzle<vector, T, 4, 2, 0, 3, 1> brag;
            swizzle<vector, T, 4, 2, 1, 0, 3> bgra;
            swizzle<vector, T, 4, 2, 1, 3, 0> bgar;
            swizzle<vector, T, 4, 2, 3, 0, 1> barg;
            swizzle<vector, T, 4, 2, 3, 1, 0> bagr;
            swizzle<vector, T, 4, 3, 0, 1, 2> argb;
            swizzle<vector, T, 4, 3, 0, 2, 1> arbg;
            swizzle<vector, T, 4, 3, 1, 0, 2> agrb;
            swizzle<vector, T, 4, 3, 1, 2, 0> agbr;
            swizzle<vector, T, 4, 3, 2, 0, 1> abrg;
            swizzle<vector, T, 4, 3, 2, 1, 0> abgr;
        };
    };

    template <typename T>
    struct CD_API vector<T, 4> : private detail::vector_base<T, 4>
    {
    private:

        template <typename ... Params    > using IS_CONVERTIBLE_SFINAE = std::enable_if_t<std::conjunction_v<std::is_convertible<Params, T>...>>;
        template <typename U, size_t U_SZ> using VEC_CONVERSION_SFINAE = std::enable_if_t<std::is_convertible_v<U, T> && (U_SZ > 3)>;

    public:

        static vector<T, 4> const one;
        static vector<T, 4> const zero;

        using detail::vector_base<T, 4>::x;
        using detail::vector_base<T, 4>::y;
        using detail::vector_base<T, 4>::z;
        using detail::vector_base<T, 4>::w;

        using detail::vector_base<T, 4>::r;
        using detail::vector_base<T, 4>::g;
        using detail::vector_base<T, 4>::b;
        using detail::vector_base<T, 4>::a;

        using detail::vector_base<T, 4>::xy;
        using detail::vector_base<T, 4>::xz;
        using detail::vector_base<T, 4>::xw;
        using detail::vector_base<T, 4>::yx;
        using detail::vector_base<T, 4>::yz;
        using detail::vector_base<T, 4>::yw;
        using detail::vector_base<T, 4>::zx;
        using detail::vector_base<T, 4>::zy;
        using detail::vector_base<T, 4>::zw;
        using detail::vector_base<T, 4>::wx;
        using detail::vector_base<T, 4>::wy;
        using detail::vector_base<T, 4>::wz;
        using detail::vector_base<T, 4>::xyz;
        using detail::vector_base<T, 4>::xyw;
        using detail::vector_base<T, 4>::xzy;
        using detail::vector_base<T, 4>::xzw;
        using detail::vector_base<T, 4>::xwy;
        using detail::vector_base<T, 4>::xwz;
        using detail::vector_base<T, 4>::yxz;
        using detail::vector_base<T, 4>::yxw;
        using detail::vector_base<T, 4>::yzx;
        using detail::vector_base<T, 4>::yzw;
        using detail::vector_base<T, 4>::ywx;
        using detail::vector_base<T, 4>::ywz;
        using detail::vector_base<T, 4>::zxy;
        using detail::vector_base<T, 4>::zxw;
        using detail::vector_base<T, 4>::zyx;
        using detail::vector_base<T, 4>::zyw;
        using detail::vector_base<T, 4>::zwx;
        using detail::vector_base<T, 4>::zwy;
        using detail::vector_base<T, 4>::xyzw;
        using detail::vector_base<T, 4>::xywz;
        using detail::vector_base<T, 4>::xzyw;
        using detail::vector_base<T, 4>::xzwy;
        using detail::vector_base<T, 4>::xwyz;
        using detail::vector_base<T, 4>::xwzy;
        using detail::vector_base<T, 4>::yxzw;
        using detail::vector_base<T, 4>::yxwz;
        using detail::vector_base<T, 4>::yzxw;
        using detail::vector_base<T, 4>::yzwx;
        using detail::vector_base<T, 4>::ywxz;
        using detail::vector_base<T, 4>::ywzx;
        using detail::vector_base<T, 4>::zxyw;
        using detail::vector_base<T, 4>::zxwy;
        using detail::vector_base<T, 4>::zyxw;
        using detail::vector_base<T, 4>::zywx;
        using detail::vector_base<T, 4>::zwxy;
        using detail::vector_base<T, 4>::zwyx;
        using detail::vector_base<T, 4>::wxyz;
        using detail::vector_base<T, 4>::wxzy;
        using detail::vector_base<T, 4>::wyxz;
        using detail::vector_base<T, 4>::wyzx;
        using detail::vector_base<T, 4>::wzxy;
        using detail::vector_base<T, 4>::wzyx;

        using detail::vector_base<T, 4>::rg;
        using detail::vector_base<T, 4>::rb;
        using detail::vector_base<T, 4>::ra;
        using detail::vector_base<T, 4>::gr;
        using detail::vector_base<T, 4>::gb;
        using detail::vector_base<T, 4>::ga;
        using detail::vector_base<T, 4>::br;
        using detail::vector_base<T, 4>::bg;
        using detail::vector_base<T, 4>::ba;
        using detail::vector_base<T, 4>::ar;
        using detail::vector_base<T, 4>::ag;
        using detail::vector_base<T, 4>::ab;
        using detail::vector_base<T, 4>::rgb;
        using detail::vector_base<T, 4>::rga;
        using detail::vector_base<T, 4>::rbg;
        using detail::vector_base<T, 4>::rba;
        using detail::vector_base<T, 4>::rag;
        using detail::vector_base<T, 4>::rab;
        using detail::vector_base<T, 4>::grb;
        using detail::vector_base<T, 4>::gra;
        using detail::vector_base<T, 4>::gbr;
        using detail::vector_base<T, 4>::gba;
        using detail::vector_base<T, 4>::gar;
        using detail::vector_base<T, 4>::gab;
        using detail::vector_base<T, 4>::brg;
        using detail::vector_base<T, 4>::bra;
        using detail::vector_base<T, 4>::bgr;
        using detail::vector_base<T, 4>::bga;
        using detail::vector_base<T, 4>::bar;
        using detail::vector_base<T, 4>::bag;
        using detail::vector_base<T, 4>::rgba;
        using detail::vector_base<T, 4>::rgab;
        using detail::vector_base<T, 4>::rbga;
        using detail::vector_base<T, 4>::rbag;
        using detail::vector_base<T, 4>::ragb;
        using detail::vector_base<T, 4>::rabg;
        using detail::vector_base<T, 4>::grba;
        using detail::vector_base<T, 4>::grab;
        using detail::vector_base<T, 4>::gbra;
        using detail::vector_base<T, 4>::gbar;
        using detail::vector_base<T, 4>::garb;
        using detail::vector_base<T, 4>::gabr;
        using detail::vector_base<T, 4>::brga;
        using detail::vector_base<T, 4>::brag;
        using detail::vector_base<T, 4>::bgra;
        using detail::vector_base<T, 4>::bgar;
        using detail::vector_base<T, 4>::barg;
        using detail::vector_base<T, 4>::bagr;
        using detail::vector_base<T, 4>::argb;
        using detail::vector_base<T, 4>::arbg;
        using detail::vector_base<T, 4>::agrb;
        using detail::vector_base<T, 4>::agbr;
        using detail::vector_base<T, 4>::abrg;
        using detail::vector_base<T, 4>::abgr;

        constexpr vector() noexcept = default;

        template <typename X, typename Y, typename Z, typename W, typename = IS_CONVERTIBLE_SFINAE<X, Y, Z, W>> explicit constexpr vector(X&& x, Y&& y, Z&& z, W&& w       ) noexcept; // Construct with elements
        template <typename U,                                     typename = IS_CONVERTIBLE_SFINAE<U>         > explicit constexpr vector(U&&                    fill_value) noexcept; // Fill constructor
        template <typename U, size_t U_SZ,                        typename = VEC_CONVERSION_SFINAE<U, U_SZ>   > explicit constexpr vector(vector<U, U_SZ> const& vec       ) noexcept; // Conversion construction between vectors with different dimensions and element types

        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>> vector<T, 4>& operator= (vector<U, U_SZ> const& vec); // Conversion assignment between vectors with different dimensions and element types
        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>> vector<T, 4>& operator+=(vector<U, U_SZ> const& vec);
        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>> vector<T, 4>& operator-=(vector<U, U_SZ> const& vec);
        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>> vector<T, 4>& operator*=(vector<U, U_SZ> const& vec); // Multiplies two vectors component-wise (Hadamard Product)
        template <typename U, size_t U_SZ, typename = VEC_CONVERSION_SFINAE<U, U_SZ>> vector<T, 4>& operator/=(vector<U, U_SZ> const& vec); // Divides self with other vector component-wise

        template <typename U, typename = IS_CONVERTIBLE_SFINAE<U>> vector<T, 4>& operator*=(U const& scale);
        template <typename U, typename = IS_CONVERTIBLE_SFINAE<U>> vector<T, 4>& operator/=(U const& scale); // Division by 0 will set the values to infinity

        T&       operator[](size_t index);
        T const& operator[](size_t index) const;

        T*       data();
        T const* data() const;

        void fill(T const& value);
        static constexpr std::size_t size() noexcept;
    };

    template <typename T> vector<T, 4> operator-(vector<T, 4> const& vec);

    template <typename T> bool operator==(vector<T, 4> const& lhs, vector<T, 4> const& rhs);

    template <typename T> CD::ostream& operator<<(CD::ostream& stream, vector<T, 4> const& vec);
    template <typename T> CD::istream& operator>>(CD::istream& stream, vector<T, 4>&       vec);

    template <typename T> T            Dot(vector<T, 4> const& lhs, vector<T, 4> const& rhs);
    template <typename T> vector<T, 4> Max(vector<T, 4> const& lhs, vector<T, 4> const& rhs);
    template <typename T> vector<T, 4> Min(vector<T, 4> const& lhs, vector<T, 4> const& rhs);

    template <typename T>
    using Vector4D = vector<T, 4>;

}
