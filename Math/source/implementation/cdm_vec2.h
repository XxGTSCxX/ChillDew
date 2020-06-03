/******************************************************************************/
/*!
  \project Chilldew-Math
  \file    cdm_vec2.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Partial vector specialisation for 2D vector implementation.

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
    struct CD_API detail::vector_base<elem_t, 2>
    {
        union
        {
            elem_t _data[2];

            struct
            {
                elem_t x;
                elem_t y;
            };

            swizzle<vector, elem_t, 2, 0, 1> xy;
            swizzle<vector, elem_t, 2, 1, 0> yx;
        };
    };

    template <typename elem_t>
    struct CD_API vector<elem_t, 2> : private detail::vector_base<elem_t, 2>
    {
        static vector<elem_t, 2> const up;
        static vector<elem_t, 2> const down;
        static vector<elem_t, 2> const left;
        static vector<elem_t, 2> const right;
        static vector<elem_t, 2> const one;
        static vector<elem_t, 2> const zero;

        using detail::vector_base<elem_t, 2>::x;
        using detail::vector_base<elem_t, 2>::y;
        using detail::vector_base<elem_t, 2>::xy;
        using detail::vector_base<elem_t, 2>::yx;

        explicit constexpr vector() noexcept = default;
        explicit constexpr vector(elem_t const& fill_value);                                                    // Fill constructor

        template <typename val1_t, typename val2_t, typename = enable_if_valid_params<val1_t, val2_t>>
        explicit constexpr vector(val1_t&& val1, val2_t&& val2);                                                // Construct with elements

        template <typename _elem_t, std::size_t _size_v, typename = enable_if_valid_vector<_elem_t, _size_v>>
        explicit constexpr vector(vector<_elem_t, _size_v> const& vec);                                        // Conversion from other vectors

        constexpr vector<elem_t, 2>& operator+=(vector const& vec);
        constexpr vector<elem_t, 2>& operator-=(vector const& vec);
        constexpr vector<elem_t, 2>& operator*=(vector const& vec);                                             // Multiplies two vectors component-wise (Hadamard Product)
        constexpr vector<elem_t, 2>& operator/=(vector const& vec);                                             // Divides self by other vector component-wise

        constexpr vector<elem_t, 2>& operator*=(elem_t const& scale);
        constexpr vector<elem_t, 2>& operator/=(elem_t const& scale);

        constexpr elem_t&       operator[](std::size_t index);
        constexpr elem_t const& operator[](std::size_t index) const;

        constexpr elem_t*       data()       noexcept;
        constexpr elem_t const* data() const noexcept;

        void fill(elem_t const& value);

        static constexpr std::size_t size() noexcept;

    private:

        template <typename ... params_t                 > using enable_if_valid_params = std::enable_if_t<std::conjunction_v<std::is_convertible<params_t, elem_t>...>>;
        template <typename other_t, std::size_t other_sz> using enable_if_valid_vector = std::enable_if_t<std::is_convertible_v<other_t, elem_t> && (other_sz > 1)>;
    };

    template <typename elem_t> constexpr vector<elem_t, 2> operator-(vector<elem_t, 2> const& vec);

    template <typename elem_t> constexpr bool operator==(vector<elem_t, 2> const& lhs, vector<elem_t, 2> const& rhs) noexcept;

    template <typename elem_t> constexpr cd::ostream& operator<<(cd::ostream& stream, vector<elem_t, 2> const& vec);
    template <typename elem_t> constexpr cd::istream& operator>>(cd::istream& stream, vector<elem_t, 2>&       vec);

    template <typename elem_t>
    using vec2 = vector<elem_t, 2>;

    // -------------------------------------------------------------------------
    // Functionals

    template <typename elem_t> constexpr elem_t            dot(vector<elem_t, 2> const& lhs, vector<elem_t, 2> const& rhs);
    template <typename elem_t> constexpr vector<elem_t, 2> min(vector<elem_t, 2> const& lhs, vector<elem_t, 2> const& rhs);
    template <typename elem_t> constexpr vector<elem_t, 2> max(vector<elem_t, 2> const& lhs, vector<elem_t, 2> const& rhs);

}
