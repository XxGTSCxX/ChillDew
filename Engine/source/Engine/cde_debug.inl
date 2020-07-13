/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    cde_debug.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Mimics Unity's Debug class as best as we can within the constraints of C++.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cde_debug.h"
#include "cde_logger.inl"

namespace chilldew::engine
{

    template <typename ... Args>
    inline void debug::log_assert([[maybe_unused]] bool condition, [[maybe_unused]] std::string_view const& text, [[maybe_unused]] Args&& ... args)
    {
#ifdef CD_ENABLE_ASSERT
        cd::string err_message = cd::cstr_to_str(log::format_text(text, std::forward<Args>(args)...));
        assert(condition);
#endif
    }

    template <typename ... Args>
    inline void debug::log(std::string_view const& text, Args&& ... args)
    {
        _logger.log(cd::cstr_to_str(text), std::forward<Args>(args)...);
    }

    template <typename ... Args>
    inline void debug::log_error(std::string_view const& text, Args&& ... args)
    {
        _logger.log_error(cd::cstr_to_str(text), std::forward<Args>(args)...);
    }

    template <typename ... Args>
    inline void debug::log_warning(std::string_view const& text, Args&& ... args)
    {
        _logger.log_warning(cd::cstr_to_str(text), std::forward<Args>(args)...);
    }

}
