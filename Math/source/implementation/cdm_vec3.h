/******************************************************************************/
/*!
  \project Chilldew-Math
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

#include "cd_core.h"
#include "cdm_defines.h"
#include "cdm_vector.h"
#include "cdm_swizzle.inl"

namespace chilldew::math
{

    template <typename elem_t>
    struct CD_API detail::vector_base<elem_t, 3>
    {
        union
        {
            elem_t _data[3];

            struct
            {
                elem_t x;
                elem_t y;
                elem_t z;
            };

            struct
            {
                elem_t r;
                elem_t g;
                elem_t b;
            };

            swizzle<vector, elem_t, 3, 0, 1   > xy;
            swizzle<vector, elem_t, 3, 0, 2   > xz;
            swizzle<vector, elem_t, 3, 1, 0   > yx;
            swizzle<vector, elem_t, 3, 1, 2   > yz;
            swizzle<vector, elem_t, 3, 2, 0   > zx;
            swizzle<vector, elem_t, 3, 2, 1   > zy;
            swizzle<vector, elem_t, 3, 0, 1, 2> xyz;
            swizzle<vector, elem_t, 3, 0, 2, 1> xzy;
            swizzle<vector, elem_t, 3, 1, 0, 2> yxz;
            swizzle<vector, elem_t, 3, 1, 2, 0> yzx;
            swizzle<vector, elem_t, 3, 2, 0, 1> zxy;
            swizzle<vector, elem_t, 3, 2, 1, 0> zyx;

            swizzle<vector, elem_t, 3, 0, 1   > rg;
            swizzle<vector, elem_t, 3, 0, 2   > rb;
            swizzle<vector, elem_t, 3, 1, 0   > gr;
            swizzle<vector, elem_t, 3, 1, 2   > gb;
            swizzle<vector, elem_t, 3, 2, 0   > br;
            swizzle<vector, elem_t, 3, 2, 1   > bg;
            swizzle<vector, elem_t, 3, 0, 1, 2> rgb;
            swizzle<vector, elem_t, 3, 0, 2, 1> rbg;
            swizzle<vector, elem_t, 3, 1, 0, 2> grb;
            swizzle<vector, elem_t, 3, 1, 2, 0> gbr;
            swizzle<vector, elem_t, 3, 2, 0, 1> brg;
            swizzle<vector, elem_t, 3, 2, 1, 0> bgr;
        };
    };

    template <typename elem_t>
    struct CD_API vector<elem_t, 3> : private detail::vector_base<elem_t, 3>
    {
        static vector<elem_t, 3> const up;
        static vector<elem_t, 3> const down;
        static vector<elem_t, 3> const left;
        static vector<elem_t, 3> const right;
        static vector<elem_t, 3> const forward;
        static vector<elem_t, 3> const back;
        static vector<elem_t, 3> const one;
        static vector<elem_t, 3> const zero;

        using detail::vector_base<elem_t, 3>::x;
        using detail::vector_base<elem_t, 3>::y;
        using detail::vector_base<elem_t, 3>::z;

        using detail::vector_base<elem_t, 3>::r;
        using detail::vector_base<elem_t, 3>::g;
        using detail::vector_base<elem_t, 3>::b;

        using detail::vector_base<elem_t, 3>::xy;
        using detail::vector_base<elem_t, 3>::xz;
        using detail::vector_base<elem_t, 3>::yx;
        using detail::vector_base<elem_t, 3>::yz;
        using detail::vector_base<elem_t, 3>::zx;
        using detail::vector_base<elem_t, 3>::zy;
        using detail::vector_base<elem_t, 3>::xyz;
        using detail::vector_base<elem_t, 3>::xzy;
        using detail::vector_base<elem_t, 3>::yxz;
        using detail::vector_base<elem_t, 3>::yzx;
        using detail::vector_base<elem_t, 3>::zxy;
        using detail::vector_base<elem_t, 3>::zyx;

        using detail::vector_base<elem_t, 3>::rg;
        using detail::vector_base<elem_t, 3>::rb;
        using detail::vector_base<elem_t, 3>::gr;
        using detail::vector_base<elem_t, 3>::gb;
        using detail::vector_base<elem_t, 3>::br;
        using detail::vector_base<elem_t, 3>::bg;
        using detail::vector_base<elem_t, 3>::rgb;
        using detail::vector_base<elem_t, 3>::rbg;
        using detail::vector_base<elem_t, 3>::grb;
        using detail::vector_base<elem_t, 3>::gbr;
        using detail::vector_base<elem_t, 3>::brg;
        using detail::vector_base<elem_t, 3>::bgr;

        explicit constexpr vector() noexcept = default;
        explicit constexpr vector(elem_t const& fill_value);                                                                    // Fill constructor

        template <typename val1_t, typename val2_t, typename val3_t, typename = enable_if_valid_params<val1_t, val2_t, val3_t>>
        explicit constexpr vector(val1_t&& val1, val2_t&& val2, val3_t&& val3);                                                 // Construct with elements

        template <typename _elem_t, std::size_t _size_v, typename = enable_if_valid_vector<_elem_t, _size_v>>
        explicit constexpr vector(vector<_elem_t, _size_v> const& vector);                                                      // Conversion construction between vectors with different dimensions and element types

        constexpr vector<elem_t, 3>& operator+=(vector const& vector);
        constexpr vector<elem_t, 3>& operator-=(vector const& vector);
        constexpr vector<elem_t, 3>& operator*=(vector const& vector);                                                          // Multiplies two vectors component-wise (Hadamard Product)
        constexpr vector<elem_t, 3>& operator/=(vector const& vector);                                                          // Divides self with other vector component-wise

        constexpr vector<elem_t, 3>& operator*=(elem_t const& scale);
        constexpr vector<elem_t, 3>& operator/=(elem_t const& scale);

        constexpr elem_t&       operator[](std::size_t index);
        constexpr elem_t const& operator[](std::size_t index) const;

        constexpr elem_t*       data()        noexcept;
        constexpr elem_t const* data() const  noexcept;

        void fill(elem_t const& value);

        static constexpr std::size_t size() noexcept;

    private:

        template <typename ... params_t                 > using enable_if_valid_params = std::enable_if_t<std::conjunction_v<std::is_convertible<params_t, elem_t>...>>;
        template <typename other_t, std::size_t other_sz> using enable_if_valid_vector = std::enable_if_t<std::is_convertible_v<other_t, elem_t> && (other_sz > 2)>;
    };

    template <typename elem_t> constexpr vector<elem_t, 3> operator-(vector<elem_t, 3> const& vec);

    template <typename elem_t> constexpr bool operator==(vector<elem_t, 3> const& lhs, vector<elem_t, 3> const& rhs) noexcept;

    template <typename elem_t> constexpr cd::ostream& operator<<(cd::ostream& stream, vector<elem_t, 3> const& vec);
    template <typename elem_t> constexpr cd::istream& operator>>(cd::istream& stream, vector<elem_t, 3>&       vec);

    template <typename elem_t>
    using vec3 = vector<elem_t, 3>;

    // -------------------------------------------------------------------------
    // Functionals

    template <typename elem_t> constexpr elem_t            dot(vector<elem_t, 3> const& lhs, vector<elem_t, 3> const& rhs);
    template <typename elem_t> constexpr vector<elem_t, 3> min(vector<elem_t, 3> const& lhs, vector<elem_t, 3> const& rhs);
    template <typename elem_t> constexpr vector<elem_t, 3> max(vector<elem_t, 3> const& lhs, vector<elem_t, 3> const& rhs);

}
