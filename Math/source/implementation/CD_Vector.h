/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    CD_Vector.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Base class for math vector class.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Core.h"
#include "CD_VectorBase.h"
#include <array>   // std::array
#include <cstddef> // std::size_t

namespace chilldew
{

    template <typename elem_t, std::size_t size_v>
    struct CD_API vector : private detail::vector_base<elem_t, size_v>
    {
    protected:

        template <typename ... params_t            > using elem_sfinae        = std::enable_if_t< std::conjunction_v<std::is_convertible<params_t, elem_t>...>>;
        template <typename ... params_t            > using multi_param_sfinae = std::enable_if_t<(std::conjunction_v<std::is_convertible<params_t, elem_t>...> && sizeof...(params_t) == size_v)>;
        template <typename other_t, size_t other_sz> using vec_sfinae         = std::enable_if_t<std::is_convertible_v<other_t, elem_t> && (other_sz >= size_v)>;

    public:

        constexpr vector() noexcept = default;

        template <typename ... params_t, typename = multi_param_sfinae<params_t...>>
        constexpr vector(params_t&& ... args);                                  // Construct with elements

        template <typename val_t, typename = elem_sfinae<val_t>>
        explicit constexpr vector(val_t&& fill_value);                          // Fill constructor

        template <typename other_t, std::size_t other_sz, typename = vec_sfinae<other_t, other_sz>>
        explicit constexpr vector(vector<other_t, other_sz> const& vec);        // Conversion construction between vectors with different dimensions and element types

        constexpr vector& operator+=(vector const& vec);
        constexpr vector& operator-=(vector const& vec);
        constexpr vector& operator*=(vector const& vec);                        // This is using Hadamard Product
        constexpr vector& operator/=(vector const& vec);

        constexpr vector& operator*=(elem_t const& scale);
        constexpr vector& operator/=(elem_t const& scale);                      // Division by 0 will set the values to infinity

        constexpr elem_t&       operator[](std::size_t index);
        constexpr elem_t const& operator[](std::size_t index) const;

        constexpr elem_t*       data()       noexcept;
        constexpr elem_t const* data() const noexcept;

        constexpr void fill(elem_t const& value);
        static constexpr std::size_t size() noexcept;
    };

    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> operator+(vector<elem_t, size_v> const& lhs  , vector<elem_t, size_v> const& rhs  );
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> operator-(vector<elem_t, size_v> const& lhs  , vector<elem_t, size_v> const& rhs  );
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> operator*(vector<elem_t, size_v> const& lhs  , vector<elem_t, size_v> const& rhs  ); // This is using Hadamard Product
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> operator*(vector<elem_t, size_v> const& vec  , elem_t                 const& scale);
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> operator*(elem_t                 const& scale, vector<elem_t, size_v> const& vec  );
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> operator/(vector<elem_t, size_v> const& vec  , elem_t                 const& scale); // Division by 0 will set the values to infinity
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> operator-(vector<elem_t, size_v> const& vec                                       );

    template <typename elem_t, std::size_t size_v> constexpr bool operator==(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs) noexcept;
    template <typename elem_t, std::size_t size_v> constexpr bool operator!=(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs) noexcept;

    template <typename elem_t, std::size_t size_v> constexpr CD::ostream& operator<<(CD::ostream& stream, vector<elem_t, size_v> const& vec);
    template <typename elem_t, std::size_t size_v> constexpr CD::istream& operator>>(CD::istream& stream, vector<elem_t, size_v>&       vec);

    template <typename elem_t, std::size_t size_v> constexpr elem_t                 dot(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs);
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> max(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs);
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> min(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs);

    template <typename elem_t, std::size_t size_v> constexpr elem_t                  mag_sq    (vector<elem_t, size_v> const& vec);
    template <typename elem_t, std::size_t size_v> constexpr elem_t                  mag       (vector<elem_t, size_v> const& vec);
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v>  normalise (vector<elem_t, size_v> const& vec);
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v>& normalised(vector<elem_t, size_v>&       vec);

    template <typename elem_t, std::size_t size_v> constexpr elem_t                 distance (vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs          );
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> project  (vector<elem_t, size_v> const& vec, vector<elem_t, size_v> const& normal       );
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> clamp_mag(vector<elem_t, size_v> const& vec, elem_t                 const& max_magnitude);

    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> lerp_unclamped(vector<elem_t, size_v> const& from   , vector<elem_t, size_v> const& to    , elem_t const& alpha             );
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> lerp          (vector<elem_t, size_v> const& from   , vector<elem_t, size_v> const& to    , elem_t const& alpha             );
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> move_towards  (vector<elem_t, size_v> const& current, vector<elem_t, size_v> const& target, elem_t const& max_distance_delta);

    template <typename elem_t>
    struct vector<elem_t, 0>; // There shouldn't be a 0 dimension vector

}
