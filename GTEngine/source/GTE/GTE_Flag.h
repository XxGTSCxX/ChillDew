/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Flag.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Wrapper around enum classes that can help with using them as flags.

    NOTE: This is a template class and thus is not expected to be exposed to
          client projects as is.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Core.h"
#include "GTE_MetaFunctions.h"
#include <type_traits>

namespace GTE
{

    /**************************************************************************/
    /*!
      \brief
        A Flag template class that can store multiple flag values depending on a
        defined enumaration.

        ENUM : The defined enum that will be used for the flags.

        ------------------------------ HOW TO USE ------------------------------

        1) Define an enum that will be used to define the different flag values.

           E.g. enum class PhysicsFlag // fixes the type of the enum to unsigned
                {
                  Gravity  = 0b001,
                  Friction = 0b010,
                  Bounce   = 0b100,

                  All      = gravity | friction | bounce
                };

           It is important that the values corresponds to a single bit value and
           not a combination of bits. I'd recommend using 0b values since it's
           the binary formatter so you don't have manually calculate the decimal
           to binary conversion.

           NOTE: It is important to have the "All" flag as it allows us to
                 more accurately determine the cases where ONLY specified flags
                 are on.

        2) Create a flag by specifying the enum it uses and the integral type
           that the enum uses.

           E.g. GTE::Flag<PhysicsFlag> physicsFlag;
    */
    /**************************************************************************/
    template <typename ENUM>
    class Flags final
    {
        template <typename ... Params>
        using SFINAE = std::enable_if_t<is_all_same_v<ENUM, Params...>>;

    public:

        constexpr Flags()              noexcept = default;
        constexpr Flags(Flags const&)  noexcept = default;
        Flags& operator=(Flags const&) noexcept = default;

        template <typename ... Params, typename = SFINAE<Params>>
        explicit Flags(Params ... initial_flags) noexcept;

        Flags& OnAll();                                                                                            // set to ALL_ON
        Flags& OffAll();                                                                                           // set to ALL_OFF

        template <typename ... Params, typename = SFINAE<Params>> Flags& On (Params ... flags);                    // Switches all given bits to 1
        template <typename ... Params, typename = SFINAE<Params>> Flags& Off(Params ... flags);                    // Switches all given bits to 0

        template <typename ... Params, typename = SFINAE<Params>> bool IsOn            (Params ... flags) const;   // Checks if at least one of the given 1 bits is 1
        template <typename ... Params, typename = SFINAE<Params>> bool IsOff           (Params ... flags) const;   // Checks if at least one of the given 1 bits is 0
        template <typename ... Params, typename = SFINAE<Params>> bool IsAllOn         (Params ... flags) const;   // Checks if all of the given 1 bits is 1
        template <typename ... Params, typename = SFINAE<Params>> bool IsAllOff        (Params ... flags) const;   // Checks if all of the given 1 bits is 0
        template <typename ... Params, typename = SFINAE<Params>> bool IsExclusivelyOn (Params ... flags) const;   // Checks if ONLY the given flags are on
        template <typename ... Params, typename = SFINAE<Params>> bool IsExclusivelyOff(Params ... flags) const;   // Checks if ONLY the given flags are off

        Flags& operator|=(Flags flag);
        Flags& operator&=(Flags flag);
        Flags& operator^=(Flags flag);

    private:

        static_assert(std::is_enum<ENUM>::value, "class Flag: Template requires an enum type");                    // Safety parameter check

        using TYPE = typename std::underlying_type<ENUM>::type;

        static constexpr TYPE ALL_OFF = static_cast<TYPE>(0        );
        static constexpr TYPE ALL_ON  = static_cast<TYPE>(ENUM::All);                                              // If this fails, you've forgot to define an All field in your enum

        TYPE _value = ALL_OFF;

        template <typename ENUM> friend bool        operator==(Flags<ENUM> const& lhs, Flags<ENUM> const& rhs);
        template <typename ENUM> friend bool        operator!=(Flags<ENUM> const& lhs, Flags<ENUM> const& rhs);
        template <typename ENUM> friend Flags<ENUM> operator~ (Flags<ENUM> const& flags                      );
    };

    template <typename ENUM> bool        operator==(Flags<ENUM> const& lhs, Flags<ENUM> const& rhs);
    template <typename ENUM> bool        operator!=(Flags<ENUM> const& lhs, Flags<ENUM> const& rhs);
    template <typename ENUM> Flags<ENUM> operator| (Flags<ENUM> const& lhs, Flags<ENUM> const& rhs);
    template <typename ENUM> Flags<ENUM> operator& (Flags<ENUM> const& lhs, Flags<ENUM> const& rhs);
    template <typename ENUM> Flags<ENUM> operator^ (Flags<ENUM> const& lhs, Flags<ENUM> const& rhs);
    template <typename ENUM> Flags<ENUM> operator~ (Flags<ENUM> const& flag                       );

}
