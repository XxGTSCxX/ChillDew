/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    CD_Vector2D.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Partial vector specialisation for 2D vector implementation.

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

    template <typename elem_t>
    struct CD_API detail::vector_base<elem_t, 2>
    {
        union
        {
            std::array<elem_t, 2> _array;

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
    private:

        template <typename ... params_t                 > using elem_sfinae = std::enable_if_t<std::conjunction_v<std::is_convertible<params_t, elem_t>...>>;
        template <typename other_t, std::size_t other_sz> using vec_sfinae  = std::enable_if_t<std::is_convertible_v<other_t, elem_t> && (other_sz > 1)>;

    public:

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

        constexpr vector() noexcept = default;

        template <typename val1_t, typename val2_t, typename = elem_sfinae<val1_t, val2_t>>
        explicit constexpr vector(val1_t&& value1, val2_t&& value2) noexcept; // Construct with elements

        template <typename val_t, typename = elem_sfinae<val_t>>
        explicit constexpr vector(val_t&& fill_value) noexcept; // Fill constructor

        template <typename other_t, std::size_t other_sz, typename = vec_sfinae<other_t, other_sz>>
        explicit constexpr vector(vector<other_t, other_sz> const& vec) noexcept;

        constexpr vector<elem_t, 2>& operator+=(vector const& vec);
        constexpr vector<elem_t, 2>& operator-=(vector const& vec);
        constexpr vector<elem_t, 2>& operator*=(vector const& vec);             // Multiplies two vectors component-wise (Hadamard Product)
        constexpr vector<elem_t, 2>& operator/=(vector const& vec);             // Divides self by other vector component-wise

        constexpr vector<elem_t, 2>& operator*=(elem_t const& scale);
        constexpr vector<elem_t, 2>& operator/=(elem_t const& scale);           // Division by 0 will set the values to infinity

        constexpr elem_t&       operator[](size_t index);
        constexpr elem_t const& operator[](size_t index) const;

        constexpr elem_t*       data()       noexcept;
        constexpr elem_t const* data() const noexcept;

        constexpr void fill(elem_t const& value);
        static constexpr std::size_t size() noexcept;
    };

    template <typename elem_t> constexpr vector<elem_t, 2> operator-(vector<elem_t, 2> const& vec);

    template <typename elem_t> constexpr bool operator==(vector<elem_t, 2> const& lhs, vector<elem_t, 2> const& rhs) noexcept;

    template <typename elem_t> constexpr CD::ostream& operator<<(CD::ostream& stream, vector<elem_t, 2> const& vec);
    template <typename elem_t> constexpr CD::istream& operator>>(CD::istream& stream, vector<elem_t, 2>&       vec);

    template <typename elem_t> constexpr vector<elem_t, 2> perpendicular(vector<elem_t, 2> const& vec);

    template <typename elem_t> constexpr elem_t            dot         (vector<elem_t, 2> const& lhs , vector<elem_t, 2> const& rhs   );
    template <typename elem_t> constexpr vector<elem_t, 2> max         (vector<elem_t, 2> const& lhs , vector<elem_t, 2> const& rhs   );
    template <typename elem_t> constexpr vector<elem_t, 2> min         (vector<elem_t, 2> const& lhs , vector<elem_t, 2> const& rhs   );
    template <typename elem_t> constexpr degree            angle       (vector<elem_t, 2> const& lhs , vector<elem_t, 2> const& rhs   );
    template <typename elem_t> constexpr degree            signed_angle(vector<elem_t, 2> const& from, vector<elem_t, 2> const& to    );
    template <typename elem_t> constexpr vector<elem_t, 2> reflect     (vector<elem_t, 2> const& vec , vector<elem_t, 2> const& normal);

    template <typename T>
    using vec2 = vector<T, 2>;

}
