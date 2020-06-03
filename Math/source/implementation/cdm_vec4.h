/******************************************************************************/
/*!
  \project Chilldew-Math
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

#include "cd_core.h"
#include "cdm_defines.h"
#include "cdm_vector.h"
#include "cdm_swizzle.h"

namespace chilldew::math
{

    template <typename elem_t>
    struct CD_API detail::vector_base<elem_t, 4>
    {
        union
        {
            elem_t _data[4];

            struct
            {
                elem_t x;
                elem_t y;
                elem_t z;
                elem_t w;
            };

            struct
            {
                elem_t r;
                elem_t g;
                elem_t b;
                elem_t a;
            };

            swizzle<vector, elem_t, 4, 0, 1      > xy;
            swizzle<vector, elem_t, 4, 0, 2      > xz;
            swizzle<vector, elem_t, 4, 0, 3      > xw;
            swizzle<vector, elem_t, 4, 1, 0      > yx;
            swizzle<vector, elem_t, 4, 1, 2      > yz;
            swizzle<vector, elem_t, 4, 1, 3      > yw;
            swizzle<vector, elem_t, 4, 2, 0      > zx;
            swizzle<vector, elem_t, 4, 2, 1      > zy;
            swizzle<vector, elem_t, 4, 2, 3      > zw;
            swizzle<vector, elem_t, 4, 3, 0      > wx;
            swizzle<vector, elem_t, 4, 3, 1      > wy;
            swizzle<vector, elem_t, 4, 3, 2      > wz;
            swizzle<vector, elem_t, 4, 0, 1, 2   > xyz;
            swizzle<vector, elem_t, 4, 0, 1, 3   > xyw;
            swizzle<vector, elem_t, 4, 0, 2, 1   > xzy;
            swizzle<vector, elem_t, 4, 0, 2, 3   > xzw;
            swizzle<vector, elem_t, 4, 0, 3, 1   > xwy;
            swizzle<vector, elem_t, 4, 0, 3, 2   > xwz;
            swizzle<vector, elem_t, 4, 1, 0, 2   > yxz;
            swizzle<vector, elem_t, 4, 1, 0, 3   > yxw;
            swizzle<vector, elem_t, 4, 1, 2, 0   > yzx;
            swizzle<vector, elem_t, 4, 1, 2, 3   > yzw;
            swizzle<vector, elem_t, 4, 1, 3, 0   > ywx;
            swizzle<vector, elem_t, 4, 1, 3, 2   > ywz;
            swizzle<vector, elem_t, 4, 2, 0, 1   > zxy;
            swizzle<vector, elem_t, 4, 2, 0, 3   > zxw;
            swizzle<vector, elem_t, 4, 2, 1, 0   > zyx;
            swizzle<vector, elem_t, 4, 2, 1, 3   > zyw;
            swizzle<vector, elem_t, 4, 2, 3, 0   > zwx;
            swizzle<vector, elem_t, 4, 2, 3, 1   > zwy;
            swizzle<vector, elem_t, 4, 0, 1, 2, 3> xyzw;
            swizzle<vector, elem_t, 4, 0, 1, 3, 2> xywz;
            swizzle<vector, elem_t, 4, 0, 2, 1, 3> xzyw;
            swizzle<vector, elem_t, 4, 0, 2, 3, 1> xzwy;
            swizzle<vector, elem_t, 4, 0, 3, 1, 2> xwyz;
            swizzle<vector, elem_t, 4, 0, 3, 2, 1> xwzy;
            swizzle<vector, elem_t, 4, 1, 0, 2, 3> yxzw;
            swizzle<vector, elem_t, 4, 1, 0, 3, 2> yxwz;
            swizzle<vector, elem_t, 4, 1, 2, 0, 3> yzxw;
            swizzle<vector, elem_t, 4, 1, 2, 3, 0> yzwx;
            swizzle<vector, elem_t, 4, 1, 3, 0, 2> ywxz;
            swizzle<vector, elem_t, 4, 1, 3, 2, 0> ywzx;
            swizzle<vector, elem_t, 4, 2, 0, 1, 3> zxyw;
            swizzle<vector, elem_t, 4, 2, 0, 3, 1> zxwy;
            swizzle<vector, elem_t, 4, 2, 1, 0, 3> zyxw;
            swizzle<vector, elem_t, 4, 2, 1, 3, 0> zywx;
            swizzle<vector, elem_t, 4, 2, 3, 0, 1> zwxy;
            swizzle<vector, elem_t, 4, 2, 3, 1, 0> zwyx;
            swizzle<vector, elem_t, 4, 3, 0, 1, 2> wxyz;
            swizzle<vector, elem_t, 4, 3, 0, 2, 1> wxzy;
            swizzle<vector, elem_t, 4, 3, 1, 0, 2> wyxz;
            swizzle<vector, elem_t, 4, 3, 1, 2, 0> wyzx;
            swizzle<vector, elem_t, 4, 3, 2, 0, 1> wzxy;
            swizzle<vector, elem_t, 4, 3, 2, 1, 0> wzyx;

            swizzle<vector, elem_t, 4, 0, 1      > rg;
            swizzle<vector, elem_t, 4, 0, 2      > rb;
            swizzle<vector, elem_t, 4, 0, 3      > ra;
            swizzle<vector, elem_t, 4, 1, 0      > gr;
            swizzle<vector, elem_t, 4, 1, 2      > gb;
            swizzle<vector, elem_t, 4, 1, 3      > ga;
            swizzle<vector, elem_t, 4, 2, 0      > br;
            swizzle<vector, elem_t, 4, 2, 1      > bg;
            swizzle<vector, elem_t, 4, 2, 3      > ba;
            swizzle<vector, elem_t, 4, 3, 0      > ar;
            swizzle<vector, elem_t, 4, 3, 1      > ag;
            swizzle<vector, elem_t, 4, 3, 2      > ab;
            swizzle<vector, elem_t, 4, 0, 1, 2   > rgb;
            swizzle<vector, elem_t, 4, 0, 1, 3   > rga;
            swizzle<vector, elem_t, 4, 0, 2, 1   > rbg;
            swizzle<vector, elem_t, 4, 0, 2, 3   > rba;
            swizzle<vector, elem_t, 4, 0, 3, 1   > rag;
            swizzle<vector, elem_t, 4, 0, 3, 2   > rab;
            swizzle<vector, elem_t, 4, 1, 0, 2   > grb;
            swizzle<vector, elem_t, 4, 1, 0, 3   > gra;
            swizzle<vector, elem_t, 4, 1, 2, 0   > gbr;
            swizzle<vector, elem_t, 4, 1, 2, 3   > gba;
            swizzle<vector, elem_t, 4, 1, 3, 0   > gar;
            swizzle<vector, elem_t, 4, 1, 3, 2   > gab;
            swizzle<vector, elem_t, 4, 2, 0, 1   > brg;
            swizzle<vector, elem_t, 4, 2, 0, 3   > bra;
            swizzle<vector, elem_t, 4, 2, 1, 0   > bgr;
            swizzle<vector, elem_t, 4, 2, 1, 3   > bga;
            swizzle<vector, elem_t, 4, 2, 3, 0   > bar;
            swizzle<vector, elem_t, 4, 2, 3, 1   > bag;
            swizzle<vector, elem_t, 4, 0, 1, 2, 3> rgba;
            swizzle<vector, elem_t, 4, 0, 1, 3, 2> rgab;
            swizzle<vector, elem_t, 4, 0, 2, 1, 3> rbga;
            swizzle<vector, elem_t, 4, 0, 2, 3, 1> rbag;
            swizzle<vector, elem_t, 4, 0, 3, 1, 2> ragb;
            swizzle<vector, elem_t, 4, 0, 3, 2, 1> rabg;
            swizzle<vector, elem_t, 4, 1, 0, 2, 3> grba;
            swizzle<vector, elem_t, 4, 1, 0, 3, 2> grab;
            swizzle<vector, elem_t, 4, 1, 2, 0, 3> gbra;
            swizzle<vector, elem_t, 4, 1, 2, 3, 0> gbar;
            swizzle<vector, elem_t, 4, 1, 3, 0, 2> garb;
            swizzle<vector, elem_t, 4, 1, 3, 2, 0> gabr;
            swizzle<vector, elem_t, 4, 2, 0, 1, 3> brga;
            swizzle<vector, elem_t, 4, 2, 0, 3, 1> brag;
            swizzle<vector, elem_t, 4, 2, 1, 0, 3> bgra;
            swizzle<vector, elem_t, 4, 2, 1, 3, 0> bgar;
            swizzle<vector, elem_t, 4, 2, 3, 0, 1> barg;
            swizzle<vector, elem_t, 4, 2, 3, 1, 0> bagr;
            swizzle<vector, elem_t, 4, 3, 0, 1, 2> argb;
            swizzle<vector, elem_t, 4, 3, 0, 2, 1> arbg;
            swizzle<vector, elem_t, 4, 3, 1, 0, 2> agrb;
            swizzle<vector, elem_t, 4, 3, 1, 2, 0> agbr;
            swizzle<vector, elem_t, 4, 3, 2, 0, 1> abrg;
            swizzle<vector, elem_t, 4, 3, 2, 1, 0> abgr;
        };
    };

    template <typename elem_t>
    struct CD_API vector<elem_t, 4> : private detail::vector_base<elem_t, 4>
    {
        static vector<elem_t, 4> const one;
        static vector<elem_t, 4> const zero;

        using detail::vector_base<elem_t, 4>::x;
        using detail::vector_base<elem_t, 4>::y;
        using detail::vector_base<elem_t, 4>::z;
        using detail::vector_base<elem_t, 4>::w;

        using detail::vector_base<elem_t, 4>::r;
        using detail::vector_base<elem_t, 4>::g;
        using detail::vector_base<elem_t, 4>::b;
        using detail::vector_base<elem_t, 4>::a;

        using detail::vector_base<elem_t, 4>::xy;
        using detail::vector_base<elem_t, 4>::xz;
        using detail::vector_base<elem_t, 4>::xw;
        using detail::vector_base<elem_t, 4>::yx;
        using detail::vector_base<elem_t, 4>::yz;
        using detail::vector_base<elem_t, 4>::yw;
        using detail::vector_base<elem_t, 4>::zx;
        using detail::vector_base<elem_t, 4>::zy;
        using detail::vector_base<elem_t, 4>::zw;
        using detail::vector_base<elem_t, 4>::wx;
        using detail::vector_base<elem_t, 4>::wy;
        using detail::vector_base<elem_t, 4>::wz;
        using detail::vector_base<elem_t, 4>::xyz;
        using detail::vector_base<elem_t, 4>::xyw;
        using detail::vector_base<elem_t, 4>::xzy;
        using detail::vector_base<elem_t, 4>::xzw;
        using detail::vector_base<elem_t, 4>::xwy;
        using detail::vector_base<elem_t, 4>::xwz;
        using detail::vector_base<elem_t, 4>::yxz;
        using detail::vector_base<elem_t, 4>::yxw;
        using detail::vector_base<elem_t, 4>::yzx;
        using detail::vector_base<elem_t, 4>::yzw;
        using detail::vector_base<elem_t, 4>::ywx;
        using detail::vector_base<elem_t, 4>::ywz;
        using detail::vector_base<elem_t, 4>::zxy;
        using detail::vector_base<elem_t, 4>::zxw;
        using detail::vector_base<elem_t, 4>::zyx;
        using detail::vector_base<elem_t, 4>::zyw;
        using detail::vector_base<elem_t, 4>::zwx;
        using detail::vector_base<elem_t, 4>::zwy;
        using detail::vector_base<elem_t, 4>::xyzw;
        using detail::vector_base<elem_t, 4>::xywz;
        using detail::vector_base<elem_t, 4>::xzyw;
        using detail::vector_base<elem_t, 4>::xzwy;
        using detail::vector_base<elem_t, 4>::xwyz;
        using detail::vector_base<elem_t, 4>::xwzy;
        using detail::vector_base<elem_t, 4>::yxzw;
        using detail::vector_base<elem_t, 4>::yxwz;
        using detail::vector_base<elem_t, 4>::yzxw;
        using detail::vector_base<elem_t, 4>::yzwx;
        using detail::vector_base<elem_t, 4>::ywxz;
        using detail::vector_base<elem_t, 4>::ywzx;
        using detail::vector_base<elem_t, 4>::zxyw;
        using detail::vector_base<elem_t, 4>::zxwy;
        using detail::vector_base<elem_t, 4>::zyxw;
        using detail::vector_base<elem_t, 4>::zywx;
        using detail::vector_base<elem_t, 4>::zwxy;
        using detail::vector_base<elem_t, 4>::zwyx;
        using detail::vector_base<elem_t, 4>::wxyz;
        using detail::vector_base<elem_t, 4>::wxzy;
        using detail::vector_base<elem_t, 4>::wyxz;
        using detail::vector_base<elem_t, 4>::wyzx;
        using detail::vector_base<elem_t, 4>::wzxy;
        using detail::vector_base<elem_t, 4>::wzyx;

        using detail::vector_base<elem_t, 4>::rg;
        using detail::vector_base<elem_t, 4>::rb;
        using detail::vector_base<elem_t, 4>::ra;
        using detail::vector_base<elem_t, 4>::gr;
        using detail::vector_base<elem_t, 4>::gb;
        using detail::vector_base<elem_t, 4>::ga;
        using detail::vector_base<elem_t, 4>::br;
        using detail::vector_base<elem_t, 4>::bg;
        using detail::vector_base<elem_t, 4>::ba;
        using detail::vector_base<elem_t, 4>::ar;
        using detail::vector_base<elem_t, 4>::ag;
        using detail::vector_base<elem_t, 4>::ab;
        using detail::vector_base<elem_t, 4>::rgb;
        using detail::vector_base<elem_t, 4>::rga;
        using detail::vector_base<elem_t, 4>::rbg;
        using detail::vector_base<elem_t, 4>::rba;
        using detail::vector_base<elem_t, 4>::rag;
        using detail::vector_base<elem_t, 4>::rab;
        using detail::vector_base<elem_t, 4>::grb;
        using detail::vector_base<elem_t, 4>::gra;
        using detail::vector_base<elem_t, 4>::gbr;
        using detail::vector_base<elem_t, 4>::gba;
        using detail::vector_base<elem_t, 4>::gar;
        using detail::vector_base<elem_t, 4>::gab;
        using detail::vector_base<elem_t, 4>::brg;
        using detail::vector_base<elem_t, 4>::bra;
        using detail::vector_base<elem_t, 4>::bgr;
        using detail::vector_base<elem_t, 4>::bga;
        using detail::vector_base<elem_t, 4>::bar;
        using detail::vector_base<elem_t, 4>::bag;
        using detail::vector_base<elem_t, 4>::rgba;
        using detail::vector_base<elem_t, 4>::rgab;
        using detail::vector_base<elem_t, 4>::rbga;
        using detail::vector_base<elem_t, 4>::rbag;
        using detail::vector_base<elem_t, 4>::ragb;
        using detail::vector_base<elem_t, 4>::rabg;
        using detail::vector_base<elem_t, 4>::grba;
        using detail::vector_base<elem_t, 4>::grab;
        using detail::vector_base<elem_t, 4>::gbra;
        using detail::vector_base<elem_t, 4>::gbar;
        using detail::vector_base<elem_t, 4>::garb;
        using detail::vector_base<elem_t, 4>::gabr;
        using detail::vector_base<elem_t, 4>::brga;
        using detail::vector_base<elem_t, 4>::brag;
        using detail::vector_base<elem_t, 4>::bgra;
        using detail::vector_base<elem_t, 4>::bgar;
        using detail::vector_base<elem_t, 4>::barg;
        using detail::vector_base<elem_t, 4>::bagr;
        using detail::vector_base<elem_t, 4>::argb;
        using detail::vector_base<elem_t, 4>::arbg;
        using detail::vector_base<elem_t, 4>::agrb;
        using detail::vector_base<elem_t, 4>::agbr;
        using detail::vector_base<elem_t, 4>::abrg;
        using detail::vector_base<elem_t, 4>::abgr;

        explicit constexpr vector() noexcept = default;
        explicit constexpr vector(elem_t const& fill_value);                                                                                                // Fill constructor

        template <typename val1_t, typename val2_t, typename val3_t, typename val4_t, typename = enable_if_valid_params<val1_t, val2_t, val3_t, val4_t>>
        explicit constexpr vector(val1_t&& val1, val2_t&& val2, val3_t&& val3, val4_t&& val4);                                                              // Construct with elements

        template <typename _elem_t, std::size_t _size_v, typename = enable_if_valid_vector<_elem_t, _size_v>>
        explicit constexpr vector(vector<_elem_t, _size_v> const& vec);                                                                                     // Conversion construction between vectors with different dimensions and element types

        constexpr vector<elem_t, 4>& operator+=(vector const& vec);
        constexpr vector<elem_t, 4>& operator-=(vector const& vec);
        constexpr vector<elem_t, 4>& operator*=(vector const& vec);                                                                                         // Multiplies two vectors component-wise (Hadamard Product)
        constexpr vector<elem_t, 4>& operator/=(vector const& vec);                                                                                         // Divides self with other vector component-wise

        constexpr vector<elem_t, 4>& operator*=(elem_t const& scale);
        constexpr vector<elem_t, 4>& operator/=(elem_t const& scale);

        constexpr elem_t&       operator[](std::size_t index);
        constexpr elem_t const& operator[](std::size_t index) const;

        constexpr elem_t*       data()       noexcept;
        constexpr elem_t const* data() const noexcept;

        void fill(elem_t const& value);

        static constexpr std::size_t size() noexcept;

    private:

        template <typename ... params_t                > using enable_if_valid_params = std::enable_if_t<std::conjunction_v<std::is_convertible<params_t, elem_t>...>>;
        template <typename _elem_t, std::size_t _size_v> using enable_if_valid_vector = std::enable_if_t<std::is_convertible_v<_elem_t, elem_t> && (_size_v > 3)>;
    };

    template <typename elem_t> vector<elem_t, 4> operator-(vector<elem_t, 4> const& vec);

    template <typename elem_t> bool operator==(vector<elem_t, 4> const& lhs, vector<elem_t, 4> const& rhs);

    template <typename elem_t> cd::ostream& operator<<(cd::ostream& stream, vector<elem_t, 4> const& vec);
    template <typename elem_t> cd::istream& operator>>(cd::istream& stream, vector<elem_t, 4>&       vec);

    template <typename elem_t>
    using vec4 = vector<elem_t, 4>;

    // -------------------------------------------------------------------------
    // Functionals

    template <typename elem_t> constexpr elem_t            dot(vector<elem_t, 4> const& lhs, vector<elem_t, 4> const& rhs);
    template <typename elem_t> constexpr vector<elem_t, 4> min(vector<elem_t, 4> const& lhs, vector<elem_t, 4> const& rhs);
    template <typename elem_t> constexpr vector<elem_t, 4> max(vector<elem_t, 4> const& lhs, vector<elem_t, 4> const& rhs);

}
