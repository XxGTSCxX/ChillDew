/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    CD_Flags.inl
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

#include "CD_Flags.h"

namespace chilldew
{

    template <typename ENUM>
    template <typename ... Params, typename>
    inline Flags<ENUM>::Flags(Params ... initial_flags) noexcept
    : _value{ (static_cast<TYPE>(initial_flags) | ...) }
    {}

    template<typename ENUM>
    template<typename ...Params, typename>
    inline Flags<ENUM>& Flags<ENUM>::operator=(ENUM flag) noexcept
    {
        _value = flag;
        return *this;
    }

    template <typename ENUM>
    inline Flags<ENUM>& Flags<ENUM>::OnAll()
    {
        _value = ALL_ON;
        return *this;
    }

    template <typename ENUM>
    inline Flags<ENUM>& Flags<ENUM>::OffAll()
    {
        _value = ALL_OFF;
        return *this;
    }

    template <typename ENUM>
    template <typename ... Params, typename>
    inline Flags<ENUM>& Flags<ENUM>::On(Params ... flags)
    {
        _value |= (static_cast<TYPE>(flags) | ...);
        return *this;
    }

    template <typename ENUM>
    template <typename ... Params, typename>
    inline Flags<ENUM>& Flags<ENUM>::Off(Params ... flags)
    {
        _value &= (~static_cast<TYPE>(flags) & ...);
        return *this;
    }

    template <typename ENUM>
    template <typename ... Params, typename>
    inline bool Flags<ENUM>::IsOn(Params ... flags) const
    {
        return  _value & (static_cast<TYPE>(flags) | ...);
    }

    template <typename ENUM>
    template <typename ... Params, typename>
    inline bool Flags<ENUM>::IsOff(Params ... flags) const
    {
        return ~_value & (static_cast<TYPE>(flags) | ...);
    }

    template <typename ENUM>
    template <typename ... Params, typename>
    inline bool Flags<ENUM>::IsAllOn(Params ... flags) const
    {
        TYPE combined_flags = (static_cast<TYPE>(flags) | ...);
        return !((_value & combined_flags) ^ combined_flags);
    }

    template <typename ENUM>
    template <typename ... Params, typename>
    inline bool Flags<ENUM>::IsAllOff(Params ... flags) const
    {
        TYPE combined_flags = (static_cast<TYPE>(flags) | ...);
        return !((~_value & combined_flags) ^ combined_flags);
    }

    template <typename ENUM>
    template <typename ... Params, typename>
    inline bool Flags<ENUM>::IsExclusivelyOn(Params ... flags) const
    {
        return _value == (static_cast<TYPE>(flags) | ...);
    }

    template <typename ENUM>
    template <typename ... Params, typename>
    inline bool Flags<ENUM>::IsExclusivelyOff(Params ... flags) const
    {
        return (~_value & ALL_ON) == (static_cast<TYPE>(flags) | ...);
    }

    template <typename ENUM>
    inline Flags<ENUM>& Flags<ENUM>::operator|=(Flags<ENUM> flag)
    {
        _value |= flag._value;
        return *this;
    }

    template <typename ENUM>
    inline Flags<ENUM>& Flags<ENUM>::operator&=(Flags<ENUM> flag)
    {
        _value &= flag._value;
        return *this;
    }

    template <typename ENUM>
    inline Flags<ENUM>& Flags<ENUM>::operator^=(Flags<ENUM> flag)
    {
        _value ^= flag._value;
        return *this;
    }

    template <typename ENUM>
    bool operator==(Flags<ENUM> const& lhs, Flags<ENUM> const& rhs)
    {
        return lhs._value == rhs._value;
    }

    template <typename ENUM>
    bool operator!=(Flags<ENUM> const& lhs, Flags<ENUM> const& rhs)
    {
        return !(lhs == rhs);
    }

    template <typename ENUM>
    Flags<ENUM> operator|(Flags<ENUM> const& lhs, Flags<ENUM> const& rhs)
    {
        return Flags<ENUM>{ lhs } |= rhs;
    }

    template <typename ENUM>
    Flags<ENUM> operator&(Flags<ENUM> const& lhs, Flags<ENUM> const& rhs)
    {
        return Flags<ENUM>{ lhs } &= rhs;
    }

    template <typename ENUM>
    Flags<ENUM> operator^(Flags<ENUM> const& lhs, Flags<ENUM> const& rhs)
    {
        return Flags<ENUM>{ lhs } ^= rhs;
    }

    template<typename ENUM>
    Flags<ENUM> operator~(Flags<ENUM> const& flag)
    {
        Flags<ENUM> result{ *this };
        result._value = ~result._value & Flags<ENUM>::ALL_ON;
        return result;
    }

}
