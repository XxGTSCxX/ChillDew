/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    cdu_flag.inl
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

#include "cdu_flag.h"

namespace chilldew::utility
{

    template <typename enum_t>
    template <typename ... params_t, typename>
    inline constexpr flag<enum_t>::flag(params_t ... initial_flags) noexcept
    : _value{ static_cast<data_t>((static_cast<data_t>(initial_flags) | ...)) }
    {}

    template <typename enum_t>
    inline flag<enum_t>& flag<enum_t>::operator=(enum_t flag) noexcept
    {
        _value = static_cast<data_t>(flag);
        return *this;
    }

    template <typename enum_t>
    inline flag<enum_t>& flag<enum_t>::on_all()
    {
        _value = all_on;
        return *this;
    }

    template <typename enum_t>
    inline flag<enum_t>& flag<enum_t>::off_all()
    {
        _value = all_off;
        return *this;
    }

    template <typename enum_t>
    template <typename ... params_t, typename>
    inline flag<enum_t>& flag<enum_t>::on(params_t ... flags)
    {
        _value |= (static_cast<data_t>(flags) | ...);
        return *this;
    }

    template <typename enum_t>
    template <typename ... params_t, typename>
    inline flag<enum_t>& flag<enum_t>::off(params_t ... flags)
    {
        _value &= (~static_cast<data_t>(flags) & ...);
        return *this;
    }

    template <typename enum_t>
    template <typename ... params_t, typename>
    inline bool flag<enum_t>::is_on(params_t ... flags) const
    {
        return  _value & (static_cast<data_t>(flags) | ...);
    }

    template <typename enum_t>
    template <typename ... params_t, typename>
    inline bool flag<enum_t>::is_off(params_t ... flags) const
    {
        return ~_value & (static_cast<data_t>(flags) | ...);
    }

    template <typename enum_t>
    template <typename ... params_t, typename>
    inline bool flag<enum_t>::is_all_on(params_t ... flags) const
    {
        data_t combined_flags = (static_cast<data_t>(flags) | ...);
        return !((_value & combined_flags) ^ combined_flags);
    }

    template <typename enum_t>
    template <typename ... params_t, typename>
    inline bool flag<enum_t>::is_all_off(params_t ... flags) const
    {
        data_t combined_flags = (static_cast<data_t>(flags) | ...);
        return !((~_value & combined_flags) ^ combined_flags);
    }

    template <typename enum_t>
    template <typename ... params_t, typename>
    inline bool flag<enum_t>::is_exclusively_on(params_t ... flags) const
    {
        return _value == (static_cast<data_t>(flags) | ...);
    }

    template <typename enum_t>
    template <typename ... params_t, typename>
    inline bool flag<enum_t>::is_exclusively_off(params_t ... flags) const
    {
        return (~_value & all_on) == (static_cast<data_t>(flags) | ...);
    }

    template <typename enum_t>
    inline flag<enum_t>& flag<enum_t>::operator|=(flag<enum_t> flag)
    {
        _value |= flag._value;
        return *this;
    }

    template <typename enum_t>
    inline flag<enum_t>& flag<enum_t>::operator&=(flag<enum_t> flag)
    {
        _value &= flag._value;
        return *this;
    }

    template <typename enum_t>
    inline flag<enum_t>& flag<enum_t>::operator^=(flag<enum_t> flag)
    {
        _value ^= flag._value;
        return *this;
    }

    template <typename enum_t>
    bool operator==(flag<enum_t> const& lhs, flag<enum_t> const& rhs)
    {
        return lhs._value == rhs._value;
    }

    template <typename enum_t>
    bool operator!=(flag<enum_t> const& lhs, flag<enum_t> const& rhs)
    {
        return !(lhs == rhs);
    }

    template <typename enum_t>
    flag<enum_t> operator|(flag<enum_t> const& lhs, flag<enum_t> const& rhs)
    {
        return flag<enum_t>{ lhs } |= rhs;
    }

    template <typename enum_t>
    flag<enum_t> operator&(flag<enum_t> const& lhs, flag<enum_t> const& rhs)
    {
        return flag<enum_t>{ lhs } &= rhs;
    }

    template <typename enum_t>
    flag<enum_t> operator^(flag<enum_t> const& lhs, flag<enum_t> const& rhs)
    {
        return flag<enum_t>{ lhs } ^= rhs;
    }

    template<typename enum_t>
    flag<enum_t> operator~(flag<enum_t> const& flags)
    {
        flag<enum_t> result{ flags };
        result._value = ~result._value & flag<enum_t>::all_on;
        return result;
    }

}
