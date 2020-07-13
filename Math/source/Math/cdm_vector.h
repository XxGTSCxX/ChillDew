/******************************************************************************/
/*!
  \project Chilldew-Math
  \file    CD_Vector.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Base class for math vector class.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cd_core.h"
#include <array>   // std::array
#include <cstddef> // std::size_t

namespace chilldew::math
{

    namespace detail
    {
        template <typename elem_t, std::size_t size_v>
        struct CD_API vector_base
        {
            elem_t _data[size_v];
        };
    }

    template <typename elem_t, std::size_t size_v>
    struct CD_API vector : private detail::vector_base<elem_t, size_v>
    {
        explicit constexpr vector() noexcept = default;
        explicit constexpr vector(elem_t const& fill_value);                                                    // Fill constructor

        template <typename ... params_t, typename = enable_if_valid_params<params_t...>>
        explicit constexpr vector(params_t&& ... args);                                                         // Construct with elements

        template <typename _elem_t, std::size_t _size_v, typename = enable_if_valid_vector<_elem_t, _size_v>>
        explicit constexpr vector(vector<_elem_t, _size_v> const& vec);                                         // Conversion construction between vectors with different dimensions and element types

        constexpr vector& operator+=(vector const& vec);
        constexpr vector& operator-=(vector const& vec);
        constexpr vector& operator*=(vector const& vec);                                                        // Multiplies two vectors component-wise (Hadamard Product)
        constexpr vector& operator/=(vector const& vec);                                                        // Divides self with other vector component-wise

        constexpr vector& operator*=(elem_t const& scale);
        constexpr vector& operator/=(elem_t const& scale);

        constexpr elem_t&       operator[](std::size_t index);
        constexpr elem_t const& operator[](std::size_t index) const;

        constexpr elem_t*       data()       noexcept;
        constexpr elem_t const* data() const noexcept;

        void fill(elem_t const& value);

        static constexpr std::size_t size() noexcept;

    private:

        template <typename ... params_t                > using enable_if_valid_params = std::enable_if_t<std::conjunction_v<std::is_convertible<params_t, elem_t>...> && (sizeof...(params_t) == size_v)>;
        template <typename _elem_t, std::size_t _size_v> using enable_if_valid_vector = std::enable_if_t<std::is_convertible_v<_elem_t, elem_t>                       && (_size_v             >= size_v)>;
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

    template <typename elem_t, std::size_t size_v> constexpr cd::ostream& operator<<(cd::ostream& stream, vector<elem_t, size_v> const& vec);
    template <typename elem_t, std::size_t size_v> constexpr cd::istream& operator>>(cd::istream& stream, vector<elem_t, size_v>&       vec);

    template <typename elem_t>
    struct vector<elem_t, 0>; // There shouldn't be a 0 dimension vector

    // -------------------------------------------------------------------------
    // Functionals

    template <typename elem_t, std::size_t size_v> constexpr elem_t                 dot          (vector<elem_t, size_v> const& lhs    , vector<elem_t, size_v> const& rhs   );
    template <typename elem_t, std::size_t size_v> constexpr elem_t                 length_square(vector<elem_t, size_v> const& vec                                          );
    template <typename elem_t, std::size_t size_v> constexpr elem_t                 length       (vector<elem_t, size_v> const& vec                                          );
    template <typename elem_t, std::size_t size_v> constexpr elem_t                 distance     (vector<elem_t, size_v> const& lhs    , vector<elem_t, size_v> const& rhs   );
    template <typename elem_t, std::size_t size_v> constexpr radian                 angle        (vector<elem_t, size_v> const& from   , vector<elem_t, size_v> const& to    ); // Expects both vectors to be normalised before it's passed in
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> proj         (vector<elem_t, size_v> const& vec    , vector<elem_t, size_v> const& normal); // Normal is expected to be normalised already
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> orthogonalise(vector<elem_t, size_v> const& tangent, vector<elem_t, size_v> const& normal); // Makes tangent orthogonal to the normal
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> reflect      (vector<elem_t, size_v> const& vec    , vector<elem_t, size_v> const& normal); // Normal is expected to be normalised already
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> faceforward  (vector<elem_t, size_v> const& vec    , vector<elem_t, size_v> const& normal);

    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> refract(vector<elem_t, size_v> const& incidence, vector<elem_t, size_v> const& normal, real eta);

    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v>  normalise (vector<elem_t, size_v> const& vec);
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v>& normalised(vector<elem_t, size_v>&       vec);

    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> min(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs);
    template <typename elem_t, std::size_t size_v> constexpr vector<elem_t, size_v> max(vector<elem_t, size_v> const& lhs, vector<elem_t, size_v> const& rhs);

}
