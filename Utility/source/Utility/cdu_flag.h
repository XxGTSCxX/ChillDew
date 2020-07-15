/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    cdu_flag.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Wrapper around enum classes that can help with using them as flag.

    NOTE: This is a template class and thus is not expected to be exposed to
          client projects as is.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cdu_core.h"
#include "cdu_metafunctions.h"
#include <type_traits>

namespace chilldew::utility
{

    /**************************************************************************/
    /*!
      \brief
        A Flag template class that can store multiple flag values depending on a
        defined enumaration.

        enum_t : The defined enum that will be used for the flag.

        ------------------------------ HOW TO USE ------------------------------

        1) Define an enum that will be used to define the different flag values.

           E.g. enum class PhysicsFlag // fixes the type of the enum to unsigned
                {
                  gravity  = 0b001,
                  friction = 0b010,
                  bounce   = 0b100,

                  all      = gravity | friction | bounce
                };

           It is important that the values corresponds to a single bit value and
           not a combination of bits. I'd recommend using 0b values since it's
           the binary formatter so you don't have manually calculate the decimal
           to binary conversion.

           NOTE: It is important to have the "all" flag as it allows us to
                 more accurately determine the cases where ONLY specified flag
                 are on.

        2) Create a flag by specifying the enum it uses and the integral type
           that the enum uses.

           E.g. cd::Flag<PhysicsFlag> physicsFlag;
    */
    /**************************************************************************/
    template <typename enum_t>
    struct flag final
    {
    private:

        template <typename ... params_t>
        using enable_if_valid_params = std::enable_if_t<is_all_same_v<enum_t, params_t...>>;

    public:

        constexpr flag()             noexcept = default;
        constexpr flag(flag const&)  noexcept = default;
        flag& operator=(flag const&) noexcept = default;

        template <typename ... params_t, typename = enable_if_valid_params<params_t...>>
        explicit constexpr flag(params_t ... initial_flags) noexcept;

        flag& operator=(enum_t flag) noexcept;

        flag&  on_all();                                                                                                            // set to all_on
        flag& off_all();                                                                                                            // set to all_off

        template <typename ... params_t, typename = enable_if_valid_params<params_t...>> flag& on (params_t ... flags);                   // Switches all given bits to 1
        template <typename ... params_t, typename = enable_if_valid_params<params_t...>> flag& off(params_t ... flags);                   // Switches all given bits to 0

        template <typename ... params_t, typename = enable_if_valid_params<params_t...>> bool is_on             (params_t ... flags) const; // Checks if at least one of the given 1 bits is 1
        template <typename ... params_t, typename = enable_if_valid_params<params_t...>> bool is_off            (params_t ... flags) const; // Checks if at least one of the given 1 bits is 0
        template <typename ... params_t, typename = enable_if_valid_params<params_t...>> bool is_all_on         (params_t ... flags) const; // Checks if all of the given 1 bits is 1
        template <typename ... params_t, typename = enable_if_valid_params<params_t...>> bool is_all_off        (params_t ... flags) const; // Checks if all of the given 1 bits is 0
        template <typename ... params_t, typename = enable_if_valid_params<params_t...>> bool is_exclusively_on (params_t ... flags) const; // Checks if ONLY the given flag are on
        template <typename ... params_t, typename = enable_if_valid_params<params_t...>> bool is_exclusively_off(params_t ... flags) const; // Checks if ONLY the given flag are off

        flag& operator|=(flag flag);
        flag& operator&=(flag flag);
        flag& operator^=(flag flag);

    private:

        static_assert(std::is_enum<enum_t>::value, "class Flag: Template requires an enum type"); // Safety parameter check

        using data_t = typename std::underlying_type<enum_t>::type;

        static constexpr data_t all_off = static_cast<data_t>(0          );
        static constexpr data_t all_on  = static_cast<data_t>(enum_t::all);                       // If this fails, you've forgot to define an all field in your enum

        data_t _value = all_off;

        template <typename enum_t> friend bool         operator==(flag<enum_t> const& lhs, flag<enum_t> const& rhs);
        template <typename enum_t> friend bool         operator!=(flag<enum_t> const& lhs, flag<enum_t> const& rhs);
        template <typename enum_t> friend flag<enum_t> operator~ (flag<enum_t> const& flags                       );
    };

    template <typename enum_t> bool         operator==(flag<enum_t> const& lhs, flag<enum_t> const& rhs);
    template <typename enum_t> bool         operator!=(flag<enum_t> const& lhs, flag<enum_t> const& rhs);
    template <typename enum_t> flag<enum_t> operator| (flag<enum_t> const& lhs, flag<enum_t> const& rhs);
    template <typename enum_t> flag<enum_t> operator& (flag<enum_t> const& lhs, flag<enum_t> const& rhs);
    template <typename enum_t> flag<enum_t> operator^ (flag<enum_t> const& lhs, flag<enum_t> const& rhs);
    template <typename enum_t> flag<enum_t> operator~ (flag<enum_t> const& flag                        );

}
